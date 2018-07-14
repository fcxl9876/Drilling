﻿#include "layer.h"
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
//    //sql.getjtype();
//    int n = sql.getdatacount();
//    int *east = new int[n];
//    east=sql.getjeast();
//    int *north = new int[n];
//    north=sql.getjnorth();
//    int *altitude = new int[n];
//    altitude=sql.getjaltitude();
//    for(int i=0;i<n;i++){
//        qDebug()<<"("<<east[i]<<","<<north[i]<<","<<altitude[i]<<")";
//    }

    Widget *w;
    w = new Widget;
    w->show();

    return a.exec();
}
