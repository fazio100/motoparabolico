#include "Scene.h"


Scene::Scene(const Renderer& renderer, const Camera& camera) :
	localRenderer(renderer),
	localCamera(camera),
	isPlaying(true)
{
	localRenderer.SetClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
}

void Scene::OnSelect()
{
	localRenderer.SetClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
}




