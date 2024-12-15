#include "ScenesManager.h"



ScenesManager::ScenesManager(bool reload) : reloadOnSelection(reload)
{
}

void ScenesManager::Add(const std::string& name, Scene* scene)
{
    if (scene == nullptr) return;

    for (int i = 0; i < collector.size(); i++) {
        if (collector[i].first == name) {
            std::cout << "[Scene Error] Scene at addres: " << scene << " is a duplicate" << std::endl;
            return;
        }
        else if(collector[i].second == scene) {
            std::cout << "[Scene Error] Scene named " << name << " already exists" << std::endl;
            return;
        }
    }
	collector.push_back(std::make_pair(name, scene));
}

void ScenesManager::Select(int index) {
    if (index >= collector.size()) {
        std::cout << "[Scene Error] Index (" << index << ") out of range (max = " << collector.size() << ")" << std::endl;
        return;
    }

    
    currentScene = reloadOnSelection ? collector[index].second->Clone() : collector[index].second;
	currentScene->OnSelect();
    std::cout << "Scene " << index << " selected." << std::endl;
}

void ScenesManager::SelectionWindow() {
    ImGui::Begin("Selettore scena");

        ImGui::Text("FPS %.0f", ImGui::GetIO().Framerate);
        ImGui::Text(reloadOnSelection ? "Ricaricamento ON" : "Ricaricamento OFF");

        for (int i = 0; i < collector.size(); i++) {
            if (ImGui::Button(collector[i].first.c_str())) {
                Select(i);
            }
        }

    ImGui::End();
}

void ScenesManager::Draw()
{
    if (currentScene != nullptr)
        currentScene->Draw();
}

void ScenesManager::Update(float deltaTime, WindowData winData)
{
    if (currentScene != nullptr && currentScene->isPlaying)
        currentScene->Update(deltaTime, winData);

}
