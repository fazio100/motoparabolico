#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"


class App {
private:
    GLFWwindow* window;
    Game game;
    float dt;
    float currentTime;
    float previousTime;
public:
	App() {

        if (!glfwInit())
            abort();

        window = glfwCreateWindow(W, H, "My Game", NULL, NULL);

        if (!window) {
            glfwTerminate();
            abort();
        }

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
            std::cout << "GLEW ERROR" << std::endl;

        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        currentTime = glfwGetTime();
        previousTime = currentTime;

        while (!glfwWindowShouldClose(window)) {
            currentTime = glfwGetTime();
            dt = currentTime - previousTime;
            previousTime = currentTime;

            game.Update(dt);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
	}
};
