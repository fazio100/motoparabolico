#pragma once

#include "Scene.h"
#include "Rect.h"
#include "Ball.h"

class MainScene : public Scene {
private:
	Rect ground;
	Ball ball;
public:
	MainScene(const Renderer& renderer, const Camera& camera) :
		Scene(renderer, camera),
		ground(0, H, W, 100, Bottomleft, "C:/Users/della/OneDrive/Desktop/c++/personali/opengl2/opengl2/res/textures/floor.png"),
		ball(glm::vec3(0, H - 100, 0))
	{
		clearColor = { 0.2f, 0.2f, 0.2f, 1.0f };
	}

	MainScene* Clone() const
	{
		return new MainScene(*this);
	}

	void Draw() override {
		ball.Draw(localRenderer, localCamera);
		ground.Draw(localRenderer, localCamera);

	}

	void RenderGUI() {
		ball.RenderGUI();
	}

	void Update(float deltaTime, WindowData winData) override {


		RenderGUI();


		ball.Update(deltaTime, ground.collider);
		ground.Update();
		localCamera.Update();


	}
};