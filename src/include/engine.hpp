#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Engine {
    public:
        Engine();
        ~Engine();

        GLFWwindow* createWindow();

    private:
        bool _failedInit;

        int _width;
        int _height;

};

// HELPERS
void handleGLFWError(int error, const char* description);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);