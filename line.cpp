#include "line.h"

Line::Line()
{
    //实际孔迹线===============================================================================

    //L1_1层
    for(int i = 0; i<L1_1; i++)
    {
        L1_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L1_1lineSources
        L1_1lineSources[i]->SetPoint1(jeastfromL1_1[i],jnorthfromL1_1[i],jaltitudefromL1_1[i]);
        L1_1lineSources[i]->SetPoint2(jeasttoL1_1[i],jnorthtoL1_1[i],jaltitudetoL1_1[i]);

        L1_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L1_1lineMappers
        L1_1lineMappers[i]->SetInputConnection(L1_1lineSources[i]->GetOutputPort());

        L1_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L1_1lineActors
        L1_1lineActors[i]->SetMapper(L1_1lineMappers[i]);
        L1_1lineActors[i]->GetProperty()->SetColor(0,1,0);  //孔迹线的属性
        L1_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L1-2层
    for(int i = 0; i<L1_2; i++)
    {
        L1_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L1_2lineSources
        L1_2lineSources[i]->SetPoint1(jeastfromL1_2[i],jnorthfromL1_2[i],jaltitudefromL1_2[i]);
        L1_2lineSources[i]->SetPoint2(jeasttoL1_2[i],jnorthtoL1_2[i],jaltitudetoL1_2[i]);

        L1_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L1_2lineMappers
        L1_2lineMappers[i]->SetInputConnection(L1_2lineSources[i]->GetOutputPort());

        L1_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L1_2lineActors
        L1_2lineActors[i]->SetMapper(L1_2lineMappers[i]);
        L1_2lineActors[i]->GetProperty()->SetColor(0,1,0);  //孔迹线的属性
        L1_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L2-1层
    for(int i = 0; i<L2_1; i++)
    {
        L2_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L2_1lineSources
        L2_1lineSources[i]->SetPoint1(jeastfromL2_1[i],jnorthfromL2_1[i],jaltitudefromL2_1[i]);
        L2_1lineSources[i]->SetPoint2(jeasttoL2_1[i],jnorthtoL2_1[i],jaltitudetoL2_1[i]);

        L2_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L2_1lineMappers
        L2_1lineMappers[i]->SetInputConnection(L2_1lineSources[i]->GetOutputPort());

        L2_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L2_1lineActors
        L2_1lineActors[i]->SetMapper(L2_1lineMappers[i]);
        L2_1lineActors[i]->GetProperty()->SetColor(1,1,0);  //孔迹线的属性
        L2_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }


    //L2_2层
    for(int i = 0; i<L2_2; i++)
    {
        L2_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L2_2lineSources
        L2_2lineSources[i]->SetPoint1(jeastfromL2_2[i],jnorthfromL2_2[i],jaltitudefromL2_2[i]);
        L2_2lineSources[i]->SetPoint2(jeasttoL2_2[i],jnorthtoL2_2[i],jaltitudetoL2_2[i]);

        L2_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L2_2lineMappers
        L2_2lineMappers[i]->SetInputConnection(L2_2lineSources[i]->GetOutputPort());

        L2_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L2_2lineActors
        L2_2lineActors[i]->SetMapper(L2_2lineMappers[i]);
        L2_2lineActors[i]->GetProperty()->SetColor(1,0,1);  //孔迹线的属性
        L2_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L2_3层
    for(int i = 0; i<L2_3; i++)
    {
        L2_3lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L2_3lineSources
        L2_3lineSources[i]->SetPoint1(jeastfromL2_3[i],jnorthfromL2_3[i],jaltitudefromL2_3[i]);
        L2_3lineSources[i]->SetPoint2(jeasttoL2_3[i],jnorthtoL2_3[i],jaltitudetoL2_3[i]);

        L2_3lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L2_3lineMappers
        L2_3lineMappers[i]->SetInputConnection(L2_3lineSources[i]->GetOutputPort());

        L2_3lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L2_3lineActors
        L2_3lineActors[i]->SetMapper(L2_3lineMappers[i]);
        L2_3lineActors[i]->GetProperty()->SetColor(0,1,1);  //孔迹线的属性
        L2_3lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L3_1层
    for(int i = 0; i<L3_1; i++)
    {
        L3_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L3_1lineSources
        L3_1lineSources[i]->SetPoint1(jeastfromL3_1[i],jnorthfromL3_1[i],jaltitudefromL3_1[i]);
        L3_1lineSources[i]->SetPoint2(jeasttoL3_1[i],jnorthtoL3_1[i],jaltitudetoL3_1[i]);

        L3_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L3_1lineMappers
        L3_1lineMappers[i]->SetInputConnection(L3_1lineSources[i]->GetOutputPort());

        L3_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L3_1lineActors
        L3_1lineActors[i]->SetMapper(L3_1lineMappers[i]);
        L3_1lineActors[i]->GetProperty()->SetColor(0.5,0,0);  //孔迹线的属性
        L3_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L3_2层
    for(int i = 0; i<L3_2; i++)
    {
        L3_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L3_2lineSources
        L3_2lineSources[i]->SetPoint1(jeastfromL3_2[i],jnorthfromL3_2[i],jaltitudefromL3_2[i]);
        L3_2lineSources[i]->SetPoint2(jeasttoL3_2[i],jnorthtoL3_2[i],jaltitudetoL3_2[i]);

        L3_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L3_2lineMappers
        L3_2lineMappers[i]->SetInputConnection(L3_2lineSources[i]->GetOutputPort());

        L3_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L3_2lineActors
        L3_2lineActors[i]->SetMapper(L3_2lineMappers[i]);
        L3_2lineActors[i]->GetProperty()->SetColor(0,0.5,0);  //孔迹线的属性
        L3_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L3_3层
    for(int i = 0; i<L3_3; i++)
    {
        L3_3lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L3_3lineSources
        L3_3lineSources[i]->SetPoint1(jeastfromL3_3[i],jnorthfromL3_3[i],jaltitudefromL3_3[i]);
        L3_3lineSources[i]->SetPoint2(jeasttoL3_3[i],jnorthtoL3_3[i],jaltitudetoL3_3[i]);

        L3_3lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L3_3lineMappers
        L3_3lineMappers[i]->SetInputConnection(L3_3lineSources[i]->GetOutputPort());

        L3_3lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L3_3lineActors
        L3_3lineActors[i]->SetMapper(L3_3lineMappers[i]);
        L3_3lineActors[i]->GetProperty()->SetColor(0,0,0.5);  //孔迹线的属性
        L3_3lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L4_1层
    for(int i = 0; i<L4_1; i++)
    {
        L4_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L4_1lineSources
        L4_1lineSources[i]->SetPoint1(jeastfromL4_1[i],jnorthfromL4_1[i],jaltitudefromL4_1[i]);
        L4_1lineSources[i]->SetPoint2(jeasttoL4_1[i],jnorthtoL4_1[i],jaltitudetoL4_1[i]);

        L4_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L4_1lineMappers
        L4_1lineMappers[i]->SetInputConnection(L4_1lineSources[i]->GetOutputPort());

        L4_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L4_1lineActors
        L4_1lineActors[i]->SetMapper(L4_1lineMappers[i]);
        L4_1lineActors[i]->GetProperty()->SetColor(0.5,0.5,0);  //孔迹线的属性
        L4_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L4_2层
    for(int i = 0; i<L4_2; i++)
    {
        L4_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L4_2lineSources
        L4_2lineSources[i]->SetPoint1(jeastfromL4_2[i],jnorthfromL4_2[i],jaltitudefromL4_2[i]);
        L4_2lineSources[i]->SetPoint2(jeasttoL4_2[i],jnorthtoL4_2[i],jaltitudetoL4_2[i]);

        L4_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L4_2lineMappers
        L4_2lineMappers[i]->SetInputConnection(L4_2lineSources[i]->GetOutputPort());

        L4_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L4_2lineActors
        L4_2lineActors[i]->SetMapper(L4_2lineMappers[i]);
        L4_2lineActors[i]->GetProperty()->SetColor(0.5,0,0.5);  //孔迹线的属性
        L4_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L5_1_1层
    for(int i = 0; i<L5_1_1; i++)
    {
        L5_1_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L5_1_1lineSources
        L5_1_1lineSources[i]->SetPoint1(jeastfromL5_1_1[i],jnorthfromL5_1_1[i],jaltitudefromL5_1_1[i]);
        L5_1_1lineSources[i]->SetPoint2(jeasttoL5_1_1[i],jnorthtoL5_1_1[i],jaltitudetoL5_1_1[i]);

        L5_1_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L5_1_1lineMappers
        L5_1_1lineMappers[i]->SetInputConnection(L5_1_1lineSources[i]->GetOutputPort());

        L5_1_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L5_1_1lineActors
        L5_1_1lineActors[i]->SetMapper(L5_1_1lineMappers[i]);
        L5_1_1lineActors[i]->GetProperty()->SetColor(0,0.5,0.5);  //孔迹线的属性
        L5_1_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L5_1_2层
    for(int i = 0; i<L5_1_2; i++)
    {
        L5_1_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L5_1_2lineSources
        L5_1_2lineSources[i]->SetPoint1(jeastfromL5_1_2[i],jnorthfromL5_1_2[i],jaltitudefromL5_1_2[i]);
        L5_1_2lineSources[i]->SetPoint2(jeasttoL5_1_2[i],jnorthtoL5_1_2[i],jaltitudetoL5_1_2[i]);

        L5_1_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L5_1_2lineMappers
        L5_1_2lineMappers[i]->SetInputConnection(L5_1_2lineSources[i]->GetOutputPort());

        L5_1_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L5_1_2lineActors
        L5_1_2lineActors[i]->SetMapper(L5_1_2lineMappers[i]);
        L5_1_2lineActors[i]->GetProperty()->SetColor(0.75,0.75,0.75);  //孔迹线的属性
        L5_1_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L5_2层
    for(int i = 0; i<L5_2; i++)
    {
        L5_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L5_2lineSources
        L5_2lineSources[i]->SetPoint1(jeastfromL5_2[i],jnorthfromL5_2[i],jaltitudefromL5_2[i]);
        L5_2lineSources[i]->SetPoint2(jeasttoL5_2[i],jnorthtoL5_2[i],jaltitudetoL5_2[i]);

        L5_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L5_2lineMappers
        L5_2lineMappers[i]->SetInputConnection(L5_2lineSources[i]->GetOutputPort());

        L5_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L5_2lineActors
        L5_2lineActors[i]->SetMapper(L5_2lineMappers[i]);
        L5_2lineActors[i]->GetProperty()->SetColor(0.5,0.5,0.5);  //孔迹线的属性
        L5_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L5_3层
    for(int i = 0; i<L5_3; i++)
    {
        L5_3lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L5_3lineSources
        L5_3lineSources[i]->SetPoint1(jeastfromL5_3[i],jnorthfromL5_3[i],jaltitudefromL5_3[i]);
        L5_3lineSources[i]->SetPoint2(jeasttoL5_3[i],jnorthtoL5_3[i],jaltitudetoL5_3[i]);

        L5_3lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L5_3lineMappers
        L5_3lineMappers[i]->SetInputConnection(L5_3lineSources[i]->GetOutputPort());

        L5_3lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L5_3lineActors
        L5_3lineActors[i]->SetMapper(L5_3lineMappers[i]);
        L5_3lineActors[i]->GetProperty()->SetColor(0.6,0.6,1);  //孔迹线的属性
        L5_3lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L5_4层
    for(int i = 0; i<L5_4; i++)
    {
        L5_4lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L5_4lineSources
        L5_4lineSources[i]->SetPoint1(jeastfromL5_4[i],jnorthfromL5_4[i],jaltitudefromL5_4[i]);
        L5_4lineSources[i]->SetPoint2(jeasttoL5_4[i],jnorthtoL5_4[i],jaltitudetoL5_4[i]);

        L5_4lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L5_4lineMappers
        L5_4lineMappers[i]->SetInputConnection(L5_4lineSources[i]->GetOutputPort());

        L5_4lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L5_4lineActors
        L5_4lineActors[i]->SetMapper(L5_4lineMappers[i]);
        L5_4lineActors[i]->GetProperty()->SetColor(0.6,0.2,0.4);  //孔迹线的属性
        L5_4lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L6层
    for(int i = 0; i<L6; i++)
    {
        L6lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L6lineSources
        L6lineSources[i]->SetPoint1(jeastfromL6[i],jnorthfromL6[i],jaltitudefromL6[i]);
        L6lineSources[i]->SetPoint2(jeasttoL6[i],jnorthtoL6[i],jaltitudetoL6[i]);

        L6lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L6lineMappers
        L6lineMappers[i]->SetInputConnection(L6lineSources[i]->GetOutputPort());

        L6lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L6lineActors
        L6lineActors[i]->SetMapper(L6lineMappers[i]);
        L6lineActors[i]->GetProperty()->SetColor(1,1,0.8);  //孔迹线的属性
        L6lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L7_1层
    for(int i = 0; i<L7_1; i++)
    {
        L7_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L7_1lineSources
        L7_1lineSources[i]->SetPoint1(jeastfromL7_1[i],jnorthfromL7_1[i],jaltitudefromL7_1[i]);
        L7_1lineSources[i]->SetPoint2(jeasttoL7_1[i],jnorthtoL7_1[i],jaltitudetoL7_1[i]);

        L7_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L7_1lineMappers
        L7_1lineMappers[i]->SetInputConnection(L7_1lineSources[i]->GetOutputPort());

        L7_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L7_1lineActors
        L7_1lineActors[i]->SetMapper(L7_1lineMappers[i]);
        L7_1lineActors[i]->GetProperty()->SetColor(0.8,1,1);  //孔迹线的属性
        L7_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L7_2层
    for(int i = 0; i<L7_2; i++)
    {
        L7_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L7_2lineSources
        L7_2lineSources[i]->SetPoint1(jeastfromL7_2[i],jnorthfromL7_2[i],jaltitudefromL7_2[i]);
        L7_2lineSources[i]->SetPoint2(jeasttoL7_2[i],jnorthtoL7_2[i],jaltitudetoL7_2[i]);

        L7_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L7_2lineMappers
        L7_2lineMappers[i]->SetInputConnection(L7_2lineSources[i]->GetOutputPort());

        L7_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L7_2lineActors
        L7_2lineActors[i]->SetMapper(L7_2lineMappers[i]);
        L7_2lineActors[i]->GetProperty()->SetColor(0.4,0,0.4);  //孔迹线的属性
        L7_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L8_1层
    for(int i = 0; i<L8_1; i++)
    {
        L8_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L8_1lineSources
        L8_1lineSources[i]->SetPoint1(jeastfromL8_1[i],jnorthfromL8_1[i],jaltitudefromL8_1[i]);
        L8_1lineSources[i]->SetPoint2(jeasttoL8_1[i],jnorthtoL8_1[i],jaltitudetoL8_1[i]);

        L8_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L8_1lineMappers
        L8_1lineMappers[i]->SetInputConnection(L8_1lineSources[i]->GetOutputPort());

        L8_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L8_1lineActors
        L8_1lineActors[i]->SetMapper(L8_1lineMappers[i]);
        L8_1lineActors[i]->GetProperty()->SetColor(1,0.5,0.5);  //孔迹线的属性
        L8_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L8_2层
    for(int i = 0; i<L8_2; i++)
    {
        L8_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L8_2lineSources
        L8_2lineSources[i]->SetPoint1(jeastfromL8_2[i],jnorthfromL8_2[i],jaltitudefromL8_2[i]);
        L8_2lineSources[i]->SetPoint2(jeasttoL8_2[i],jnorthtoL8_2[i],jaltitudetoL8_2[i]);

        L8_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L8_2lineMappers
        L8_2lineMappers[i]->SetInputConnection(L8_2lineSources[i]->GetOutputPort());

        L8_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L8_2lineActors
        L8_2lineActors[i]->SetMapper(L8_2lineMappers[i]);
        L8_2lineActors[i]->GetProperty()->SetColor(1,0.4,0.8);  //孔迹线的属性
        L8_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L9_1层
    for(int i = 0; i<L9_1; i++)
    {
        L9_1lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L9_1lineSources
        L9_1lineSources[i]->SetPoint1(jeastfromL9_1[i],jnorthfromL9_1[i],jaltitudefromL9_1[i]);
        L9_1lineSources[i]->SetPoint2(jeasttoL9_1[i],jnorthtoL9_1[i],jaltitudetoL9_1[i]);

        L9_1lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L9_1lineMappers
        L9_1lineMappers[i]->SetInputConnection(L9_1lineSources[i]->GetOutputPort());

        L9_1lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L9_1lineActors
        L9_1lineActors[i]->SetMapper(L9_1lineMappers[i]);
        L9_1lineActors[i]->GetProperty()->SetColor(0.8,0.8,0.8);  //孔迹线的属性
        L9_1lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L9_2层
    for(int i = 0; i<L9_2; i++)
    {
        L9_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L9_2lineSources
        L9_2lineSources[i]->SetPoint1(jeastfromL9_2[i],jnorthfromL9_2[i],jaltitudefromL9_2[i]);
        L9_2lineSources[i]->SetPoint2(jeasttoL9_2[i],jnorthtoL9_2[i],jaltitudetoL9_2[i]);

        L9_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L9_2lineMappers
        L9_2lineMappers[i]->SetInputConnection(L9_2lineSources[i]->GetOutputPort());

        L9_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L9_2lineActors
        L9_2lineActors[i]->SetMapper(L9_2lineMappers[i]);
        L9_2lineActors[i]->GetProperty()->SetColor(0.2,0.4,1);  //孔迹线的属性
        L9_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L10层
    for(int i = 0; i<L10; i++)
    {
        L10lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L10lineSources
        L10lineSources[i]->SetPoint1(jeastfromL10[i],jnorthfromL10[i],jaltitudefromL10[i]);
        L10lineSources[i]->SetPoint2(jeasttoL10[i],jnorthtoL10[i],jaltitudetoL10[i]);

        L10lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L10lineMappers
        L10lineMappers[i]->SetInputConnection(L10lineSources[i]->GetOutputPort());

        L10lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L10lineActors
        L10lineActors[i]->SetMapper(L10lineMappers[i]);
        L10lineActors[i]->GetProperty()->SetColor(1,0,1);  //孔迹线的属性
        L10lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L11层
    for(int i = 0; i<L11; i++)
    {
        L11lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L11lineSources
        L11lineSources[i]->SetPoint1(jeastfromL11[i],jnorthfromL11[i],jaltitudefromL11[i]);
        L11lineSources[i]->SetPoint2(jeasttoL11[i],jnorthtoL11[i],jaltitudetoL11[i]);

        L11lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L11lineMappers
        L11lineMappers[i]->SetInputConnection(L11lineSources[i]->GetOutputPort());

        L11lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L11lineActors
        L11lineActors[i]->SetMapper(L11lineMappers[i]);
        L11lineActors[i]->GetProperty()->SetColor(1,1,0);  //孔迹线的属性
        L11lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L12层
    for(int i = 0; i<L12; i++)
    {
        L12lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L12lineSources
        L12lineSources[i]->SetPoint1(jeastfromL12[i],jnorthfromL12[i],jaltitudefromL12[i]);
        L12lineSources[i]->SetPoint2(jeasttoL12[i],jnorthtoL12[i],jaltitudetoL12[i]);

        L12lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L12lineMappers
        L12lineMappers[i]->SetInputConnection(L12lineSources[i]->GetOutputPort());

        L12lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L12lineActors
        L12lineActors[i]->SetMapper(L12lineMappers[i]);
        L12lineActors[i]->GetProperty()->SetColor(0.2,0.8,0.8);  //孔迹线的属性
        L12lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L13层
    for(int i = 0; i<L13; i++)
    {
        L13lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L13lineSources
        L13lineSources[i]->SetPoint1(jeastfromL13[i],jnorthfromL13[i],jaltitudefromL13[i]);
        L13lineSources[i]->SetPoint2(jeasttoL13[i],jnorthtoL13[i],jaltitudetoL13[i]);

        L13lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L13lineMappers
        L13lineMappers[i]->SetInputConnection(L13lineSources[i]->GetOutputPort());

        L13lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L13lineActors
        L13lineActors[i]->SetMapper(L13lineMappers[i]);
        L13lineActors[i]->GetProperty()->SetColor(0.6,0.8,0);  //孔迹线的属性
        L13lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L13_2层
    for(int i = 0; i<L13_2; i++)
    {
        L13_2lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L13_2lineSources
        L13_2lineSources[i]->SetPoint1(jeastfromL13_2[i],jnorthfromL13_2[i],jaltitudefromL13_2[i]);
        L13_2lineSources[i]->SetPoint2(jeasttoL13_2[i],jnorthtoL13_2[i],jaltitudetoL13_2[i]);

        L13_2lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L13_2lineMappers
        L13_2lineMappers[i]->SetInputConnection(L13_2lineSources[i]->GetOutputPort());

        L13_2lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L13_2lineActors
        L13_2lineActors[i]->SetMapper(L13_2lineMappers[i]);
        L13_2lineActors[i]->GetProperty()->SetColor(0.2,0.4,1);  //孔迹线的属性
        L13_2lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //L14层
    for(int i = 0; i<L14; i++)
    {
        L14lineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //L14lineSources
        L14lineSources[i]->SetPoint1(jeastfromL14[i],jnorthfromL14[i],jaltitudefromL14[i]);
        L14lineSources[i]->SetPoint2(jeasttoL14[i],jnorthtoL14[i],jaltitudetoL14[i]);

        L14lineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //L14lineMappers
        L14lineMappers[i]->SetInputConnection(L14lineSources[i]->GetOutputPort());

        L14lineActors.push_back(vtkSmartPointer<vtkActor>::New()); //L14lineActors
        L14lineActors[i]->SetMapper(L14lineMappers[i]);
        L14lineActors[i]->GetProperty()->SetColor(1,0.8,0);  //孔迹线的属性
        L14lineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //chazhi层
    for(int i = 0; i<chazhi; i++)
    {
        chazhilineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //chazhilineSources
        chazhilineSources[i]->SetPoint1(jeastfromchazhi[i],jnorthfromchazhi[i],jaltitudefromchazhi[i]);
        chazhilineSources[i]->SetPoint2(jeasttochazhi[i],jnorthtochazhi[i],jaltitudetochazhi[i]);

        chazhilineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //chazhilineMappers
        chazhilineMappers[i]->SetInputConnection(chazhilineSources[i]->GetOutputPort());

        chazhilineActors.push_back(vtkSmartPointer<vtkActor>::New()); //chazhilineActors
        chazhilineActors[i]->SetMapper(chazhilineMappers[i]);
        chazhilineActors[i]->GetProperty()->SetColor(0.3,0.4,0.5);  //孔迹线的属性
        chazhilineActors[i]->GetProperty()->SetLineWidth(3);
    }

    //bujialayer层
    for(int i = 0; i<bujialayer; i++)
    {
        bujialayerlineSources.push_back(vtkSmartPointer<vtkLineSource>::New());   //bujialayerlineSources
        bujialayerlineSources[i]->SetPoint1(jeastfrombujialayer[i],jnorthfrombujialayer[i],jaltitudefrombujialayer[i]);
        bujialayerlineSources[i]->SetPoint2(jeasttobujialayer[i],jnorthtobujialayer[i],jaltitudetobujialayer[i]);

        bujialayerlineMappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());   //bujialayerlineMappers
        bujialayerlineMappers[i]->SetInputConnection(bujialayerlineSources[i]->GetOutputPort());

        bujialayerlineActors.push_back(vtkSmartPointer<vtkActor>::New()); //bujialayerlineActors
        bujialayerlineActors[i]->SetMapper(bujialayerlineMappers[i]);
        bujialayerlineActors[i]->GetProperty()->SetColor(0.5,0.4,1);  //孔迹线的属性
        bujialayerlineActors[i]->GetProperty()->SetLineWidth(3);
    }
}
