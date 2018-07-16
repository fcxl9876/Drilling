#include "line.h"
#include "odbchelper.h"

Line::Line()
{
    vtkSmartPointer<vtkPolyData> linesPolyData = vtkSmartPointer<vtkPolyData>::New();
    double origin[3] = { 2225.0, 4042.0, 0.0 };
    double p0[3] = { 2225.0, 4042.0, 100.0 };
    double p1[3] = { 2225.0, 4042.0, 200.0};
    double p2[3] = { 2500.0, 4042.0, 0.0 };
    double p3[3] = { 2500.0, 4042.0, 200.0 };
    vtkSmartPointer<vtkPoints> pts = vtkSmartPointer<vtkPoints>::New();
    pts->InsertNextPoint(origin);
    pts->InsertNextPoint(p0);
    pts->InsertNextPoint(p1);
    pts->InsertNextPoint(p2);
    pts->InsertNextPoint(p3);
    linesPolyData->SetPoints(pts);
    vtkSmartPointer<vtkLine> line0 = vtkSmartPointer<vtkLine>::New();
    line0->GetPointIds()->SetId(0, 0); // 第二个0表示pts中的origin点
    line0->GetPointIds()->SetId(1, 1); //第二个1表示pts中的p0点
    vtkSmartPointer<vtkLine> line1 = vtkSmartPointer<vtkLine>::New();
    line1->GetPointIds()->SetId(0, 3);
    line1->GetPointIds()->SetId(1, 4);
    vtkSmartPointer<vtkLine> line2 = vtkSmartPointer<vtkLine>::New();
    line2->GetPointIds()->SetId(0, 1);
    line2->GetPointIds()->SetId(1, 2);

    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
    lines->InsertNextCell(line0);
    lines->InsertNextCell(line1);
    lines->InsertNextCell(line2);
    linesPolyData->SetLines(lines);
    float red[3] = {255, 0, 0};
    float green[3] = {0, 255, 0};
    float blue[3] = {0, 0, 255};
    vtkSmartPointer<vtkFloatArray> colors = vtkSmartPointer<vtkFloatArray>::New();
    colors->SetNumberOfComponents(0);
    colors->InsertNextTuple(red);
    colors->InsertNextTuple(blue);
    colors->InsertNextTuple(green);

    linesPolyData->GetCellData()->SetScalars(colors);


    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(linesPolyData);
    lineActor = vtkSmartPointer<vtkActor>::New();
    lineActor->SetMapper(mapper);
}
