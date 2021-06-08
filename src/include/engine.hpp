#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Engine {
    public:
        Engine();
        ~Engine();

        GLFWwindow* createWindow();

    private:
        bool _failedInit;

};

// HELPERS
void handleGLFWError(int error, const char* description);