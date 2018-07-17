#include "odbchelper.h"

int m;
int n;
int q;

double* east1;
double* north1;
double* altitude1;
double* depth1;
double* east2;
double* north2;
double* altitude2;
double* depth2;

double* jeastfrom;
double* jnorthfrom;
double* jaltitudefrom;
double* jeastto;
double* jnorthto;
double* jaltitudeto;
QString* jlithology;
QString* jcolor;

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
    q=this->getdatacount3();

    east1=new double[m];
    east1=this->getjeast1();
    north1=new double[m];
    north1=this->getjnorth1();
    altitude1=new double[m];
    altitude1=this->getjaltitude1();
    depth1=new double[m];
    depth1=this->getjdepth1();

    east2=new double[n];
    east2=this->getjeast2();
    north2=new double[n];
    north2=this->getjnorth2();
    altitude2=new double[n];
    altitude2=this->getjaltitude2();
    depth2=new double[n];
    depth2=this->getjdepth2();

    jeastfrom=new double[q];
    jeastfrom=this->getjeastfrom();
    jnorthfrom=new double[q];
    jnorthfrom=this->getjnorthfrom();
    jaltitudefrom=new double[q];
    jaltitudefrom=this->getjaltitudefrom();
    jeastto=new double[q];
    jeastto=this->getjeastto();
    jnorthto=new double[q];
    jnorthto=this->getjnorthto();
    jaltitudeto=new double[q];
    jaltitudeto=this->getjaltitudeto();
    jlithology=new QString[q];
    jlithology=this->getjlithology();

//    jcolor=new QString[q];
//    jcolor=this->getjcolor(jlithology);

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

int odbchelper::getdatacount3()
{
    int x=0;
    QSqlQuery *query1=new QSqlQuery(db);
    QString sql1="select count(*) from mylithologydata";
    query1->exec(sql1);

    while (query1->next()) {
        x+=query1->value(0).toInt();
    }

    return x;
}

double* odbchelper::getjeastfrom()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jeastfrom from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjnorthfrom()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jnorthfrom from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjaltitudefrom()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jaltitudefrom from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjeastto()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jeastto from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjnorthto()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jnorthto from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

double* odbchelper::getjaltitudeto()
{
    int x = getdatacount3();

    double *arr = new double[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jaltitudeto from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toDouble();
        j++;
    }

    return arr;
}

QString* odbchelper::getjlithology()
{
    int x = getdatacount3();

    QString *arr = new QString[x];
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    QString sql = "select jlithology from mylithologydata";
    query->exec(sql);

    while(query->next()&&j<x)
    {
        arr[j] = query->value(0).toString();
        j++;
    }

    return arr;
}

QString* odbchelper::getjcolor(QString *str)
{
    int x = getdatacount3();

    QString *arr = new QString[x];
    int i = 0;
    int j = 0;

    QSqlQuery *query = new QSqlQuery(db);
    for(i=0,j=0;i<x,j<x;i++){
        if(str[i]=="1"){
            arr[j]="#00FF00";
        } else if(str[i]=="chazhi"||str[i]=="bujialayer"){
            arr[j]="#FF0000";
        } else{
            QString sql = QString("select jcolor from lithologytype where jtype = '%1'").arg(str[i]);
            query->exec(sql);
            while(query->next()&&j<x)
            {
                arr[j] = query->value(0).toString();
                j++;
            }
        }
    }
    return arr;
}

double odbchelper::returnR(QString str)
{
    double r;
    QString s = str.mid(2,2);
    bool ok;
    r=(s.toInt(&ok,10))/255;
    return r;
}

double odbchelper::returnG(QString str)
{
    double g;
    QString s = str.mid(4,2);
    bool ok;
    g=(s.toInt(&ok,10))/255;
    return g;
}

double odbchelper::returnB(QString str)
{
    double b;
    QString s = str.mid(6,2);
    bool ok;
    b=(s.toInt(&ok,10))/255;
    return b;
}

