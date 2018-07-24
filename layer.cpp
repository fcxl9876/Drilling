#include "layer.h"


Layer::Layer()
{
    //插入数据======================================================================================================
    points = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<m;i++)
    {
        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
    }
    points2 = vtkSmartPointer<vtkPoints>::New();
//    for(int i=0;i<sortcount2;i++)
//    {
//        points2->InsertNextPoint(jeast2[i],jnorth2[i],jaltitude2[i]-100);
//    }


    //三角剖分建立地层========================================================================================
    polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);

    delaunay = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay->SetInputData(polydata);
    delaunay->Update();

    glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    glyphFilter->SetInputData(polydata);
    glyphFilter->Update();

    pointsMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    pointsMapper->SetInputData(glyphFilter->GetOutput());
    pointsActor = vtkSmartPointer<vtkActor>::New();
    pointsActor->SetMapper(pointsMapper);
    pointsActor->GetProperty()->SetPointSize(getThickness);
    pointsActor->GetProperty()->SetColor(getdColorR, getdColorG, getdColorB);

    triangulatedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper->SetInputData(delaunay->GetOutput());
    triangulatedActor = vtkSmartPointer<vtkActor>::New();
    triangulatedActor->SetMapper(triangulatedMapper);
    triangulatedActor->GetProperty()->SetOpacity(0.8);
    triangulatedActor->GetProperty()->SetColor(0,0.8,0.4);

    //第二层
    polydata2 = vtkSmartPointer<vtkPolyData>::New();
    polydata2->SetPoints(points2);

    delaunay2 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay2->SetInputData(polydata2);
    delaunay2->Update();

    glyphFilter2 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    glyphFilter2->SetInputData(polydata2);
    glyphFilter2->Update();

    pointsMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    pointsMapper2->SetInputData(glyphFilter2->GetOutput());
    pointsActor2 = vtkSmartPointer<vtkActor>::New();
    pointsActor2->SetMapper(pointsMapper2);
    pointsActor2->GetProperty()->SetPointSize(getThickness);
    pointsActor2->GetProperty()->SetColor(getdColorR, getdColorG, getdColorB);

    triangulatedMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper2->SetInputData(delaunay2->GetOutput());
    triangulatedActor2 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor2->SetMapper(triangulatedMapper2);
    triangulatedActor2->GetProperty()->SetOpacity(0.8);
    triangulatedActor2->GetProperty()->SetColor(0.5,0.8,0.4);
    //显示编码================================================================================================
    for(int i = 0; i<m; i++)
    {
        textPropertys.push_back(vtkSmartPointer<vtkTextProperty>::New());
        textActors.push_back(vtkSmartPointer<vtkTextActor3D>::New());
        QString str = QString::number(i,10,2)+" "+jborehole[i]+"\n"+"("+QString::number(east1[i],10,2)+","+QString::number(north1[i],10,2)+","+QString::number(altitude1[i],10,2)+")";
        textActors[i]->SetInput(str.toLatin1().data());
        textActors[i]->SetTextProperty(textPropertys[i]);
        textActors[i]->GetTextProperty()->SetFontFamily(20);
        textActors[i]->GetTextProperty()->SetFontSize(10); // 设置字体大小
        textActors[i]->SetPosition(east1[i],north1[i],altitude1[i]); // 设置编码位置
        textActors[i]->GetTextProperty()->SetColor(0, 0, 1); // 设置编码颜色
        textActors[i]->SetScale(0.2 ,0.2, 0.2); //设置文字大小
    }

}

Layer::~Layer()
{
}
