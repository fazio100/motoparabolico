#include "RectCollider.h"
#include "iostream"


RectCollider::RectCollider(float x, float y, float width, float height) :
    position(x, y, 0.0f),
    size(width, height, 0.0f),
    isRigid(false)
{
}

bool RectCollider::Collides(const RectCollider& rectCollider) {
    return position.x + size.x >= rectCollider.position.x &&
        position.x <= rectCollider.position.x + rectCollider.size.x &&
        position.y + size.y >= rectCollider.size.y &&
        position.y <= rectCollider.position.y + rectCollider.size.y;
}

bool RectCollider::CollidesPoint(glm::vec2 point) {
    return  point.x >= position.x && point.x <= position.x + size.x &&
        point.y >= position.y && point.y <= position.y + size.y;
}

void RectCollider::Update(glm::vec3 newPosition, glm::vec3 newSize) {
    if (position != newPosition)
        position = newPosition;
    if (size != newSize)
        size = newSize;


}