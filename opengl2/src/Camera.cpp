#include "Camera.h"
#include <iostream>
Camera::Camera() : position(0,0,0), proj(0), view(0) {

}

Camera::Camera(int windowWidth, int windowHeight, glm::vec3 startPosition)
{
	position = startPosition;
	proj = glm::ortho(0.f, (float)windowWidth, (float) windowHeight, 0.0f, -1.0f, 1.0f);
	view = glm::translate(glm::mat4(1.0f), glm::vec3(startPosition));
}

void Camera::Update() {
	view = glm::translate(glm::mat4(1.0f), -glm::vec3(position));
}