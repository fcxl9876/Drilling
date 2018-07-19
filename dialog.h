﻿#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>

#pragma execution_character_set("utf-8")

extern float getdColorR;
extern float getdColorG;
extern float getdColorB;

extern float getcColorR;
extern float getcColorG;
extern float getcColorB;

extern int getThickness;


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

class Page1 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page1(QWidget *parent = 0);

public slots:
    void Color();
    void showColor();

};

class Page2 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page2(QWidget *parent = 0);

public slots:
    void dThickness();

};

class Page3 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page3(QWidget *parent = 0);

public slots:
    void Link();

};

class Page4 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page4(QWidget *parent = 0);

public slots:
    void cColor();
    void showcColor();

};

class Page5 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page5(QWidget *parent = 0);

public slots:
    void Link();

};

class Page6 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page6(QWidget *parent = 0);

public slots:
    void Link();

};

class Page7 : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;

public:
    Page7(QWidget *parent = 0);

public slots:
    void Link();

};

#endif // DIALOG_H
