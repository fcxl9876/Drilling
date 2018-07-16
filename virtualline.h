#ifndef VIRTUALLINE_H
#define VIRTUALLINE_H

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

class VirtualLine
{
public:
    VirtualLine();
    vtkSmartPointer<vtkPolyDataMapper> mapper;
    vtkSmartPointer<vtkActor> lineActor;

    vtkSmartPointer<vtkPoints> points;
};

#endif // VIRTUALLINE_H
