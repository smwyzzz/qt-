#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QListWidgetItem>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textEdit = ui->textEdit;
    setWindowTitle("无标题 - 文本编辑器");

    // 信号绑定（保持原样）
    connect(ui->newtxt, &QAction::triggered, this, &MainWindow::newfile);
    connect(ui->open,   &QAction::triggered, this, &MainWindow::open);
    connect(ui->save,   &QAction::triggered, this, &MainWindow::save);
    connect(ui->saveas, &QAction::triggered, this, &MainWindow::saveas);
    connect(ui->exit,   &QAction::triggered, this, &MainWindow::exit);
    connect(ui->listWidget_1, &QListWidget::itemClicked, this, &MainWindow::content);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::change);
    connect(ui->status, &QAction::triggered, this, &MainWindow::status);
    connect(ui->content, &QAction::triggered, this, &MainWindow::content);

    initStatusBar();
    restoreFileList();
}

MainWindow::~MainWindow()
{
    saveFileList();
    if (textEdit->document()->isModified()) save();
    delete ui;
}

// -------------------- 基本功能 --------------------

void MainWindow::newfile()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "新建文件",
        QDir::homePath(),
        "文本文件 (*.txt)"
        );

    if (fileName.isEmpty())
        return;

    // 自动补 .txt 后缀
    if (!fileName.endsWith(".txt", Qt::CaseInsensitive))
        fileName += ".txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法创建文件: " + fileName);
        return;
    }
    file.close();

    // 清空编辑区并更新当前文件路径
    ui->textEdit->clear();
    currentFile = fileName;

    // 避免重复添加同名文件
    QString shortName = QFileInfo(fileName).fileName();
    bool exists = false;
    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        if (ui->listWidget_1->item(i)->text() == shortName) {
            exists = true;
            break;
        }
    }
    if (!exists)
        ui->listWidget_1->addItem(shortName);

    // 把完整路径存到 item 的 data 中，方便打开时用
    QListWidgetItem *item = ui->listWidget_1->item(ui->listWidget_1->count() - 1);
    item->setData(Qt::UserRole, fileName);

    // 更新标题
    setWindowTitle(shortName + " - 文本编辑器");
}



void MainWindow::open()
{
    QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "", "文本文件 (*.txt)");
    if (filePath.isEmpty()) return;

    save();

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }
    QTextStream in(&file);
    textEdit->setPlainText(in.readAll());
    file.close();

    currentFile = filePath;
    QString name = QFileInfo(filePath).fileName();

    bool exists = false;
    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        if (ui->listWidget_1->item(i)->data(Qt::UserRole).toString() == filePath) {
            exists = true;
            ui->listWidget_1->setCurrentRow(i);
            break;
        }
    }
    if (!exists) {
        QListWidgetItem *item = new QListWidgetItem(name);
        item->setData(Qt::UserRole, filePath);
        ui->listWidget_1->addItem(item);
        ui->listWidget_1->setCurrentItem(item);
    }

    setWindowTitle(name + " - 文本编辑器");
    textEdit->document()->setModified(false);
}

void MainWindow::save()
{
    if (currentFile.isEmpty()) {
        saveas();
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法保存文件");
        return;
    }

    QTextStream out(&file);
    out << textEdit->toPlainText();
    file.close();
    textEdit->document()->setModified(false);

    QString title = QFileInfo(currentFile).fileName();
    setWindowTitle(title + " - 文本编辑器");

    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        if (ui->listWidget_1->item(i)->data(Qt::UserRole).toString() == currentFile) {
            ui->listWidget_1->item(i)->setText(title);
            break;
        }
    }
}

void MainWindow::saveas()
{
    QString filePath = QFileDialog::getSaveFileName(this, "另存为", "", "文本文件 (*.txt)");
    if (filePath.isEmpty()) return;

    currentFile = filePath;
    save();
}

void MainWindow::exit()
{
    if (textEdit->document()->isModified())
        save();
    textEdit->clear();
    setWindowTitle("无标题 - 文本编辑器");
    currentFile.clear();
}

// -------------------- 状态栏与目录栏 --------------------

void MainWindow::status()
{
    if (ui->statusbar->isVisible())
        ui->statusbar->hide();
    else
        ui->statusbar->show();
}

void MainWindow::content()
{
    // 判断调用来源：如果是点击 listWidget 项，就切换文件；如果是菜单动作，就切换可见性
    QAction *senderAction = qobject_cast<QAction*>(sender());
    if (senderAction && senderAction == ui->content) {
        ui->listWidget_1->setVisible(!ui->listWidget_1->isVisible());
        return;
    }

    // 否则是 listWidget 点击触发的
    QListWidgetItem *item = ui->listWidget_1->currentItem();
    if (!item) return;

    QString path = item->data(Qt::UserRole).toString();
    if (path == currentFile) return;

    if (textEdit->document()->isModified())
        save();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }
    QTextStream in(&file);
    textEdit->setPlainText(in.readAll());
    file.close();

    currentFile = path;
    setWindowTitle(QFileInfo(path).fileName() + " - 文本编辑器");
    textEdit->document()->setModified(false);
}

// -------------------- 辅助 --------------------

void MainWindow::change()
{
    if (currentFile.isEmpty()) {
        setWindowTitle("*无标题 - 文本编辑器");
        return;
    }

    QString title = QFileInfo(currentFile).fileName();
    if (textEdit->document()->isModified()) {
        setWindowTitle("*" + title + " - 文本编辑器");
        for (int i = 0; i < ui->listWidget_1->count(); ++i) {
            if (ui->listWidget_1->item(i)->data(Qt::UserRole).toString() == currentFile) {
                ui->listWidget_1->item(i)->setText("*" + title);
                break;
            }
        }
    }
}

// 初始化状态栏
void MainWindow::initStatusBar()
{
    QLabel *info = new QLabel(this);
    QLabel *count = new QLabel(this);
    info->setText(QTime::currentTime().toString("hh:mm:ss"));
    count->setText("字符数: 0");
    ui->statusbar->addPermanentWidget(count);
    ui->statusbar->addPermanentWidget(info);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        info->setText(QTime::currentTime().toString("hh:mm:ss"));
    });
    timer->start(1000);

    connect(ui->textEdit, &QTextEdit::textChanged, this, [=]() {
        int num = ui->textEdit->toPlainText().length();
        count->setText(QString("字符数: %1").arg(num));
    });
}

// 恢复文件列表
void MainWindow::restoreFileList()
{
    QSettings settings("MyApp", "TxtEditor");
    QStringList paths = settings.value("files").toStringList();
    currentFile = settings.value("current").toString();

    for (const QString &path : paths) {
        if (QFile::exists(path)) {
            QListWidgetItem *item = new QListWidgetItem(QFileInfo(path).fileName());
            item->setData(Qt::UserRole, path);
            ui->listWidget_1->addItem(item);
        }
    }

    // 恢复最后打开的文件
    if (!currentFile.isEmpty() && QFile::exists(currentFile)) {
        QFile file(currentFile);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        textEdit->setPlainText(in.readAll());
        file.close();
        setWindowTitle(QFileInfo(currentFile).fileName() + " - 文本编辑器");
        textEdit->document()->setModified(false);
    }
}

// 保存文件列表
void MainWindow::saveFileList()
{
    QSettings settings("MyApp", "TxtEditor");
    QStringList paths;
    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        paths << ui->listWidget_1->item(i)->data(Qt::UserRole).toString();
    }
    settings.setValue("files", paths);
    settings.setValue("current", currentFile);
}
