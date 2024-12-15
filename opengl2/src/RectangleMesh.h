#pragma once
#include "opengl\Mesh.h"
#include <vector>
#include <iostream>

#define RECTANGLE_SHADER "C:/Users/della/OneDrive/Desktop/c++/personali/opengl2/opengl2/res/shaders/rectangle.shader"


class RectangleMesh : public Mesh
{
private:
    std::vector<float> position;
public:

    RectangleMesh(float, float, float, float, const std::string&, const std::string&);

    ~RectangleMesh();

    void SetColor(float r, float g, float b, float a);
};

