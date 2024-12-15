#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Game.h"
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl3.h"


#define IMGUIUpdate(x) ImGui_ImplGlfw_NewFrame();\
                    ImGui_ImplOpenGL3_NewFrame();\
                    ImGui::NewFrame();\
                    x;\
                    ImGui::Render();\
                    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData())


int main(void)
{
    GLFWwindow* window;


    if (!glfwInit())
        exit(-1);

    window = glfwCreateWindow(W, H, "Game", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) 
        std::cout << "GLEW ERROR" << std::endl;


    {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        Game game;

        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

        ImGui::StyleColorsDark();

        
        float dt = 0;
        float currentTime = (float)glfwGetTime();
        float previousTime = currentTime;

        WindowData winData;
        winData.window = window;

        double x, y;


        while (!glfwWindowShouldClose(window)){
            // dt calcultation
            currentTime = (float)glfwGetTime();
            dt = currentTime - previousTime;
            previousTime = currentTime;

            // mouse pos assignment
            glfwGetCursorPos(window, &x, &y);

            winData.mousePos = glm::vec2(x, y);
            winData.mouseButtons[0] = (bool)glfwGetMouseButton(window, 0);
            winData.mouseButtons[1] = (bool)glfwGetMouseButton(window, 1);
            winData.mouseButtons[2] = (bool)glfwGetMouseButton(window, 2);
            

            IMGUIUpdate(game.Update(dt, winData));

            

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}