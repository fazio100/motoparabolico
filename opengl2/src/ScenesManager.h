#pragma once
#include "Scene.h"
#include "imgui\imgui.h"
#include <iostream>


class ScenesManager
{
private:
	std::vector<std::pair<std::string, Scene*>> collector = {};
	Scene* currentScene = nullptr;
	bool reloadOnSelection;
public:
	ScenesManager(bool reload);

	void Add(const std::string& name, Scene* scene);
	void Select(int index);
	void SelectionWindow();
	void Draw();
	void Update(float deltaTime, WindowData winData);
};

