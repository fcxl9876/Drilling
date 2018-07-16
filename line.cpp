#include "line.h"
#include "odbchelper.h"
#include "renderer.h"

Line::Line()
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


//    vtkSmartPointer<vtkPolyData> linesPolyData = vtkSmartPointer<vtkPolyData>::New();
//    double origin[3] = { 2225.0, 4042.0, 0.0 };
//    double p0[3] = { 2225.0, 4042.0, 100.0 };
//    double p1[3] = { 2225.0, 4042.0, 200.0};
//    double p2[3] = { 2500.0, 4042.0, 0.0 };
//    double p3[3] = { 2500.0, 4042.0, 200.0 };
//    vtkSmartPointer<vtkPoints> pts = vtkSmartPointer<vtkPoints>::New();
//    pts->InsertNextPoint(origin);
//    pts->InsertNextPoint(p0);
//    pts->InsertNextPoint(p1);
//    pts->InsertNextPoint(p2);
//    pts->InsertNextPoint(p3);
//    linesPolyData->SetPoints(pts);
//    vtkSmartPointer<vtkLine> line0 = vtkSmartPointer<vtkLine>::New();
//    line0->GetPointIds()->SetId(0, 0); // 第二个0表示pts中的origin点
//    line0->GetPointIds()->SetId(1, 1); //第二个1表示pts中的p0点
//    vtkSmartPointer<vtkLine> line1 = vtkSmartPointer<vtkLine>::New();
//    line1->GetPointIds()->SetId(0, 3);
//    line1->GetPointIds()->SetId(1, 4);
//    vtkSmartPointer<vtkLine> line2 = vtkSmartPointer<vtkLine>::New();
//    line2->GetPointIds()->SetId(0, 1);
//    line2->GetPointIds()->SetId(1, 2);

//    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
//    lines->InsertNextCell(line0);
//    lines->InsertNextCell(line1);
//    lines->InsertNextCell(line2);
//    linesPolyData->SetLines(lines);
//    float red[3] = {255, 0, 0};
//    float green[3] = {0, 255, 0};
//    float blue[3] = {0, 0, 255};
//    vtkSmartPointer<vtkFloatArray> colors = vtkSmartPointer<vtkFloatArray>::New();
//    colors->SetNumberOfComponents(0);
//    colors->InsertNextTuple(red);
//    colors->InsertNextTuple(blue);
//    colors->InsertNextTuple(green);

//    linesPolyData->GetCellData()->SetScalars(colors);

//    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    mapper->SetInputData(linesPolyData);
//    lineActor = vtkSmartPointer<vtkActor>::New();
//    lineActor->SetMapper(mapper);

    //画线===============================================================================

        vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
        lineSource->SetPoint1(east1[k],north1[k],altitude1[k]);
        lineSource->SetPoint2(east1[k],north1[k],altitude1[k]+depth1[k]);
        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(lineSource->GetOutputPort());    // 设置映射的渲染数据
        lineActor = vtkSmartPointer<vtkActor>::New();
        lineActor->GetProperty()->SetColor(1,0,0);
        lineActor->GetProperty()->SetLineWidth(3);
        lineActor->SetMapper(mapper);

}
