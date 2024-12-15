#include "RectangleMesh.h"


RectangleMesh::RectangleMesh(
    float x, float y,
    float width, float height,
    const std::string& shaderPath,
    const std::string& texturePath
) : Mesh(
    std::vector<float>
    { 0.0f,     0.0f,       0.0f,   1.0f,
      width,    0.0f,       1.0f,   1.0f,
      width,    height,     1.0f,   0.0f,
      0.0f,     height,     0.0f,   0.0f, }.data(),
    (unsigned int)(sizeof(float) * 16),
    std::vector<unsigned int>
    { 0, 1, 2,
      2, 3, 0 }.data(), (unsigned int)6,
    shaderPath, texturePath
)
{
    SetColor(1.0f, 1.0f, 1.0f, 1.0f);
}


RectangleMesh::~RectangleMesh()
{
}




void RectangleMesh::SetColor(float r, float g, float b, float a = 1.0f)
{
    shader.Bind();
    shader.SetUniform4f("u_BgColor", r, g, b, a);
}
