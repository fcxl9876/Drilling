#include "lithologydrilling.h"

#pragma execution_character_set("utf-8")

LithologyDrilling::LithologyDrilling()
{
    this->setWindowTitle("钻孔分层显示");
    this->resize(400,300);

    layout = new QVBoxLayout();
    label = new QLabel("请选择需要显示的地层：");
    btn = new QPushButton("确定");
    connect(btn,SIGNAL(clicked()),this,SLOT(close()));


    layout1 = new QHBoxLayout();
    layout2 = new QHBoxLayout();
    layout3 = new QHBoxLayout();
    layout4 = new QHBoxLayout();
    layout5 = new QHBoxLayout();
    layout6 = new QHBoxLayout();
    layout7 = new QHBoxLayout();
    layout8 = new QHBoxLayout();
    layout9 = new QHBoxLayout();
    layout10 = new QHBoxLayout();

    //checkbox=================================================================================
    L1_1CheckBox = new QCheckBox("L1_1层", this);
    connect(L1_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L1_1OnStateChanged(int)));
    L1_2CheckBox = new QCheckBox("L1_2层", this);
    connect(L1_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L1_2OnStateChanged(int)));
    L2_1CheckBox = new QCheckBox("L2_1层", this);
    connect(L2_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L2_1OnStateChanged(int)));
    L2_2CheckBox = new QCheckBox("L2_2层", this);
    connect(L2_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L2_2OnStateChanged(int)));
    L2_3CheckBox = new QCheckBox("L2_3层", this);
    connect(L2_3CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L2_3OnStateChanged(int)));
    L3_1CheckBox = new QCheckBox("L3_1层", this);
    connect(L3_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L3_1OnStateChanged(int)));
    L3_2CheckBox = new QCheckBox("L3_2层", this);
    connect(L3_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L3_2OnStateChanged(int)));
    L3_3CheckBox = new QCheckBox("L3_3层", this);
    connect(L3_3CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L3_3OnStateChanged(int)));
    L4_1CheckBox = new QCheckBox("L4_1层", this);
    connect(L4_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L4_1OnStateChanged(int)));
    L4_2CheckBox = new QCheckBox("L4_2层", this);
    connect(L4_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L4_2OnStateChanged(int)));
    L5_1_1CheckBox = new QCheckBox("L5_1_1层", this);
    connect(L5_1_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L5_1_1OnStateChanged(int)));
    L5_1_2CheckBox = new QCheckBox("L5_1_2层", this);
    connect(L5_1_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L5_1_2OnStateChanged(int)));
    L5_2CheckBox = new QCheckBox("L5_2层", this);
    connect(L5_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L5_2OnStateChanged(int)));
    L5_3CheckBox = new QCheckBox("L5_3层", this);
    connect(L5_3CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L5_3OnStateChanged(int)));
    L5_4CheckBox = new QCheckBox("L5_4层", this);
    connect(L5_4CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L5_4OnStateChanged(int)));
    L6CheckBox = new QCheckBox("L6层", this);
    connect(L6CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L6OnStateChanged(int)));
    L7_1CheckBox = new QCheckBox("L7_1层", this);
    connect(L7_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L7_1OnStateChanged(int)));
    L7_2CheckBox = new QCheckBox("L7_2层", this);
    connect(L7_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L7_2OnStateChanged(int)));
    L8_1CheckBox = new QCheckBox("L8_1层", this);
    connect(L8_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L8_1OnStateChanged(int)));
    L8_2CheckBox = new QCheckBox("L8_2层", this);
    connect(L8_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L8_2OnStateChanged(int)));
    L9_1CheckBox = new QCheckBox("L9_1层", this);
    connect(L9_1CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L9_1OnStateChanged(int)));
    L9_2CheckBox = new QCheckBox("L9_2层", this);
    connect(L9_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L9_2OnStateChanged(int)));
    L10CheckBox = new QCheckBox("L10层", this);
    connect(L10CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L10OnStateChanged(int)));
    L11CheckBox = new QCheckBox("L11层", this);
    connect(L11CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L11OnStateChanged(int)));
    L12CheckBox = new QCheckBox("L12层", this);
    connect(L12CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L12OnStateChanged(int)));
    L13CheckBox = new QCheckBox("L13层", this);
    connect(L13CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L13OnStateChanged(int)));
    L13_2CheckBox = new QCheckBox("L13_2层", this);
    connect(L13_2CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L13_2OnStateChanged(int)));
    L14CheckBox = new QCheckBox("L14层", this);
    connect(L14CheckBox, SIGNAL(stateChanged(int)), this, SLOT(L14OnStateChanged(int)));
    chazhiCheckBox = new QCheckBox("chazhi层", this);
    connect(chazhiCheckBox, SIGNAL(stateChanged(int)), this, SLOT(chazhiOnStateChanged(int)));
    bujialayerCheckBox = new QCheckBox("bujialayer层", this);
    connect(bujialayerCheckBox, SIGNAL(stateChanged(int)), this, SLOT(bujialayerOnStateChanged(int)));

    //添加layout======================================================================================
    layout1->addWidget(L1_1CheckBox);
    layout1->addWidget(L1_2CheckBox);
    layout1->addWidget(L2_1CheckBox);

    layout2->addWidget(L2_2CheckBox);
    layout2->addWidget(L2_3CheckBox);
    layout2->addWidget(L3_1CheckBox);

    layout3->addWidget(L3_2CheckBox);
    layout3->addWidget(L3_3CheckBox);
    layout3->addWidget(L4_1CheckBox);

    layout4->addWidget(L4_2CheckBox);
    layout4->addWidget(L5_1_1CheckBox);
    layout4->addWidget(L5_1_2CheckBox);

    layout5->addWidget(L5_2CheckBox);
    layout5->addWidget(L5_3CheckBox);
    layout5->addWidget(L5_4CheckBox);

    layout6->addWidget(L6CheckBox);
    layout6->addWidget(L7_1CheckBox);
    layout6->addWidget(L7_2CheckBox);

    layout7->addWidget(L8_1CheckBox);
    layout7->addWidget(L8_2CheckBox);
    layout7->addWidget(L9_1CheckBox);

    layout8->addWidget(L9_2CheckBox);
    layout8->addWidget(L10CheckBox);
    layout8->addWidget(L11CheckBox);

    layout9->addWidget(L12CheckBox);
    layout9->addWidget(L13CheckBox);
    layout9->addWidget(L13_2CheckBox);

    layout10->addWidget(L14CheckBox);
    layout10->addWidget(chazhiCheckBox);
    layout10->addWidget(bujialayerCheckBox);

    layout->addWidget(label);
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->addLayout(layout3);
    layout->addLayout(layout4);
    layout->addLayout(layout5);
    layout->addLayout(layout6);
    layout->addLayout(layout7);
    layout->addLayout(layout8);
    layout->addLayout(layout9);
    layout->addLayout(layout10);
    layout->addWidget(btn);
    this->setLayout(layout);
}


