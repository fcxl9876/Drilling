#include "line.h"
#include "odbchelper.h"
#include "renderer.h"

Line::Line()
{


    //插入数据
//    points = vtkSmartPointer<vtkPoints>::New();
//    for(int i=0;i<m;i++){
//        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
//    }

//    for(int i=0;i<n;i++){
//        points->InsertNextPoint(east2[i],north2[i],altitude2[i]);
//    }
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

        vtkSmartPointer<vtkLineSource> lineSource1 = vtkSmartPointer<vtkLineSource>::New();
        lineSource1->SetPoint1(east1[k],north1[k],altitude1[k]);
        lineSource1->SetPoint2(east1[k],north1[k],altitude1[k]+depth1[k]);
        vtkSmartPointer<vtkPolyDataMapper> mapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper1->SetInputConnection(lineSource1->GetOutputPort());    // 设置映射的渲染数据
        lineActor1 = vtkSmartPointer<vtkActor>::New();
        lineActor1->GetProperty()->SetColor(1,0,0);
        lineActor1->GetProperty()->SetLineWidth(3);
        lineActor1->SetMapper(mapper1);

        vtkSmartPointer<vtkLineSource> lineSource2 = vtkSmartPointer<vtkLineSource>::New();
        lineSource2->SetPoint1(east1[k],north1[k],altitude1[k]+depth1[k]);
        lineSource2->SetPoint2(east1[k],north1[k],altitude1[k]+depth1[k]*2);
        vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper2->SetInputConnection(lineSource2->GetOutputPort());    // 设置映射的渲染数据
        lineActor2 = vtkSmartPointer<vtkActor>::New();
        lineActor2->GetProperty()->SetColor(0.4,0.8,1);
        lineActor2->GetProperty()->SetLineWidth(3);
        lineActor2->SetMapper(mapper2);



}
