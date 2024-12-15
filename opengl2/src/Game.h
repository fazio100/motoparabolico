#pragma once
#include <vector>

#include "opengl\Renderer.h"
#include "glm\glm.hpp"
#include "imgui\imgui.h"

#include "Camera.h"
#include "ScenesManager.h"
#include "MainScene.h"


class Game {
private:
    Camera camera;
    Renderer renderer;
    ScenesManager scenes;
public:
    Game() :
        camera(W, H, glm::vec3(0.0f, 0.0f, 0.0f)),
        scenes(true)
    {
        renderer.SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        scenes.Add("Moto Parabolico", new MainScene(renderer, camera));
        scenes.Select(0);
	}
    

	void Update(float deltaTime, WindowData winData) {
        renderer.Clear();

        scenes.SelectionWindow();
        
        // draw
        scenes.Draw();

        // update
        scenes.Update(deltaTime, winData);

        camera.Update();
	}
};
