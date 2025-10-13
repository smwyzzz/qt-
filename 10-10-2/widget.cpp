#include "widget.h"
#include "ui_widget.h"
#include "QCompleter"
#include "QTimer"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    set();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::set(){
    QStringList list;
    list<<"user2024"<<"admin"<<"guest";
    QCompleter *c= new QCompleter(list);
    ui->lineEdit->setCompleter(c);
    ui->spinBox->setRange(18,100);
    QTimer *t = new QTimer(this);
    t->setInterval(10);
    QMap<QString, int> m;
    m.insert("管理员",10);
    m.insert("普通用户",5);
    m.insert("访客",1);
    ui->comboBox->addItems(m.keys());
    connect(ui->checkBox,&QCheckBox::checkStateChanged,this,&Widget::hide);
    connect(t,&QTimer::timeout,this,&Widget::display);
    t->start();
}
void Widget::display(){
    QString s;
    s += "用户名:" + ui->lineEdit->text() + "\n";
    if(ui->checkBox->isChecked()){
        s += "密码:*********\n";
    }
    else{
        s += "密码:" + ui->lineEdit_2->text() + "\n";
    }
    s += "年龄:" + ui->spinBox->text() + "\n";
    s += "权限:" + ui->comboBox->currentText() + ""+ "\n";
    ui->textEdit->setText(s);
}
void Widget::hide(){
    if(ui->checkBox->isChecked()){
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
}
