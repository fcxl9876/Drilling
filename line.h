#ifndef LINE_H
#define LINE_H

#include "odbchelper.h"
#include "renderer.h"

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkLine.h>
#include <vtkFloatArray.h>
#include <vtkCellData.h>
#include <vtkLineSource.h>
#include <vtkProperty.h>


class Line
{
public:
    Line();
    std::vector<vtkSmartPointer<vtkActor> > lineActors;
    std::vector<vtkSmartPointer<vtkLineSource> > lineSources;
    std::vector<vtkSmartPointer<vtkPolyDataMapper> > lineMappers;
};

#endif // LINE_H
