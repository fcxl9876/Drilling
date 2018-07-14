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

int odbchelper::getdatacount()
{
    int n;
    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select count(*) from mycollardata";
    query->exec(sql);

    while (query->next()) {
        n=query->value(0).toInt();
    }
    return n;
}

int* odbchelper::getjeast()
{
    int n=getdatacount();

    int *arr = new int[n];
    int i=0;

    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select jeast from mycollardata";
    query->exec(sql);

    while (query->next()&&i<n) {
        arr[i]=query->value(0).toDouble();
        i++;
    }

    return arr;
}

int* odbchelper::getjnorth()
{
    int n=getdatacount();

    int *arr = new int[n];
    int i=0;

    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select jaltitude from mycollardata";
    query->exec(sql);

    while (query->next()&&i<n) {
        arr[i]=query->value(0).toDouble();
        i++;
    }

    return arr;
}

int* odbchelper::getjaltitude()
{
    int n=getdatacount();

    int *arr = new int[n];
    int i=0;

    QSqlQuery *query=new QSqlQuery(db);
    QString sql="select jaltitude from mycollardata";
    query->exec(sql);

    while (query->next()&&i<n) {
        arr[i]=query->value(0).toDouble();
        i++;
    }

    return arr;
}
