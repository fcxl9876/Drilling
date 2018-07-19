#include "layer.h"


Layer::Layer()
{
    //插入数据==================================================================
    points = vtkSmartPointer<vtkPoints>::New();
    for(int i=0;i<m;i++)
    {
        points->InsertNextPoint(east1[i],north1[i],altitude1[i]);
    }
    for(int i=0;i<n;i++)
    {
        points->InsertNextPoint(east2[i],north2[i],altitude2[i]);
    }

    //三角剖分建立地层============================================================
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

    //显示编码===============================================================
    for(int i = 0; i<m; i++)
    {

                textVectors.push_back(vtkSmartPointer<vtkVectorText>::New());
                QString str = jborehole[i]+"\n"+"("+QString::number(east1[i],10,2)+","+QString::number(north1[i],10,2)+","+QString::number(altitude1[i],10,2)+")";
                textVectors[i]->SetText(str.toLatin1().data());

                textTransforms.push_back(vtkSmartPointer<vtkTransform>::New());
                textTransforms[i]->Translate(east1[i], north1[i], altitude1[i]);
                textTransforms[i]->Scale(getcSize, getcSize, getcSize);    //编码大小

                textTransformFilters.push_back(vtkSmartPointer<vtkTransformFilter>::New());
                textTransformFilters[i]->SetTransform(textTransforms[i]);
                textTransformFilters[i]->SetInputConnection(textVectors[i]->GetOutputPort());
                textAppendPolyDatas.push_back(vtkSmartPointer<vtkAppendPolyData>::New());
                textAppendPolyDatas[i]->AddInputConnection(textTransformFilters[i]->GetOutputPort());

                textPolyDataMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());
                textPolyDataMappers[i]->ImmediateModeRenderingOn();
                textPolyDataMappers[i]->SetInputConnection(textAppendPolyDatas[i]->GetOutputPort());
                textActors.push_back(vtkSmartPointer<vtkActor>::New());
                textActors[i]->SetMapper(textPolyDataMappers[i]);
                textActors[i]->GetProperty()->SetColor(getcColorR,getcColorG,getcColorB);      //编码颜色
                textActors[i]->GetProperty()->SetOpacity(getcOpacity);      //编码透明度

//        textSources.push_back(vtkSmartPointer<vtkTextSource>::New());
//        std::string str = jborehole[i].toStdString();
//        const char* ch = str.c_str();
//        textSources[i]->SetText(ch);
//        textSources[i]->SetForegroundColor(0,0,1);
//        textMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());
//        textMappers[i]->SetInputConnection(textSources[i]->GetOutputPort());
//        textActors.push_back(vtkSmartPointer<vtkActor>::New());
//        textActors[i]->SetMapper(textMappers[i]);
//        textActors[i]->SetPosition(east1[i],north1[i],altitude1[i]);



//        textPropertys.push_back(vtkSmartPointer<vtkTextProperty>::New());
//        textPropertys[i]->SetColor(1 ,1 ,0);
//        textPropertys[i]->SetFontSize(18);
//        textPropertys[i]->SetFontFamily(0);
//        textPropertys[i]->SetJustification(1);
//        textPropertys[i]->SetBold(1);
//        textPropertys[i]->SetItalic(1);
//        textPropertys[i]->SetShadow(0);
//        textActors.push_back(vtkSmartPointer<vtkTextActor3D>::New());
//        textActors[i]->SetInput("test");
//        textActors[i]->SetTextProperty(textPropertys[i]);
//        textActors[i]->SetPosition(east1[i],north1[i], altitude1[i]); //设置位置
//        textActors[i]->SetScale(0.3 ,0.3 , 0.3); //设置文字大小
//        textActors[i]->RotateX(180.0);//沿X轴旋转90度

    }

}

Layer::~Layer()
{
}
