#include <Engine.hpp>
#include <iostream>

int main() {
    Engine engine = Engine();
    GLFWwindow* window = engine.createWindow();

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    std::cout << "Success!" << std::endl;

    return 0;
}