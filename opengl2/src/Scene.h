#pragma once
#include "opengl/Renderer.h"
#include "Camera.h"
#include "glm/glm.hpp"
#include "Settings.h"


class Scene
{
protected:
	Camera localCamera;
	Renderer localRenderer;
public:
	bool isPlaying;
	glm::vec4 clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };

	Scene(const Renderer& renderer, const Camera& camera);


	void OnSelect();
	virtual Scene* Clone() const = 0;
	virtual void Draw() = 0;
	virtual void Update(float deltaTime, WindowData winData) = 0;
};
