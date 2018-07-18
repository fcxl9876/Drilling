#include "widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Drilling");
    this->resize(600,400);

    //菜单项实例化
    drillingView = new QMenu(this);//this指当前窗口
    lithologyView = new QMenu(this);
    drillingCode = new QMenu(this);
    drillingTest = new QMenu(this);
    drillingEdit = new QMenu(this);

    drillingView = menuBar()->addMenu("钻孔显示");
    lithologyView = menuBar()->addMenu("分层显示");
    drillingCode = menuBar()->addMenu("钻孔编码");
    drillingTest = menuBar()->addMenu("钻孔检测");
    drillingEdit = menuBar()->addMenu("编辑钻孔");

    viewDrilling = new QAction("显示钻孔",this);
    viewDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    viewDrilling->setStatusTip("Drilling view");
    connect(viewDrilling,SIGNAL(triggered()),this,SLOT(slotViewDrilling()));

    hideDrilling = new QAction("隐藏钻孔",this);
    hideDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    hideDrilling->setStatusTip("Drilling hide");
    connect(hideDrilling,SIGNAL(triggered()),this,SLOT(slotHideDrilling()));

    viewLine = new QAction("显示孔迹线",this);
    viewLine->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    viewLine->setStatusTip("Drilling view");
    connect(viewLine,SIGNAL(triggered()),this,SLOT(slotViewLine()));

    hideLine = new QAction("隐藏孔迹线",this);
    hideLine->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
    hideLine->setStatusTip("Drilling hide");
    connect(hideLine,SIGNAL(triggered()),this,SLOT(slotHideLine()));

    lithologyDrilling = new QAction("钻孔分层显示",this);
    lithologyDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    lithologyDrilling->setStatusTip("Drilling lithoLogy view");
    connect(lithologyDrilling,SIGNAL(triggered()),this,SLOT(slotLithologyDrilling()));

    viewCode = new QAction("显示编码",this);
    viewCode->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    viewCode->setStatusTip("Drilling code view");

    hideCode = new QAction("隐藏编码",this);
    hideCode->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    hideCode->setStatusTip("Drilling code hide");

    testDrilling = new QAction("钻孔检测",this);
    testDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    testDrilling->setStatusTip("Drilling Test");

    addDrilling = new QAction("添加钻孔",this);
    addDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    addDrilling->setStatusTip("Drilling add");

    removeDrilling = new QAction("删除钻孔",this);
    removeDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    removeDrilling->setStatusTip("Drilling remove");

    drillingView->addAction(viewDrilling);
    drillingView->addAction(hideDrilling);
    drillingView->addAction(viewLine);
    drillingView->addAction(hideLine);

    lithologyView->addAction(lithologyDrilling);

    drillingCode->addAction(viewCode);
    drillingCode->addAction(hideCode);

    drillingTest->addAction(testDrilling);

    drillingEdit->addAction(addDrilling);
    drillingEdit->addAction(removeDrilling);

    menuBar()->hide();

    enterSys = new QPushButton(this);
    enterSys->setText("进入系统");
    enterSys->setGeometry(200,150,200,100);
    connect(enterSys,SIGNAL(clicked()),this,SLOT(enterSystem()));
}

Widget::~Widget()
{

}

void Widget::enterSystem()
{
    menuBar()->show();
    a = new QVTKWidget(this);
    a->GetRenderWindow()->AddRenderer(renderer.renderer);
    delete enterSys;
    setCentralWidget(a);
}
void Widget::slotViewDrilling()
{
    renderer.viewDrilling();
}
void Widget::slotHideDrilling()
{
    renderer.hideDrilling();
}
void Widget::slotViewLine()
{
    renderer.viewLine();
}
void Widget::slotHideLine()
{
    renderer.hideLine();
}
void Widget::slotLithologyDrilling()
{

}
