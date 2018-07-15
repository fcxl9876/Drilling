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
    int getdatacount1();
    int getdatacount2();
    double* getjeast1();
    double* getjnorth1();
    double* getjaltitude1();
    double* getjeast2();
    double* getjnorth2();
    double* getjaltitude2();
};

#endif // ODBCHELPER_H
