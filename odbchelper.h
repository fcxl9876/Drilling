#ifndef ODBCHELPER_H
#define ODBCHELPER_H
#include "QtSql/qsqlquery.h"
#include "QtSql/qsqldatabase.h"
#include <QDebug>
#include <QMessageBox>
#include "QtSql/qsqlerror.h"

extern int m;
extern int n;
extern double* east1;
extern double* north1;
extern double* altitude1;
extern double* depth1;
extern double* east2;
extern double* north2;
extern double* altitude2;
extern double* depth2;

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
    double* getjdepth1();
    double* getjeast2();
    double* getjnorth2();
    double* getjaltitude2();
    double* getjdepth2();
};

#endif // ODBCHELPER_H
