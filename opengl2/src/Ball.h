#pragma once

#include "Rect.h"
#include "imgui/imgui.h"
#include "Settings.h"



class Ball {
private:
public:
	Rect rect;

	glm::vec3 velocity = { 0, 0, 0 };
	float startVelocity = 0;
	float alphaDeg = 45;

	float gravity = 49;
	float gravityScale = 1;

	float previousY = 0, currentY = 0, deltaY = 0;

	float pixelPerMeter = 20;

	std::vector<float> ys = {};

	Ball(glm::vec3 position):
		rect(0, H - 100, 30, 30, Bottomleft)
	{
		rect.surface.SetImage("C:/Users/della/OneDrive/Desktop/c++/personali/opengl2/opengl2/res/textures/circle.png");
	}

	void RenderGUI() {
		ImGui::Begin("Impostazioni corpo");
		ImGui::SliderFloat("g scala.", &gravityScale, 0, 5);
		ImGui::SliderFloat("pixel per metro", &pixelPerMeter, 0, 100);
		ImGui::SliderFloat("v0", &startVelocity, 0, 40);
		ImGui::SliderFloat("alfa", &alphaDeg, 0, 180);
		ImGui::End();

		ImGui::Begin("Statistiche corpo");
		ImGui::Text("posizione = %.2f, %.2f", rect.GetPosition(Topleft).x, 590 - rect.GetPosition(Topleft).y);
		ImGui::Text("velocita = %.2f, %.2f", velocity.x, -velocity.y);
		ImGui::End();
	}

	void Jump() {
		velocity = glm::vec3(
			startVelocity * glm::cos(glm::radians(alphaDeg)),
			-startVelocity * glm::sin(glm::radians(alphaDeg)),
			0
		) * pixelPerMeter;
	}

	void Draw(Renderer& renderer, Camera& camera) {
		rect.Draw(renderer, camera);
	}

	void ProcessUserInputs() {
		if (ImGui::IsKeyPressed(ImGuiKey_Space, false) && rect.GetPosition(Midbottom).y >= H - 100) {
			Jump();
		}
	}

	void Update(float deltaTime, RectCollider groundCollider) {
	
		currentY = rect.GetPosition(Center).y;
		deltaY = currentY - previousY;
		previousY = currentY;


		
		rect.Translate(velocity, deltaTime);


		// check if the rect is on the ground after translation
		if (rect.GetPosition(Midbottom).y > H - 100) {
			rect.SetPosition(rect.GetPosition(Bottomleft).x, H - 100, Bottomleft);
			velocity.y = 0;
			

			if (deltaY > 0) {
				velocity.x = 0;
			}
		}
		else {
			velocity.y += gravity * gravityScale * pixelPerMeter * deltaTime;
		}
		ProcessUserInputs();
		

		rect.Update();
	}
};