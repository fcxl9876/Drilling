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

    //实际孔迹线actor==================================================
    //L1-1层actor
    for(int i = 0; i<L1_1; i++)
    {
        renderer->AddActor(line.lineActors[i]);
    }
    //L2-1层actor


    //虚拟孔迹线actor==================================================
//    for(int i = 0; i<n; i++)
//    {
//        renderer->AddActor(virtualLine.virtualLineActors[i]);
//    }

}
//显示和隐藏钻孔
void Renderer::viewDrilling()
{
    renderer->AddActor(layer.pointsActor);
}
void Renderer::hideDrilling()
{
    renderer->RemoveActor(layer.pointsActor);
}
