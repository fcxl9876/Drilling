#ifndef ODBCHELPER_H
#define ODBCHELPER_H
#include "QtSql/qsqlquery.h"
#include "QtSql/qsqldatabase.h"
#include <QDebug>
#include <QMessageBox>
#include "QtSql/qsqlerror.h"

extern int m;
extern int n;
extern int q;

extern double* east1;
extern double* north1;
extern double* altitude1;
extern double* depth1;
extern double* east2;
extern double* north2;
extern double* altitude2;
extern double* depth2;

extern double* jeastfrom;
extern double* jnorthfrom;
extern double* jaltitudefrom;
extern double* jeastto;
extern double* jnorthto;
extern double* jaltitudeto;
extern QString* jlithology;


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

    int getdatacount3();
    double* getjeastfrom();
    double* getjnorthfrom();
    double* getjaltitudefrom();
    double* getjeastto();
    double* getjnorthto();
    double* getjaltitudeto();
    QString* getjlithology();

};

#endif // ODBCHELPER_H
