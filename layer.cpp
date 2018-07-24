#include "layer.h"


Layer::Layer()
{
    //插入数据======================================================================================================
    points = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<m;i++)
    {
        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
    }

    //4，5，6岩性
    points2 = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<sortcount4;i++)
    {
        points2->InsertNextPoint(jeast4[i],jnorth4[i],jaltitude4[i]-100);
    }

    //第二层3
    points3 = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<sortcount3;i++)
    {
        points3->InsertNextPoint(jeast3[i],jnorth3[i],jaltitude3[i]-100);
    }
    //第二层4 红色
    points4 = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<sortcount4;i++)
    {
        points4->InsertNextPoint(jeast4[i],jnorth4[i],jaltitude4[i]-100);
    }
    //第二层5 绿色
    points5 = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<sortcount5;i++)
    {
        points2->InsertNextPoint(jeast5[i],jnorth5[i],jaltitude5[i]-100);
        points5->InsertNextPoint(jeast5[i],jnorth5[i],jaltitude5[i]-100);
    }
    //第二层6 蓝色
    points6 = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<sortcount6;i++)
    {
        points2->InsertNextPoint(jeast6[i],jnorth6[i],jaltitude6[i]-100);
    }


    //围边



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

    //4，5，6岩性
    polydata2 = vtkSmartPointer<vtkPolyData>::New();
    polydata2->SetPoints(points2);

    delaunay2 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay2->SetInputData(polydata2);
    delaunay2->Update();

//    glyphFilter2 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    glyphFilter2->SetInputData(polydata2);
//    glyphFilter2->Update();

//    pointsMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsMapper2->SetInputData(glyphFilter2->GetOutput());
//    pointsActor2 = vtkSmartPointer<vtkActor>::New();
//    pointsActor2->SetMapper(pointsMapper2);
//    pointsActor2->GetProperty()->SetPointSize(6);
//    pointsActor2->GetProperty()->SetColor(1, 0, 0);

    triangulatedMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper2->SetInputData(delaunay2->GetOutput());
    triangulatedActor2 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor2->SetMapper(triangulatedMapper2);
    triangulatedActor2->GetProperty()->SetOpacity(0.7);
    triangulatedActor2->GetProperty()->SetColor(0.3,1,0.8);

    //第二层岩性3
    polydata3 = vtkSmartPointer<vtkPolyData>::New();
    polydata3->SetPoints(points3);

    delaunay3 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay3->SetInputData(polydata3);
    delaunay3->Update();

//    glyphFilter3 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    glyphFilter3->SetInputData(polydata3);
//    glyphFilter3->Update();

//    pointsMapper3 = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsMapper3->SetInputData(glyphFilter3->GetOutput());
//    pointsActor3 = vtkSmartPointer<vtkActor>::New();
//    pointsActor3->SetMapper(pointsMapper3);
//    pointsActor3->GetProperty()->SetPointSize(getThickness);
//    pointsActor3->GetProperty()->SetColor(getdColorR, getdColorG, getdColorB);

    triangulatedMapper3 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper3->SetInputData(delaunay3->GetOutput());
    triangulatedActor3 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor3->SetMapper(triangulatedMapper3);
    triangulatedActor3->GetProperty()->SetOpacity(0.8);
    triangulatedActor3->GetProperty()->SetColor(0.4,0.5,0.8);

    //第二层岩性4
    polydata4 = vtkSmartPointer<vtkPolyData>::New();
    polydata4->SetPoints(points4);

    delaunay4 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay4->SetInputData(polydata4);
    delaunay4->Update();

//    glyphFilter4 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    glyphFilter4->SetInputData(polydata4);
//    glyphFilter4->Update();

