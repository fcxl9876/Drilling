#ifndef LINE_H
#define LINE_H

#include "odbchelper.h"

#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkLine.h>
#include <vtkFloatArray.h>
#include <vtkCellData.h>
#include <vtkLineSource.h>
#include <vtkProperty.h>
#include <vtkActor.h>


class Line
{
public:
    Line();
    std::vector<vtkSmartPointer<vtkActor> > L1_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L1_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L2_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L2_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L2_3lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L3_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L3_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L3_3lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L4_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L4_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L5_1_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L5_1_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L5_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L5_3lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L5_4lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L6lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L7_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L7_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L8_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L8_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L9_1lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L9_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L10lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L11lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L12lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L13lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L13_2lineActors;
    std::vector<vtkSmartPointer<vtkActor> > L14lineActors;
    std::vector<vtkSmartPointer<vtkActor> > chazhilineActors;
    std::vector<vtkSmartPointer<vtkActor> > bujialayerlineActors;

    std::vector<vtkSmartPointer<vtkLineSource> > L1_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L1_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L2_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L2_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L2_3lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L3_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L3_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L3_3lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L4_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L4_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L5_1_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L5_1_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L5_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L5_3lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L5_4lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L6lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L7_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L7_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L8_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L8_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L9_1lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L9_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L10lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L11lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L12lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L13lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L13_2lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > L14lineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > chazhilineSources;
    std::vector<vtkSmartPointer<vtkLineSource> > bujialayerlineSources;

    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L1_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L1_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L2_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L2_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L2_3lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L3_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L3_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L3_3lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L4_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L4_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L5_1_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L5_1_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L5_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L5_3lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L5_4lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L6lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L7_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L7_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L8_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L8_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L9_1lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L9_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L10lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L11lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L12lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L13lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L13_2lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > L14lineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > chazhilineMappers;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > bujialayerlineMappers;
};

#endif // LINE_H
