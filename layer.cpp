#include "layer.h"
#include "odbchelper.h"

Layer::Layer()
{
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

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

    for(int i=0;i<m;i++){
        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
    }

    for(int i=0;i<n;i++){
        points->InsertNextPoint(east2[i],north2[i],altitude2[i]);
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
    pointsActor->GetProperty()->SetPointSize(3);
    pointsActor->GetProperty()->SetColor(0, 1, 0);

    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper->SetInputData(delaunay->GetOutput());
    vtkSmartPointer<vtkActor> triangulatedActor = vtkSmartPointer<vtkActor>::New();
    triangulatedActor->SetMapper(triangulatedMapper);
    triangulatedActor->GetProperty()->SetOpacity(0.5);
    triangulatedActor->GetProperty()->SetColor(0,1,0);

    //画线
//    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
//    lineSource->SetPoint1(2227.33,4041.28,0);
//    lineSource->SetPoint2(2227.33,4041.28,49.95);
//    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    mapper->SetInputConnection(lineSource->GetOutputPort());    // 设置映射的渲染数据
//    vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
//    lineActor->GetProperty()->SetColor(1,0,0);
//    lineActor->GetProperty()->SetLineWidth(3);
//    lineActor->SetMapper(mapper);


    vtkSmartPointer<vtkLineSource> *lineSource = new vtkSmartPointer<vtkLineSource>[m];
    vtkSmartPointer<vtkPolyDataMapper> *lineMapper = new vtkSmartPointer<vtkPolyDataMapper>[m];
    vtkSmartPointer<vtkActor> *lineActor = new vtkSmartPointer<vtkActor>[m];


    for(int i = 0; i<m; i++)
    {
        lineSource[i]->SetPoint1(east1[i],north1[i],altitude1[i]);
        lineSource[i]->SetPoint2(east1[i],north1[i],altitude1[i]+depth1[i]);
        lineMapper[i]->SetInputConnection(lineSource[i]->GetOutputPort());    // 设置映射的渲染数据
        lineActor[i]->GetProperty()->SetColor(1,0,0);
        lineActor[i]->SetMapper(lineMapper[i]);
    }



    //renderer renderWindow renderWindowInteractor
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(pointsActor);
    renderer->AddActor(triangulatedActor);
    renderer->SetBackground(0, 0, 0);
//    renderer->AddActor(lineActor);
    for(int i = 0; i<m; i++)
    {
        renderer->AddActor(lineActor[i]);
    }



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
