#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList l;
    l<<"电子产品"<<"文具"<<"食品";
    ui->comboBox->addItems(l);
    ui->comboBox->setCurrentIndex(0);
    l.clear();
    l<<"黑色"<< "蓝色"<<"红色";
    ui->comboBox_3->addItems(l);
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&Widget::change);
    connect(ui->comboBox_2,&QComboBox::currentIndexChanged,this,&Widget::myshow);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::create);
    ui->spinBox->setRange(4,32);
    ui->spinBox->setSingleStep(4);
    ui->spinBox->setWrapping(1);
    myshow();change();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::change(){
    QMap<QString, QStringList> m;
    QString s; QStringList l;
    m["电子产品"] = l<<"手机"<<"电脑";l.clear();
    m["文具"] = l<<"钢笔"<<"笔记本";l.clear();
    m["食品"] = l<<"米饭"<<"面条";l.clear();
    s = ui->comboBox->currentText();
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(m[s]);
}
void Widget::myshow(){
    ui->spinBox->hide();ui->comboBox_3->hide();ui->dateEdit->hide();
    ui->label->setText("");
    QString s;s = ui->comboBox_2->currentText();
    if(s == "手机"){
        ui->label->setText("内存大小");
        ui->spinBox->show();
    }
    if(s == "钢笔"){
        ui->label->setText("颜色");
        ui->comboBox_3->show();
    }
    if(s == "米饭"||s == "面条"){
        ui->label->setText("生产日期");
        ui->dateEdit->show();
    }
}
void Widget::create(){
    QString s;
    s += "产品类型:" + ui->comboBox->currentText() + "\n";
    QString cmp = ui->comboBox_2->currentText();
    s += "产品名:" + cmp + "\n";
    if(cmp == "手机"){
        s += "内存大小:" +ui->spinBox->text() + "\n";
    }
    if(cmp == "钢笔"){
        s += "颜色:"+ui->comboBox_3->currentText()+ "\n";
    }
    if(cmp == "米饭"||cmp == "面条"){
       s += "生产日期:"+ui->dateEdit->text() + "\n";
    }
    s += "日期:" + ui->dateTimeEdit->text() + "\n";
    ui->textEdit->append(s);
}
