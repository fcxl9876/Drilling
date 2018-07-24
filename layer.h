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
//围边
#include <vtkPlaneSource.h>
#include <vtkFloatArray.h>
#include <vtkCamera.h>
#include <vtkPointData.h>

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
//    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter2;
//    vtkSmartPointer<vtkPolyDataMapper> pointsMapper2;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper2;
//    vtkSmartPointer<vtkActor> pointsActor2;
    vtkSmartPointer<vtkActor> triangulatedActor2;

    vtkSmartPointer<vtkPoints> points3;
    vtkSmartPointer<vtkPolyData> polydata3;
    vtkSmartPointer<vtkDelaunay2D> delaunay3;
//    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter3;
//    vtkSmartPointer<vtkPolyDataMapper> pointsMapper3;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper3;
//    vtkSmartPointer<vtkActor> pointsActor3;
    vtkSmartPointer<vtkActor> triangulatedActor3;

    vtkSmartPointer<vtkPoints> points4;
    vtkSmartPointer<vtkPolyData> polydata4;
    vtkSmartPointer<vtkDelaunay2D> delaunay4;
//    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter4;
//    vtkSmartPointer<vtkPolyDataMapper> pointsMapper4;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper4;
//    vtkSmartPointer<vtkActor> pointsActor4;
    vtkSmartPointer<vtkActor> triangulatedActor4;

    vtkSmartPointer<vtkPoints> points5;
    vtkSmartPointer<vtkPolyData> polydata5;
    vtkSmartPointer<vtkDelaunay2D> delaunay5;
//    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter5;
//    vtkSmartPointer<vtkPolyDataMapper> pointsMapper5;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper5;
//    vtkSmartPointer<vtkActor> pointsActor5;
    vtkSmartPointer<vtkActor> triangulatedActor5;

    vtkSmartPointer<vtkPoints> points6;
    vtkSmartPointer<vtkPolyData> polydata6;
    vtkSmartPointer<vtkDelaunay2D> delaunay6;
//    vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter6;
//    vtkSmartPointer<vtkPolyDataMapper> pointsMapper6;
    vtkSmartPointer<vtkPolyDataMapper> triangulatedMapper6;
//    vtkSmartPointer<vtkActor> pointsActor6;
    vtkSmartPointer<vtkActor> triangulatedActor6;

    std::vector<vtkSmartPointer<vtkTextActor3D> > textActors;
    std::vector<vtkSmartPointer<vtkTextProperty> > textPropertys;
    vtkSmartPointer<vtkTextActor3D> textActor;
    vtkSmartPointer<vtkTextProperty> textProperty;

    //围边



};


#endif // LAYER_H
