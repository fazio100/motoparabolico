#include "Surface.h"

Surface::Surface(float x, float y, float width, float height, const std::string& imagePath) :
    position(x, y, 0),
    size(width, height, 0),
    mesh(x, y, width, height, RECTANGLE_SHADER, imagePath),
    angle(0.0f),
    mvp(1.0f)
{    
    model = glm::translate(glm::mat4(1.0f), position);
}

void Surface::Update(glm::vec3 newPosition, glm::vec3 newSize)
{
    position = newPosition;
    size = newSize;

    model = glm::translate(glm::mat4(1.0f), position);
    model = glm::translate(model, glm::vec3(size.x / 2, size.y / 2, 0)); 
    model = glm::rotate(model, angle, glm::vec3(0, 0, 1));
    model = glm::translate(model, glm::vec3(-size.x / 2, -size.y / 2, 0));

}

void Surface::Rotate(float degrees) {
    angle += degrees;
}

void Surface::SetImage(const std::string& path)
{
    mesh.texture.SetPath(path);
}

void Surface::Draw(Renderer& renderer, Camera& camera) {
    mesh.texture.Bind();
    mesh.shader.Bind();
    mesh.shader.SetUniform1i("u_Texture", 0); // Associa l'uniform alla texture unit 0

    mvp = camera.GetProj() * camera.GetView() * model;

    mesh.shader.SetUniformMat4f("u_MVP", mvp);
    mesh.Draw(renderer);
}
