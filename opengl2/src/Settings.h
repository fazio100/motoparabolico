#pragma once
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

struct WindowData {
    GLFWwindow* window;
    glm::vec2 mousePos;
    bool mouseButtons[3];
};

enum Button {
    Left,
    Middle,
    Right,
};

#define W 1280
#define H 720