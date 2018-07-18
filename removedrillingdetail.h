#ifndef REMOVEDRILLINGDETAIL_H
#define REMOVEDRILLINGDETAIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "odbchelper.h"

#pragma execution_character_set("utf-8")

extern QString getid2;
extern QString getjborehole3;

class removeDD : public QWidget
{
    Q_OBJECT
public:
    removeDD();

public slots:
    void remove();
    void exit();

private:
    QLabel *L1;
    QLineEdit *id;
    QLabel *L2;
    QLineEdit *jborehole;

    QPushButton *confirm;
    QPushButton *cancel;

    QVBoxLayout *layout;
};

#endif // REMOVEDRILLINGDETAIL_H
