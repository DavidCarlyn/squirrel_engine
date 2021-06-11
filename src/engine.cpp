#include <engine.hpp>
#include <iostream>

Engine::Engine() {
    //TODO: move GLFW handling logic to another wrapper/adapter class
    // Initialize GLFW
    if (!glfwInit()) {
        _failedInit = true;
        return;
    }

    // Set GLFW Error callback
    glfwSetErrorCallback(handleGLFWError);
}

Engine::~Engine() {

    // Terminate GLFW
    glfwTerminate();
}

void handleGLFWError(int error, const char* description) {
    std::cerr << description << std::endl;
}

GLFWwindow* Engine::createWindow() {
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        std::cerr << "ERROR creating GLFW window" << std::endl;
    }

    glfwMakeContextCurrent(window);
    std::cerr << "HERE" << std::endl;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error initializing GLEW" << std::endl;
    }

    return window;
}