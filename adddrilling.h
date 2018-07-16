#ifndef ADDDRILLING_H
#define ADDDRILLING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class addDrilling : public QMainWindow
{
    Q_OBJECT
public:
    addDrilling();

public slots:

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
};

#endif // ADDDRILLING_H
