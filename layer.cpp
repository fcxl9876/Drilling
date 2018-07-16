#include "layer.h"
#include "odbchelper.h"

Layer::Layer()
{
    //读取数据================================================================
    odbchelper sql;
    int m = sql.getdatacount1();
    int n = sql.getdatacount2();

    double *east1 = new double[m];
    east1=sql.getjeast1();
    double *east2 = new double[n];
    east2=sql.getjeast2();

    double *north1 = new double[m];
    north1=sql.getjnorth1();
    double *north2 = new double[n];
    north2=sql.getjnorth2();

    double *altitude1 = new double[m];
    altitude1=sql.getjaltitude1();
    double *altitude2 = new double[n];
    altitude2=sql.getjaltitude2();

    double* depth1 = new double[m];
    depth1 = sql.getjdepth1();
    double* depth2 = new double[n];
    depth2 = sql.getjdepth2();

    //插入数据
    points = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<m;i++){
        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
    }

    for(int i=0;i<n;i++){
        points->InsertNextPoint(east2[i],north2[i],altitude2[i]);
    }
    //END======================================================================

    //三角剖分建立地层============================================================
    polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);

    delaunay = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay->SetInputData(polydata);
    delaunay->Update();

    glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    glyphFilter->SetInputData(polydata);
    glyphFilter->Update();

    pointsMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    pointsMapper->SetInputData(glyphFilter->GetOutput());
    pointsActor = vtkSmartPointer<vtkActor>::New();
    pointsActor->SetMapper(pointsMapper);
    pointsActor->GetProperty()->SetPointSize(3);
    pointsActor->GetProperty()->SetColor(0, 1, 0);

    triangulatedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper->SetInputData(delaunay->GetOutput());
    triangulatedActor = vtkSmartPointer<vtkActor>::New();
    triangulatedActor->SetMapper(triangulatedMapper);
    triangulatedActor->GetProperty()->SetOpacity(0.5);
    triangulatedActor->GetProperty()->SetColor(0,1,0);
}

Layer::~Layer()
{
}
