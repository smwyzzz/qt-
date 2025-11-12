#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QLabel>
#include <QTimer>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QTextEdit *textEdit;
    QString currentFile;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newfile();
    void open();
    void save();
    void saveas();
    void exit();
    void change();
    void status();
    void content();

private:
    Ui::MainWindow *ui;
    void initStatusBar();
    void restoreFileList();
    void saveFileList();
};

#endif // MAINWINDOW_H