//    pointsMapper4 = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsMapper4->SetInputData(glyphFilter4->GetOutput());
//    pointsActor4 = vtkSmartPointer<vtkActor>::New();
//    pointsActor4->SetMapper(pointsMapper4);
//    pointsActor4->GetProperty()->SetPointSize(6);
//    pointsActor4->GetProperty()->SetColor(1, 0, 0);

    triangulatedMapper4 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper4->SetInputData(delaunay4->GetOutput());
    triangulatedActor4 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor4->SetMapper(triangulatedMapper4);
    triangulatedActor4->GetProperty()->SetOpacity(0.5);
    triangulatedActor4->GetProperty()->SetColor(1,0,0);

    //第二层岩性5
    polydata5 = vtkSmartPointer<vtkPolyData>::New();
    polydata5->SetPoints(points5);

    delaunay5 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay5->SetInputData(polydata5);
    delaunay5->Update();

//    glyphFilter5 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    glyphFilter5->SetInputData(polydata5);
//    glyphFilter5->Update();

//    pointsMapper5 = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsMapper5->SetInputData(glyphFilter5->GetOutput());
//    pointsActor5 = vtkSmartPointer<vtkActor>::New();
//    pointsActor5->SetMapper(pointsMapper5);
//    pointsActor5->GetProperty()->SetPointSize(6);
//    pointsActor5->GetProperty()->SetColor(getdColorR, getdColorG, getdColorB);

    triangulatedMapper5 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper5->SetInputData(delaunay5->GetOutput());
    triangulatedActor5 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor5->SetMapper(triangulatedMapper5);
    triangulatedActor5->GetProperty()->SetOpacity(0.8);
    triangulatedActor5->GetProperty()->SetColor(0,1,0);

    //第二层岩性6
    polydata6 = vtkSmartPointer<vtkPolyData>::New();
    polydata6->SetPoints(points6);

    delaunay6 = vtkSmartPointer<vtkDelaunay2D>::New();
    delaunay6->SetInputData(polydata6);
    delaunay6->Update();

//    glyphFilter6 = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    glyphFilter6->SetInputData(polydata6);
//    glyphFilter6->Update();

//    pointsMapper6 = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsMapper6->SetInputData(glyphFilter6->GetOutput());
//    pointsActor6 = vtkSmartPointer<vtkActor>::New();
//    pointsActor6->SetMapper(pointsMapper6);
//    pointsActor6->GetProperty()->SetPointSize(getThickness);
//    pointsActor6->GetProperty()->SetColor(getdColorR, getdColorG, getdColorB);

    triangulatedMapper6 = vtkSmartPointer<vtkPolyDataMapper>::New();
    triangulatedMapper6->SetInputData(delaunay6->GetOutput());
    triangulatedActor6 = vtkSmartPointer<vtkActor>::New();
    triangulatedActor6->SetMapper(triangulatedMapper6);
    triangulatedActor6->GetProperty()->SetOpacity(0.8);
    triangulatedActor6->GetProperty()->SetColor(0,0,1);

    //显示编码================================================================================================
    for(int i = 0; i<m; i++)
    {
        textPropertys.push_back(vtkSmartPointer<vtkTextProperty>::New());
        textActors.push_back(vtkSmartPointer<vtkTextActor3D>::New());
        QString str = QString::number(i,10,0)+","+jborehole[i]+"\n"+"("+QString::number(east1[i],10,2)+","+QString::number(north1[i],10,2)+","+QString::number(altitude1[i],10,2)+")";
        textActors[i]->SetInput(str.toLatin1().data());
        textActors[i]->SetTextProperty(textPropertys[i]);
        textActors[i]->GetTextProperty()->SetFontFamily(20);
        textActors[i]->GetTextProperty()->SetFontSize(10); // 设置字体大小
        textActors[i]->SetPosition(east1[i],north1[i],altitude1[i]); // 设置编码位置
        textActors[i]->GetTextProperty()->SetColor(0, 0, 1); // 设置编码颜色
        textActors[i]->SetScale(0.2 ,0.2, 0.2); //设置文字大小
    }

    //围边===================================================================================================

}

Layer::~Layer()
{
}
