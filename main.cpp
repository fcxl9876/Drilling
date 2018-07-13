#include "widget.h"
#include "odbchelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    odbchelper w;
    //w.getjtype();
    return a.exec();
}
