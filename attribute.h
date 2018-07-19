#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QtWidgets>
#include <QHBoxLayout>
#include "dialog.h"

#pragma execution_character_set("utf-8")

class attribute : public QWidget
{
    Q_OBJECT
public:
    attribute(QWidget *parent = 0);
    ~attribute();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    QListWidget *list;
    QStackedWidget *pages;
    void setLists();

};

#endif // ATTRIBUTE_H
