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
    void viewLine();
    void hideLine();

    void showL1_1();
    void showL1_2();
    void showL2_1();
    void showL2_2();
    void showL2_3();
    void showL3_1();
    void showL3_2();
    void showL3_3();
    void showL4_1();
    void showL4_2();
    void showL5_1_1();
    void showL5_1_2();
    void showL5_2();
    void showL5_3();
    void showL5_4();
    void showL6();
    void showL7_1();
    void showL7_2();
    void showL8_1();
    void showL8_2();
    void showL9_1();
    void showL9_2();
    void showL10();
    void showL11();
    void showL12();
    void showL13();
    void showL13_2();
    void showL14();
    void showchazhi();
    void showbujialayer();

    vtkSmartPointer<vtkRenderer> renderer;
    odbchelper sql;
    Layer layer;
private:
    Line line;
    VirtualLine virtualLine;
};

#endif // RENDERER_H
