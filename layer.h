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
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkTextActor3D.h>
#include <vtkTextProperty.h>

#include <vtkVectorText.h>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkAppendPolyData.h>


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

//    std::vector<vtkSmartPointer<vtkTextActor3D> > textActors;
//    std::vector<vtkSmartPointer<vtkTextProperty> > textPropertys;

//    std::vector<vtkSmartPointer<vtkTextSource> > textSources;
//    std::vector<vtkSmartPointer<vtkPolyDataMapper> > textMappers;
//    std::vector<vtkSmartPointer<vtkActor> > textActors;

        std::vector<vtkSmartPointer<vtkVectorText> > textVectors;
        std::vector<vtkSmartPointer<vtkTransform> > textTransforms;
        std::vector<vtkSmartPointer<vtkTransformFilter> > textTransformFilters;
        std::vector<vtkSmartPointer<vtkPolyData> > textPolyDatas;
        std::vector<vtkSmartPointer<vtkPolyDataMapper> > textPolyDataMappers;
        std::vector<vtkSmartPointer<vtkActor> > textActors;
        std::vector<vtkSmartPointer<vtkAppendPolyData> > textAppendPolyDatas;

};


#endif // LAYER_H
