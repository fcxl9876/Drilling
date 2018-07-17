#include "line.h"

Line::Line()
{
    //实际孔迹线===============================================================================
    for(int i = 0; i<m; i++)
    {
        lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //lineSources
        lineSources[i]->SetPoint1(east1[i],north1[i],altitude1[i]);
        lineSources[i]->SetPoint2(east1[i],north1[i],altitude1[i]+depth1[i]);

        lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //lineMappers
        lineMappers[i]->SetInputConnection(lineSources[i]->GetOutputPort());

        lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //lineActors
        lineActors[i]->SetMapper(lineMappers[i]);
        lineActors[i]->GetProperty()->SetColor(1,0,0);  //孔迹线的属性
        lineActors[i]->GetProperty()->SetLineWidth(3);
    }

}
