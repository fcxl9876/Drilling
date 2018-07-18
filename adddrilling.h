#ifndef ADDDRILLING_H
#define ADDDRILLING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "odbchelper.h"

#pragma execution_character_set("utf-8")

extern QString getid;
extern QString getjborehole;
extern QString getjtype;
extern QString getjeast;
extern QString getjnorth;
extern QString getjaltitude;
extern QString getjdepth;
extern QString getjpath;
extern QString getjdrill;

class addD : public QWidget
{
    Q_OBJECT
public:
    addD();

public slots:
    void add();
    void exit();

private:
    QLabel *L1;
    QLabel *L2;
    QLabel *L3;
    QLabel *L4;
    QLabel *L5;
    QLabel *L6;
    QLabel *L7;
    QLabel *L8;
    QLabel *L9;

    QLineEdit *id;
    QLineEdit *jborehole;
    QLineEdit *jtype;
    QLineEdit *jeast;
    QLineEdit *jnorth;
    QLineEdit *jaltitude;
    QLineEdit *jdepth;
    QLineEdit *jpath;
    QLineEdit *jdrill;

    QPushButton *confirm;
    QPushButton *cancel;

    QVBoxLayout *layout;

};

#endif // ADDDRILLING_H
