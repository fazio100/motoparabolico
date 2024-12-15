#pragma once
#include "RectangleMesh.h"
#include "Camera.h"

enum Pivot {
	Topleft,
	Topright,
	Bottomleft,
	Bottomright,
	Midtop,
	Midbottom,
	Midleft,
	Midright,
	Center,
};

class Surface
{
private:
	glm::vec3 position;
	glm::vec3 size;
	glm::mat4 model;
	glm::mat4 mvp;
	float angle;
public:
	RectangleMesh mesh;
	Surface(float x, float y, float widht, float height, const std::string& imagePath);
	void Rotate(float degrees);
	void SetImage(const std::string& path);
	void Draw(Renderer& renderer, Camera& camera);
	void Update(glm::vec3 newPosition, glm::vec3 newSize);
};

