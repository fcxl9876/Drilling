#ifndef ADDDRILLING_H
#define ADDDRILLING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class addDrilling : public QWidget
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

    QPushButton *confirm;
    QPushButton *cancel;

    QVBoxLayout *layout;
};

#endif // ADDDRILLING_H
