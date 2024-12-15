#pragma once
#include "opengl/Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define GLM_ENABLE_EXPERIMENTAL

#include "glm/gtx/string_cast.hpp"

#include "Surface.h"
#include "Camera.h"
#include "RectCollider.h"




/*NOTE: always call rect.Update()*/
class Rect
{
private:
public:
	glm::vec3 position;
	glm::vec3 size;
	RectCollider collider;
	Surface surface;

	//Rect();
	Rect(float x, float y, float width, float height, Pivot pivot, const std::string& imagePath= "res/textures/empty.png");

	// Return: position of the given pivot (topleft default)
	glm::vec3 GetPosition(Pivot pivot);

	// Sets the position of the given pivot (topleft default)
	void SetPosition(float x, float y, Pivot pivot);


	void Translate(glm::vec3 translation, float deltaTime);
	void Draw(Renderer& renderer, Camera& camera);
	void Update();
};

