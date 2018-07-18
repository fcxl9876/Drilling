#include "widget.h"

Renderer rend;

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
    connect(viewCode,SIGNAL(triggered()),this,SLOT(slotViewCode()));

    hideCode = new QAction("隐藏编码",this);
    hideCode->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    hideCode->setStatusTip("Drilling code hide");
    connect(hideCode,SIGNAL(triggered()),this,SLOT(slotHideCode()));

    testDrilling = new QAction("钻孔检测",this);
    testDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    testDrilling->setStatusTip("Drilling Test");
    connect(testDrilling,SIGNAL(triggered()),this,SLOT(slotCheckDrilling()));

    addDrilling = new QAction("添加钻孔",this);
    addDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    addDrilling->setStatusTip("Drilling add");
    connect(addDrilling,SIGNAL(triggered()),this,SLOT(slotAddDrilling()));

    removeDrilling = new QAction("删除钻孔",this);
    removeDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    removeDrilling->setStatusTip("Drilling remove");
    connect(removeDrilling,SIGNAL(triggered()),this,SLOT(slotRemoveDrilling()));

    addDrillingData = new QAction("添加孔迹线信息",this);
    addDrillingData->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    addDrillingData->setStatusTip("Drilling add");

    removeDrillingData = new QAction("删除孔迹线信息",this);
    removeDrillingData->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    removeDrillingData->setStatusTip("Drilling remove");


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
    drillingEdit->addAction(addDrillingData);
    drillingEdit->addAction(removeDrillingData);

    menuBar()->hide();

    enterSys = new QPushButton(this);
    enterSys->setText("进入系统");
    enterSys->setGeometry(200,150,200,100);
    connect(enterSys,SIGNAL(clicked()),this,SLOT(enterSystem()));

}

Widget::~Widget()
{

}

//进入系统按钮槽函数
void Widget::enterSystem()
{
    menuBar()->show();
    a = new QVTKWidget(this);
    a->GetRenderWindow()->AddRenderer(rend.renderer);
    delete enterSys;
    setCentralWidget(a);
}

//显示和隐藏钻孔槽函数
void Widget::slotViewDrilling()
{
    rend.viewDrilling();
}
void Widget::slotHideDrilling()
{
    rend.hideDrilling();
}

//显示和隐藏孔迹线槽函数
void Widget::slotViewLine()
{
    rend.viewLine();
}
void Widget::slotHideLine()
{
    rend.hideLine();
}

void Widget::slotAddDrilling()
{
    add = new addD();
    add->show();
}

void Widget::slotRemoveDrilling()
{
    remove = new removeD();
    remove->show();
}

//孔迹线分层显示槽函数
void Widget::slotLithologyDrilling()
{
    LithologyDrilling *l;
    l = new LithologyDrilling();
    l->show();
    rend.hideLine();
}

//显示和隐藏编码槽函数
void Widget::slotViewCode()
{
    rend.viewCode();
}
void Widget::slotHideCode()
{
    rend.hideCode();
}

void Widget::slotCheckDrilling()
{
    QString checkResult=QString("检测结果正常！");

    bool dislocationFlag=false;//是否上下错位
    int *dislocationArray=new int[count];//记录上下错位所在地层的数组
    int a=0;
    bool continueFlag=false;//是否连续多层
    int *continueArray=new int[count];//记录连续多层所在地层的数组
    int b=0;
    bool noContinueFlag=false;//是否不连续多层
    int *noContinueArray=new int[count];//记录不连续多层所在地层的数组
    int c=0;
    bool zeroThicknessFlag=false;//是否有厚度为零的地层
    int *zeroThicknessArray=new int[count];//记录厚度为零的地层
    int d=0;

    for(int i=0;i<count;i++){
        //if判断防止数组越界
        if(i<count-1){
            if(jlithology[i]!="chazhi" && jlithology[i]!="bujialayer" && jlithology[i]!="1"
                    && jlithology[i+1]!="chazhi" && jlithology[i+1]!="bujialayer" && jlithology[i+1]!="1"){
                //检测是否上下错位并记录
                if(jlithology[i] > jlithology[i+1]){
                    dislocationFlag=true;
                    dislocationArray[a]=i;
                    a++;
                }
                //检测是否连续多层并记录
                if(jlithology[i] == jlithology[i+1]){
                    continueFlag=true;
                    continueArray[b]=i;
                    b++;
                 }
            }
        }
        if(i<count-2){
            if(jlithology[i]!="chazhi" && jlithology[i]!="bujialayer" && jlithology[i]!="1"
                    && jlithology[i+2]!="chazhi" && jlithology[i+2]!="bujialayer" && jlithology[i+2]!="1"){
                //检测是否不连续多层并记录
                if(jlithology[i] == jlithology[i+2] && jlithology[i] != jlithology[i+1]){
                    noContinueFlag=true;
                    noContinueArray[c]=i;
                    c++;
                }
            }
        }
        //检测是否有厚度为零的地层并记录
        if(jaltitudeto[i] - jaltitudefrom[i]==0){
            zeroThicknessFlag=true;
            zeroThicknessArray[d]=i;
            d++;
        }
    }
    //输出
    if(dislocationFlag || continueFlag || noContinueFlag || zeroThicknessFlag){
        checkResult="";//清空字符串
        if(dislocationFlag){
            checkResult.append("上下错位！\n");
            for(int i=0;i<a;i++){
                checkResult.append(jlithology[dislocationArray[i]]+"和"+jlithology[dislocationArray[i]+1]+"地层上下错位。\n");
            }
            checkResult.append("\n");
        }
        if(continueFlag){
            checkResult.append("连续多层！\n");
            for(int i=0;i<b;i++){
                checkResult.append(jlithology[continueArray[i]]+"地层连续多层。\n");
            }
            checkResult.append("\n");
        }
        if(noContinueFlag){
            checkResult.append("不连续多层！\n");
            for(int i=0;i<c;i++){
                checkResult.append(jlithology[noContinueArray[i]]+"和"+jlithology[noContinueArray[i]+1]+"和"+jlithology[noContinueArray[i]+2]+"不连续多层。\n");
            }
            checkResult.append("\n");
        }
        if(zeroThicknessFlag){
           checkResult.append("有厚度为零的地层！\n");
           for(int i=0;i<d;i++){
               checkResult.append(jlithology[zeroThicknessArray[i]]+"地层厚度为零。\n");
           }
           checkResult.append("\n");
        }
    }
    QMessageBox::about(this,"检测结果",checkResult);
}
