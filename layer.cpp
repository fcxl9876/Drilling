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

    //画线===============================================================================

//    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
//    lineSource->SetPoint1(2227.33,4041.28,0);
//    lineSource->SetPoint2(2227.33,4041.28,49.95);
//    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    mapper->SetInputConnection(lineSource->GetOutputPort());    // 设置映射的渲染数据
//    vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
//    lineActor->GetProperty()->SetColor(1,0,0);
//    lineActor->GetProperty()->SetLineWidth(3);
//    lineActor->SetMapper(mapper);


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

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(linesPolyData);
    vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
    lineActor->SetMapper(mapper);




    //renderer renderWindow renderWindowInteractor
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(pointsActor);
    renderer->AddActor(triangulatedActor);
    renderer->SetBackground(0, 0, 0);
    renderer->AddActor(lineActor);


//END 画线================================================================================




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
