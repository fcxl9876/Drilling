#include "layer.h"

Layer::Layer()
{
    unsigned int gridSize = 196;
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (unsigned int x = 0; x < gridSize; x++)
    {
        for (unsigned int y = 0; y < gridSize; y++)
        {
            points->InsertNextPoint(x, y, vtkMath::Random(0.0, 2.0));
        }
    }

    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);

    vtkSmartPointer<vtkDelaunay2D> delaunay = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay->SetInputData(polydata);
    delaunay->Update();

    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    glyphFilter->SetInputData(polydata);
    glyphFilter->Update();

    vtkSmartPointer<vtkPolyDataMapper> pointsMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    pointsMapper->SetInputData(glyphFilter->GetOutput());
    vtkSmartPointer<vtkActor> pointsActor = vtkSmartPointer<vtkActor>::New();
    pointsActor->SetMapper(pointsMapper);
    pointsActor->GetProperty()->SetPointSize(1);
    pointsActor->GetProperty()->SetColor(0, 1, 0);

    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper->SetInputData(delaunay->GetOutput());
    vtkSmartPointer<vtkActor> triangulatedActor = vtkSmartPointer<vtkActor>::New();
    triangulatedActor->SetMapper(triangulatedMapper);
    triangulatedActor->GetProperty()->SetOpacity(0.1);
    triangulatedActor->GetProperty()->SetColor(0,1,0);

    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(0,0,0);
    lineSource->SetPoint2(0,200,0);
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(lineSource->GetOutputPort());    // 设置映射的渲染数据
    vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
    lineActor->GetProperty()->SetColor(1,0,0);
    lineActor->SetMapper(mapper);

    //renderer renderWindow renderWindowInteractor
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(pointsActor);
    renderer->AddActor(triangulatedActor);
    renderer->AddActor(lineActor);
    renderer->SetBackground(0, 0, 0);

//    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
//    renderWindow->AddRenderer(renderer);
//    renderWindow->SetSize(640, 640);
//    renderWindow->Render();
//    renderWindow->SetWindowName("PolyData Delaunay2D");

//    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    renderWindowInteractor->SetRenderWindow(renderWindow);
//    renderWindowInteractor->Start();

}

Layer::~Layer()
{
}
