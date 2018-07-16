#include "renderer.h"
#include "layer.h"
#include "line.h"

Renderer::Renderer()
{
    Layer layer;
    Line line;
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(layer.pointsActor);
    renderer->AddActor(layer.triangulatedActor);
    renderer->SetBackground(0, 0, 0);
    renderer->AddActor(line.lineActor);
}
