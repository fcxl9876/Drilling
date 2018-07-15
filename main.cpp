#include "layer.h"
#include "widget.h"
#include "odbchelper.h"
#include <QApplication>
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    odbchelper sql;
//    int m = sql.getdatacount1();
//    int n = sql.getdatacount2();

//    double *east1 = new double[m];
//    east1=sql.getjeast1();
//    double *east2 = new double[n];
//    east2=sql.getjeast2();

//    double *north1 = new double[m];
//    north1=sql.getjnorth1();
//    double *north2 = new double[n];
//    north2=sql.getjnorth2();

//    double *altitude1 = new double[m];
//    altitude1=sql.getjaltitude1();
//    double *altitude2 = new double[n];
//    altitude2=sql.getjaltitude2();

//    for(int i=0;i<m;i++){
//        qDebug()<<"("<<east1[i]<<","<<north1[i]<<","<<altitude1[i]<<")";
//    }

//    for(int i=0;i<n;i++){
//        qDebug()<<"("<<east2[i]<<","<<north2[i]<<","<<altitude2[i]<<")";
//    }

    Widget *w;
    w = new Widget;
    w->show();

    return a.exec();
}
