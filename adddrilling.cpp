#include "adddrilling.h"

addDrilling::addDrilling(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("添加钻孔");
    this->resize(400,300);

    L1 = new QLabel(this);
    id = new QLineEdit(this);
    L2 = new QLabel(this);
    jborehole = new QLineEdit(this);
    L3 = new QLabel(this);
    jtype = new QLineEdit(this);
    L4 = new QLabel(this);
    jeast = new QLineEdit(this);
    L5 = new QLabel(this);
    jnorth = new QLineEdit(this);
    L6 = new QLabel(this);
    jaltitude = new QLineEdit(this);
    L7 = new QLabel(this);
    jdepth = new QLineEdit(this);
    L8 = new QLabel(this);
    jpath = new QLineEdit(this);
    L9 = new QLabel(this);
    jdrill = new QLineEdit(this);


}
