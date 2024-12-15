#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera
{
private:
	glm::mat4 proj;
	glm::mat4 view;
public:

	glm::vec3 position;
	Camera();
	Camera(int windowWidth, int windowHeight, glm::vec3 startPosition);

	void Update();
	inline glm::mat4 GetProj() const { return proj; }
	inline glm::mat4 GetView() const { return view; }
};