//checkbox的槽函数========================================================================

void LithologyDrilling::L1_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL1_1();
    }
}
void LithologyDrilling::L1_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL1_2();
    }
}
void LithologyDrilling::L2_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL2_1();
    }
}
void LithologyDrilling::L2_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL2_2();
    }
}
void LithologyDrilling::L2_3OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL2_3();
    }
}
void LithologyDrilling::L3_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL3_1();
    }
}
void LithologyDrilling::L3_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL3_2();
    }
}
void LithologyDrilling::L3_3OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL3_3();
    }
}
void LithologyDrilling::L4_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL4_1();
    }
}
void LithologyDrilling::L4_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL4_2();
    }
}
void LithologyDrilling::L5_1_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL5_1_1();
    }
}
void LithologyDrilling::L5_1_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL5_1_2();
    }
}
void LithologyDrilling::L5_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL5_2();
    }
}
void LithologyDrilling::L5_3OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL5_3();
    }
}
void LithologyDrilling::L5_4OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL5_4();
    }
}
void LithologyDrilling::L6OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL6();
    }
}
void LithologyDrilling::L7_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL7_1();
    }
}
void LithologyDrilling::L7_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL7_2();
    }
}
void LithologyDrilling::L8_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL8_1();
    }
}
void LithologyDrilling::L8_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL8_2();
    }
}
void LithologyDrilling::L9_1OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL9_1();
    }
}
void LithologyDrilling::L9_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL9_2();
    }
}
void LithologyDrilling::L10OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL10();
    }
}
void LithologyDrilling::L11OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL11();
    }
}
void LithologyDrilling::L12OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL12();
    }
}
void LithologyDrilling::L13OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL13();
    }
}
void LithologyDrilling::L13_2OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL13_2();
    }
}
void LithologyDrilling::L14OnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showL14();
    }
}
void LithologyDrilling::chazhiOnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showchazhi();
    }
}
void LithologyDrilling::bujialayerOnStateChanged(int state)
{
    if(state == Qt::Checked)
    {
        rend.showbujialayer();
    }
}
