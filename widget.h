#ifndef WIDGET_H
#define WIDGET_H

#include "layer.h"

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

#pragma execution_character_set("utf-8")

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void enterSystem();

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

    QAction *lithologyDrilling;

    QAction *viewCode;
    QAction *hideCode;

    QAction *testDrilling;

    QAction *addDrilling;
    QAction *removeDrilling;

    QPushButton *enterSys;

    Layer *layer;
};

#endif // WIDGET_H
