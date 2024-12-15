#pragma once
#include "glm/glm.hpp"

class RectCollider
{
private:
	bool isRigid;
public:
	glm::vec3 position;
	glm::vec3 size;
	RectCollider(float x, float y, float width, float height);
	bool Collides(const RectCollider& rect);
	bool CollidesPoint(glm::vec2 point);
	void Update(glm::vec3 newPosition, glm::vec3 newSize);
};

