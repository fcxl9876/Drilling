#include "renderer.h"

Renderer::Renderer()
{
    Line line;
    VirtualLine virtualLine;

    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->SetBackground(0, 0, 0);

    //将Actors添加到renderer里=========================================
    renderer->AddActor(layer.pointsActor);
    renderer->AddActor(layer.triangulatedActor);
    for(int i = 0; i<m; i++)
    {
        renderer->AddActor(line.lineActors[i]);
    }
    for(int i = 0; i<n; i++)
    {
        renderer->AddActor(virtualLine.virtualLineActors[i]);
    }

}
