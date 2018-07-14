#ifndef ODBCHELPER_H
#define ODBCHELPER_H
#include "QtSql/qsqlquery.h"
#include "QtSql/qsqldatabase.h"
#include <QDebug>
#include <QMessageBox>
#include "QtSql/qsqlerror.h"

class odbchelper
{
public:
    odbchelper();
    QSqlDatabase db;
    void getjtype();
    int getdatacount();
    int* getjeast();
    int* getjnorth();
    int* getjaltitude();
};

#endif // ODBCHELPER_H
