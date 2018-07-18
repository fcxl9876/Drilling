#include "adddrillingdetail.h"

#pragma execution_character_set("utf-8")

QString getDid;
QString getDjborehole;
QString getDjsample;
QString getDjdepthfrom;
QString getDjdepthto;
QString getDjeastfrom;
QString getDjnorthfrom;
QString getDjaltitudefrom;
QString getDjeastto;
QString getDjnorthto;
QString getDjaltitudeto;
QString getDjlithology;
QString getDjflag;
QString getDlithologysort;
QString getDattribute;

addDD::addDD()
{
    this->setWindowTitle("添加孔迹线信息");
    this->resize(400,300);

    L1 = new QLabel("id:");
    Did = new QLineEdit();
    L2 = new QLabel("jborehole:");
    Djborehole = new QLineEdit();
    L3 = new QLabel("jsample:");
    Djsample = new QLineEdit();
    L4 = new QLabel("jdepthfrom:");
    Djdepthfrom = new QLineEdit();
    L5 = new QLabel("jdepthto:");
    Djdepthto = new QLineEdit();
    L6 = new QLabel("jeastfrom:");
    Djeastfrom = new QLineEdit();
    L7 = new QLabel("jnorthfrom:");
    Djnorthfrom = new QLineEdit();
    L8 = new QLabel("jaltitudefrom:");
    Djaltitudefrom = new QLineEdit();
    L9 = new QLabel("jeastto:");
    Djeastto = new QLineEdit();
    L10 = new QLabel("jnorthto:");
    Djnorthto = new QLineEdit();
    L11 = new QLabel("jaltitudeto:");
    Djaltitudeto = new QLineEdit();
    L12 = new QLabel("jlithology:");
    Djlithology = new QLineEdit();
    L13 = new QLabel("jflag:");
    Djflag = new QLineEdit();
    L14 = new QLabel("lithologysort:");
    Dlithologysort = new QLineEdit();
    L15 = new QLabel("attribute:");
    Dattribute = new QLineEdit();

    confirm = new QPushButton("添加");
    cancel = new QPushButton("取消");

    layout = new QVBoxLayout();
    layout->addWidget(L1);
    layout->addWidget(Did);
    layout->addWidget(L2);
    layout->addWidget(Djborehole);
    layout->addWidget(L3);
    layout->addWidget(Djsample);
    layout->addWidget(L4);
    layout->addWidget(Djdepthfrom);
    layout->addWidget(L5);
    layout->addWidget(Djdepthto);
    layout->addWidget(L6);
    layout->addWidget(Djeastfrom);
    layout->addWidget(L7);
    layout->addWidget(Djnorthfrom);
    layout->addWidget(L8);
    layout->addWidget(Djaltitudefrom);
    layout->addWidget(L9);
    layout->addWidget(Djeastto);
    layout->addWidget(L10);
    layout->addWidget(Djnorthto);
    layout->addWidget(L11);
    layout->addWidget(Djaltitudeto);
    layout->addWidget(L12);
    layout->addWidget(Djlithology);
    layout->addWidget(L13);
    layout->addWidget(Djflag);
    layout->addWidget(L14);
    layout->addWidget(Dlithologysort);
    layout->addWidget(L15);
    layout->addWidget(Dattribute);
    layout->addWidget(confirm);
    layout->addWidget(cancel);

    this->setLayout(layout);
    connect(confirm,SIGNAL(clicked()),this,SLOT(add()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(exit()));
}

void addDD::add()
{
    odbchelper odbc;

    getDid = this->Did->text();
    getDjborehole = this->Djborehole->text();
    getDjsample = this->Djsample->text();
    getDjdepthfrom = this->Djdepthfrom->text();
    getDjdepthto = this->Djdepthto->text();
    getDjeastfrom = this->Djeastfrom->text();
    getDjnorthfrom = this->Djnorthfrom->text();
    getDjaltitudefrom = this->Djaltitudefrom->text();
    getDjeastto = this->Djeastto->text();
    getDjnorthto = this->Djnorthto->text();
    getDjaltitudeto = this->Djaltitudeto->text();
    getDjlithology = this->Djlithology->text();
    getDjflag = this->Djflag->text();
    getDlithologysort = this->Dlithologysort->text();
    getDattribute = this->Dattribute->text();

    odbc.addDrillingDetail(getDid.toInt(),getDjborehole,getDjsample,getDjdepthfrom.toFloat(),getDjdepthto.toFloat(),getDjeastfrom.toFloat(),getDjnorthfrom.toFloat(),getDjaltitudefrom.toFloat(),getDjeastto.toFloat(),getDjnorthto.toFloat(),getDjaltitudeto.toFloat(),getDjlithology,getDjflag,getDlithologysort.toInt(),getDattribute.toFloat());

}

void addDD::exit()
{
    this->hide();
}
