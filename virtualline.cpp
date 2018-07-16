#include "virtualline.h"
#include "odbchelper.h"
#include "renderer.h"

VirtualLine::VirtualLine()
{

    vtkSmartPointer<vtkLineSource> lineSource2 = vtkSmartPointer<vtkLineSource>::New();
    lineSource2->SetPoint1(east2[p],north2[p],altitude2[p]);
    lineSource2->SetPoint2(east2[p],north2[p],altitude2[p]+depth2[p]);
    vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper2->SetInputConnection(lineSource2->GetOutputPort());    // 设置映射的渲染数据
    lineActor = vtkSmartPointer<vtkActor>::New();
    lineActor->GetProperty()->SetColor(0,0,1);
    lineActor->GetProperty()->SetLineWidth(3);
    lineActor->SetMapper(mapper2);
}
