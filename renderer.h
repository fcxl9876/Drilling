#ifndef RENDERER_H
#define RENDERER_H

#include "renderer.h"
#include "layer.h"
#include "line.h"
#include "odbchelper.h"
#include "virtualline.h"

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkActor.h>


class Renderer
{
public:
    Renderer();
    void viewDrilling();
    void hideDrilling();
    vtkSmartPointer<vtkRenderer> renderer;
    odbchelper sql;
    Layer layer;
};

#endif // RENDERER_H
