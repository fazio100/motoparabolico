#include "Rect.h"


/*Rect::Rect() :
    position(0, 0, 0),
    size(0, 0, 0),
    surface(0, 0, 0, 0, "res/textures/empty.png"),
    collider(0, 0, 0, 0)
{
}*/

Rect::Rect(float x, float y, float width, float height, Pivot pivot, const std::string& imagePath) :
    size(width, height, 0),
    surface(x, y, width, height, imagePath),
    collider(x, y, width, height),
    position(0,0,0)
{
    SetPosition(x, y, pivot);
}


void Rect::Translate(glm::vec3 translation, float deltaTime)
{
    position += (translation * deltaTime);
}


void Rect::Draw(Renderer& renderer , Camera& camera)
{
    surface.Draw(renderer, camera);
}

glm::vec3 Rect::GetPosition(Pivot pivot)
{
    switch (pivot) {
    case Topleft:       return glm::vec3(position.x, position.y, 0);
    case Topright:      return glm::vec3(position.x + size.x, position.y, 0);
    case Bottomleft:    return glm::vec3(position.x, position.y + size.y, 0);
    case Bottomright:   return glm::vec3(position.x + size.x, position.y + size.y, 0);
    case Midleft:       return glm::vec3(position.x, position.y + size.y / 2, 0);
    case Midright:      return glm::vec3(position.x + size.x, position.y + size.y / 2, 0);
    case Midtop:        return glm::vec3(position.x + size.x / 2, position.y, 0);
    case Midbottom:     return glm::vec3(position.x + size.x / 2, position.y + size.y, 0);
    case Center:        return glm::vec3(position.x + size.x / 2, position.y + size.y / 2, 0);
    default:
        std::cout << "[Rect Error] No known pivot (" << pivot << ")" << std::endl;
        return position;
    }
}

void Rect::SetPosition(float x, float y, Pivot pivot) {
    switch (pivot) {
    case Topleft:       position = glm::vec3(x, y, 0); break;
    case Topright:      position = glm::vec3(x - size.x, y, 0); break;
    case Bottomleft:    position = glm::vec3(x, y - size.y, 0); break;
    case Bottomright:   position = glm::vec3(x - size.x, y - size.y, 0); break;
    case Midleft:       position = glm::vec3(x, y - size.y / 2, 0); break;
    case Midright:      position = glm::vec3(x - size.x, y - size.y / 2, 0); break;
    case Midtop:        position = glm::vec3(x - size.x / 2, y, 0); break;
    case Midbottom:     position = glm::vec3(x - size.x / 2, y - size.y, 0); break;
    case Center:        position = glm::vec3(x - size.x / 2, y - size.y / 2, 0); break;
    default: std::cout << "[Rect Error] No known pivot (" << pivot << ")" << std::endl; break;
    }
}

void Rect::Update() {
    surface.Update(position, size);
    collider.Update(position, size);
}