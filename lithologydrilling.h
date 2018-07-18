#ifndef LITHOLOGYDRILLING_H
#define LITHOLOGYDRILLING_H

#include "widget.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

class LithologyDrilling : public QWidget
{
    Q_OBJECT
public:
    LithologyDrilling();
    QVBoxLayout *layout;
    QLabel *label;

    QHBoxLayout *layout1;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QHBoxLayout *layout4;
    QHBoxLayout *layout5;
    QHBoxLayout *layout6;
    QHBoxLayout *layout7;
    QHBoxLayout *layout8;
    QHBoxLayout *layout9;
    QHBoxLayout *layout10;

    QCheckBox *L1_1CheckBox;
    QCheckBox *L1_2CheckBox;
    QCheckBox *L2_1CheckBox;
    QCheckBox *L2_2CheckBox;
    QCheckBox *L2_3CheckBox;
    QCheckBox *L3_1CheckBox;
    QCheckBox *L3_2CheckBox;
    QCheckBox *L3_3CheckBox;
    QCheckBox *L4_1CheckBox;
    QCheckBox *L4_2CheckBox;
    QCheckBox *L5_1_1CheckBox;
    QCheckBox *L5_1_2CheckBox;
    QCheckBox *L5_2CheckBox;
    QCheckBox *L5_3CheckBox;
    QCheckBox *L5_4CheckBox;
    QCheckBox *L6CheckBox;
    QCheckBox *L7_1CheckBox;
    QCheckBox *L7_2CheckBox;
    QCheckBox *L8_1CheckBox;
    QCheckBox *L8_2CheckBox;
    QCheckBox *L9_1CheckBox;
    QCheckBox *L9_2CheckBox;
    QCheckBox *L10CheckBox;
    QCheckBox *L11CheckBox;
    QCheckBox *L12CheckBox;
    QCheckBox *L13CheckBox;
    QCheckBox *L13_2CheckBox;
    QCheckBox *L14CheckBox;
    QCheckBox *chazhiCheckBox;
    QCheckBox *bujialayerCheckBox;

public slots:
    void L1_1OnStateChanged(int state);
    void L1_2OnStateChanged(int state);
    void L2_1OnStateChanged(int state);
    void L2_2OnStateChanged(int state);
    void L2_3OnStateChanged(int state);
    void L3_1OnStateChanged(int state);
    void L3_2OnStateChanged(int state);
    void L3_3OnStateChanged(int state);
    void L4_1OnStateChanged(int state);
    void L4_2OnStateChanged(int state);
    void L5_1_1OnStateChanged(int state);
    void L5_1_2OnStateChanged(int state);
    void L5_2OnStateChanged(int state);
    void L5_3OnStateChanged(int state);
    void L5_4OnStateChanged(int state);
    void L6OnStateChanged(int state);
    void L7_1OnStateChanged(int state);
    void L7_2OnStateChanged(int state);
    void L8_1OnStateChanged(int state);
    void L8_2OnStateChanged(int state);
    void L9_1OnStateChanged(int state);
    void L9_2OnStateChanged(int state);
    void L10OnStateChanged(int state);
    void L11OnStateChanged(int state);
    void L12OnStateChanged(int state);
    void L13OnStateChanged(int state);
    void L13_2OnStateChanged(int state);
    void L14OnStateChanged(int state);
    void chazhiOnStateChanged(int state);
    void bujialayerOnStateChanged(int state);

};

#endif // LITHOLOGYDRILLING_H
