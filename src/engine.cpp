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

    _height = 480;
    _width = 480;
}

Engine::~Engine() {

    // Terminate GLFW
    glfwTerminate();
}

GLFWwindow* Engine::createWindow() {
    GLFWwindow* window = glfwCreateWindow(_width, _height, "My Title", NULL, NULL);
    if (!window) {
        std::cerr << "ERROR creating GLFW window" << std::endl;
    }

    // Set current context
    glfwMakeContextCurrent(window);

    //Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        _failedInit = true;
        return nullptr;
    }

    // Set viewport
    glViewport(0, 0, _width, _height);

    // Set callback on window resize
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    return window;
}

void handleGLFWError(int error, const char* description) {
    std::cerr << description << std::endl;
}

//TODO: find a way to update the height and the width of the engine class
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}