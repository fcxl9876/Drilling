#ifndef LAYER_H
#define LAYER_H

#include "odbchelper.h"
#include "dialog.h"

#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkDelaunay2D.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkTextActor3D.h>
#include <vtkTextProperty.h>
#include <vtkVectorText.h>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkAppendPolyData.h>
#include <vtkTextProperty.h>
#include <vtkTextActor.h>

#include <vtkSurfaceReconstructionFilter.h>
#include <vtkContourFilter.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkActor.h>
#include <vtkPolyData.h>

class Layer
{
public:
    Layer();
    ~Layer();

    vtkSmartPointer<vtkPoints> points;
    vtkSmartPointer<vtkPolyData> polydata;
    vtkSmartPointer<vtkDelaunay2D> delaunay;
    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter;
    vtkSmartPointer<vtkPolyDataMapper> pointsMapper;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper;
    vtkSmartPointer<vtkActor> pointsActor;
    vtkSmartPointer<vtkActor> triangulatedActor;

    vtkSmartPointer<vtkPoints> points2;
    vtkSmartPointer<vtkPolyData> polydata2;
    vtkSmartPointer<vtkDelaunay2D> delaunay2;
    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter2;
    vtkSmartPointer<vtkPolyDataMapper> pointsMapper2;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper2;
    vtkSmartPointer<vtkActor> pointsActor2;
    vtkSmartPointer<vtkActor> triangulatedActor2;

    std::vector<vtkSmartPointer<vtkTextActor3D> > textActors;
    std::vector<vtkSmartPointer<vtkTextProperty> > textPropertys;
};


#endif // LAYER_H
