#include "line.h"

Line::Line()
{
    //实际孔迹线===============================================================================
    for(int i = 0; i<L1_1; i++)
    {
        lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //lineSources
        lineSources[i]->SetPoint1(jeastfromL1_1[i],jnorthfromL1_1[i],jaltitudefromL1_1[i]);
        lineSources[i]->SetPoint2(jeasttoL1_1[i],jnorthtoL1_1[i],jaltitudetoL1_1[i]);

        lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //lineMappers
        lineMappers[i]->SetInputConnection(lineSources[i]->GetOutputPort());

        lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //lineActors
        lineActors[i]->SetMapper(lineMappers[i]);
        lineActors[i]->GetProperty()->SetColor(0,1,0);  //孔迹线的属性
        lineActors[i]->GetProperty()->SetLineWidth(3);
    }

}
