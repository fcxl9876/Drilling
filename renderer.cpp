#include "renderer.h"
#include "layer.h"
#include "line.h"
#include "odbchelper.h"

int k = 0;

Renderer::Renderer()
{
    //读取数据=========================================================
    odbchelper sql;
    int m = sql.getdatacount1();
    int n = sql.getdatacount2();

    Layer layer;
//    Line line;
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(layer.pointsActor);
    renderer->AddActor(layer.triangulatedActor);
    renderer->SetBackground(0, 0, 0);
//    renderer->AddActor(line.lineActor);
    for(k = 0; k<m; k++)
    {
        Line line;
        renderer->AddActor(line.lineActor);
    }
}
