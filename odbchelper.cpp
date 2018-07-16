#include "odbchelper.h"

int m;
int n;
double* east1;
double* north1;
double* altitude1;
double* depth1;
double* east2;
double* north2;
double* altitude2;
double* depth2;

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
    m=this->getdatacount1();
    n=this->getdatacount2();

    east1=new double[m];
    east1=this->getjeast1();
    north1=new double[m];
    north1=this->getjnorth1();
    altitude1=new double[m];
    altitude1=this->getjaltitude1();
    depth1=new double[m];
    depth1=this->getjdepth1();

    east2=new double[m];
    east2=this->getjeast2();
    north2=new double[m];
    north2=this->getjnorth2();
    altitude2=new double[m];
    altitude2=this->getjaltitude2();
    depth2=new double[m];
    depth2=this->getjdepth1();

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
    int x=0;
    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select count(*) from mycollardata";
    query1->exec(sql1);

    while (query1->next()) {
        x+=query1->value(0).toInt();
    }

    return x;
}

int odbchelper::getdatacount2()
{
    int x=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select count(*) from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()) {
        x+=query2->value(0).toInt();
    }

    return x;
}

double* odbchelper::getjeast1()
{
    int x=getdatacount1();

    double *arr = new double[x];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jeast from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<x) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjeast2()
{
    int x=getdatacount2();

    double *arr = new double[x];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jeast from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<x) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjnorth1()
{
    int x=getdatacount1();

    double *arr = new double[x];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jnorth from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<x) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjnorth2()
{
    int x=getdatacount2();

    double *arr = new double[x];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jnorth from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<x) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjaltitude1()
{
    int x=getdatacount1();

    double *arr = new double[x];
    int i=0;

    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select jaltitude from mycollardata";
    query1->exec(sql1);

    while (query1->next()&&i<x) {
        arr[i]=query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjaltitude2()
{
    int x=getdatacount2();

    double *arr = new double[x];
    int j=0;

    QSqlQuery *query2=new QSqlQuery(db);
    QString sql2="select jaltitude from myvirtualcollardata";
    query2->exec(sql2);

    while (query2->next()&&j<x) {
        arr[j]=query2->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjdepth1()
{
    int x = getdatacount1();

    double *arr = new double[x];
    int i = 0;

    QSqlQuery *query1 = new QSqlQuery(db);
    QString sql1 = "select jdepth from mycollardata";
    query1->exec(sql1);

    while(query1->next()&&i<x)
    {
        arr[i] = query1->value(0).toDouble();
        i++;
    }

    return arr;
}

double* odbchelper::getjdepth2()
{
    int x = getdatacount2();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query2 = new QSqlQuery(db);
    QString sql2 = "select jdepth from myvirtualcollardata";
    query2->exec(sql2);

    while(query2->next()&&j<x)
    {
        arr[j] = query2->value(0).toDouble();
        j++;
    }

    return arr;
}
