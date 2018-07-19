#include "dialog.h"
#include <QtWidgets>

#pragma execution_character_set("utf-8")

float getdColorR=0;
float getdColorG=1;
float getdColorB=0;

float getcColorR=0;
float getcColorG=1;
float getcColorB=0;

int getThickness=3;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
}

Dialog::~Dialog()
{

}

Page1::Page1(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label =new QLabel("请使用调色盘或手动输入要调整颜色的RGB值：");
    QLabel *label1 =new QLabel("R:");
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel("G:");
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel("B:");
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("调色盘"));
    QPushButton *btn2 = new QPushButton(QObject::tr("确认"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(label);
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    vLayout->addWidget(btn2,0,Qt::AlignTop);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(Color()));
}

Page2::Page2(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label =new QLabel("请输入钻孔粗细:");
    text1 =new QLineEdit();
    QPushButton *btn1 = new QPushButton("设置");
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout1->addWidget(label);
    hLayout2->addWidget(text1);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(dThickness()));
}

Page3::Page3(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label1 =new QLabel(QObject::tr("String1:"));
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel(QObject::tr("String2:"));
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel(QObject::tr("Result:"));
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("link"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(Link()));
}

Page4::Page4(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label =new QLabel("请使用调色盘或手动输入要调整颜色的RGB值");
    QLabel *label1 =new QLabel("R:");
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel("G:");
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel("B:");
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("调色盘"));
    QPushButton *btn2 = new QPushButton(QObject::tr("确认"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(label);
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    vLayout->addWidget(btn2,0,Qt::AlignTop);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(showcColor()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(cColor()));
}

Page5::Page5(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label1 =new QLabel(QObject::tr("String1:"));
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel(QObject::tr("String2:"));
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel(QObject::tr("Result:"));
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("link"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(Link()));
}

Page6::Page6(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label1 =new QLabel(QObject::tr("String1:"));
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel(QObject::tr("String2:"));
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel(QObject::tr("Result:"));
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("link"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(Link()));
}

Page7::Page7(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label1 =new QLabel(QObject::tr("String1:"));
    text1 =new QLineEdit();
    QLabel *label2 =new QLabel(QObject::tr("String2:"));
    text2 =new QLineEdit();
    QLabel *label3 =new QLabel(QObject::tr("Result:"));
    text3 =new QLineEdit();
    QPushButton *btn1 = new QPushButton(QObject::tr("link"));
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout1->addWidget(label1);
    hLayout1->addWidget(text1);
    vLayout->addLayout(hLayout1);
    hLayout2->addWidget(label2);
    hLayout2->addWidget(text2);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(btn1,0,Qt::AlignTop);
    hLayout3->addWidget(label3);
    hLayout3->addWidget(text3);
    vLayout->addLayout(hLayout3);
    setLayout(vLayout);
    connect(btn1,SIGNAL(clicked()),this,SLOT(Link()));
}

void Page1::Color()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString str3=text3->text();
    if(str1.toFloat()>=0 && str1.toFloat()<=255 && str2.toFloat()>=0 && str2.toFloat()<=255 && str2.toFloat()>=0 && str2.toFloat()<=255)
    {
        getdColorR = (str1.toFloat())/255;
        getdColorG = (str2.toFloat())/255;
        getdColorB = (str3.toFloat())/255;

        QMessageBox::about(NULL,QString("设置成功"),QString("设置钻孔颜色成功"));
    }else
    {
        QMessageBox::warning(NULL,QString("设置失败"),QString("设置钻孔颜色失败"));
    }
}

void Page1::showColor()
{
    QColor c = QColorDialog::getColor(Qt::green);//静态方法，默认为绿色，括号中的参数为默认颜色
    if(c.isValid())
    {
        QString r=QString::number(c.red(),10);
        QString g=QString::number(c.green(),10);
        QString b=QString::number(c.blue(),10);
        text1->setText(r);
        text2->setText(g);
        text3->setText(b);
    }else
    {
        QMessageBox::warning(NULL,QString("Warning"),QString("颜色错误"));
    }
}

void Page2::dThickness()
{
    QString str = text1->text();
    getThickness = str.toInt();
    QMessageBox::about(NULL,QString("设置成功"),QString("设置钻孔粗细成功"));
}

void Page3::Link()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString s = str1 + str2;
    text3->setText(s);
}

void Page4::cColor()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString str3=text3->text();
    if(str1.toFloat()>=0 && str1.toFloat()<=255 && str2.toFloat()>=0 && str2.toFloat()<=255 && str2.toFloat()>=0 && str2.toFloat()<=255)
    {
        getcColorR = (str1.toFloat())/255;
        getcColorG = (str2.toFloat())/255;
        getcColorB = (str3.toFloat())/255;

        QMessageBox::about(NULL,QString("设置成功"),QString("设置钻孔颜色成功"));
    }else
    {
        QMessageBox::warning(NULL,QString("设置失败"),QString("设置钻孔颜色成功"));
    }

}

void Page4::showcColor()
{
    QColor c = QColorDialog::getColor(Qt::green);//静态方法，默认为绿色，括号中的参数为默认颜色
    if(c.isValid())
    {
        QString r=QString::number(c.red(),10);
        QString g=QString::number(c.green(),10);
        QString b=QString::number(c.blue(),10);
        text1->setText(r);
        text2->setText(g);
        text3->setText(b);
    }else
    {
        QMessageBox::warning(NULL,QString("Warning"),QString("颜色错误"));
    }
}

void Page5::Link()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString s = str1 + str2;
    text3->setText(s);
}

void Page6::Link()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString s = str1 + str2;
    text3->setText(s);
}

void Page7::Link()
{
    QString str1=text1->text();
    QString str2=text2->text();
    QString s = str1 + str2;
    text3->setText(s);
}
