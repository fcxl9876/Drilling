#ifndef WIDGET_H
#define WIDGET_H

#include "layer.h"
#include "renderer.h"
#include "adddrilling.h"
#include "removedrilling.h"
#include "adddrillingdetail.h"
#include "removedrillingdetail.h"
#include "lithologydrilling.h"

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>

extern Renderer rend;

#pragma execution_character_set("utf-8")

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void enterSystem();
    void slotViewDrilling();
    void slotHideDrilling();
    void slotViewLine();
    void slotHideLine();
    void slotAddDrilling();
    void slotRemoveDrilling();
    void slotAddDrillingDetail();
    void slotRemoveDrillingDetail();


    void slotLithologyDrilling();
    void slotCheckDrilling();
    void slotViewCode();
    void slotHideCode();



private:
    QMenu *drillingView;
    QMenu *lithologyView;
    QMenu *drillingCode;
    QMenu *drillingTest;
    QMenu *drillingEdit;

    QAction *viewDrilling;
    QAction *hideDrilling;
    QAction *viewLine;
    QAction *hideLine;
    QAction *linearDisplay;
    QAction *columnDisplay;

    QAction *lithologyDrilling;

    QAction *viewCode;
    QAction *hideCode;
    QAction *drillingProperties;

    QAction *testDrilling;

    QAction *addDrilling;
    QAction *removeDrilling;
    QAction *addDrillingData;
    QAction *removeDrillingData;

    QPushButton *enterSys;

//    Renderer rend;
    Layer *layer;
    QVTKWidget *a;

    addD *add;
    removeD *remove;

    addDD *add2;
    removeDD *remove2;

};

#endif // WIDGET_H
