#include "renderer.h"
#include "layer.h"
#include "line.h"
#include "odbchelper.h"
#include "virtualline.h"

int k = 0;
int p = 0;

Renderer::Renderer()
{
    //读取数据=========================================================
    odbchelper sql;

    Layer layer;
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(layer.pointsActor);
    renderer->AddActor(layer.triangulatedActor);
    renderer->SetBackground(0, 0, 0);

    for(k = 0; k<m; k++)
    {
        Line line;
        renderer->AddActor(line.lineActor1);
        renderer->AddActor(line.lineActor2);
    }
    for(p = 0; p<n; p++)
    {
        VirtualLine line2;
        renderer->AddActor(line2.lineActor);
    }
}
