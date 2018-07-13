#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#pragma execution_character_set("utf-8")

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QMenu *drillingView;
    QMenu *lithologyView;
    QMenu *drillingCode;
    QMenu *drillingTest;
    QMenu *drillingEdit;

    QAction *viewDrilling;
    QAction *hideDrilling;

    QAction *lithologyDrilling;

    QAction *viewCode;
    QAction *hideCode;

    QAction *testDrilling;

    QAction *addDrilling;
    QAction *removeDrilling;

};

#endif // WIDGET_H
