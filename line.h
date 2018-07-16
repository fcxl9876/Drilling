#ifndef LINE_H
#define LINE_H

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
    vtkSmartPointer<vtkPolyDataMapper> mapper;
    vtkSmartPointer<vtkActor> lineActor1;
    vtkSmartPointer<vtkActor> lineActor2;

    vtkSmartPointer<vtkPoints> points;
};

#endif // LINE_H
