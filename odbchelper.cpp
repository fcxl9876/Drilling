#include "odbchelper.h"

odbchelper::odbchelper()
{
    this->db=QSqlDatabase::addDatabase("QODBC");
    QString conn = "Driver={PostgreSQL UNICODE(x64)};server=127.0.0.1;port=5433;uid=postgres;pwd=123456;database=drilling";
    this->db.setDatabaseName(conn);
    if(!this->db.open()){
        QMessageBox::critical(0,QString("odbc error"),
                              QString("??Openopen db error'").arg(this->db.lastError().text()));
        return;
    }
}

void odbchelper::getjtype()
{
    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select jtype from lithologytype";
    query->exec(sql);

    while (query->next()) {
        qDebug()<<query->value(0);
    }
}

int odbchelper::getdatacount1()
{
    int n=0;
    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select count(*) from mycollardata";
    query1->exec(sql1);

    while (query1->next()) {
        n+=query1->value(0).toInt();
    }

    return n;
}

int odbchelper::getdatacount2()
{
    int n=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select count(*) from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()) {
        n+=query2->value(0).toInt();
    }

    return n;
}

double* odbchelper::getjeast1()
{
    int m=getdatacount1();

    double *arr = new double[m];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jeast from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<m) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjeast2()
{
    int n=getdatacount2();

    double *arr = new double[n];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jeast from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<n) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjnorth1()
{
    int m=getdatacount1();

    double *arr = new double[m];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jnorth from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<m) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjnorth2()
{
    int n=getdatacount2();

    double *arr = new double[n];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jnorth from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<n) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjaltitude1()
{
    int m=getdatacount1();

    double *arr = new double[m];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jaltitude from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<m) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjaltitude2()
{
    int n=getdatacount2();

    double *arr = new double[n];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jaltitude from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<n) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjdepth1()
{
    int m = getdatacount1();

    double *arr = new double[m];
    int i = 0;

    QSqlQuery *query1 = new QSqlQuery(db);
    QString sql1 = "select jdepth from mycollardata";
    query1->exec(sql1);

    while(query1->next()&&i<m)
    {
        arr[i] = query1->value(0).toDouble();
        i++;
    }

    return arr;
}
double* odbchelper::getjdepth2()
{
    int n = getdatacount2();

    double *arr = new double[n];
    int j = 0;

    QSqlQuery *query2 = new QSqlQuery(db);
    QString sql2 = "select jdepth from myvirtualcollardata";
    query2->exec(sql2);

    while(query2->next()&&j<n)
    {
        arr[j] = query2->value(0).toDouble();
        j++;
    }

    return arr;
}
