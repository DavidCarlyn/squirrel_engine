#include <glad/glad.h>
#include <Engine.hpp>
#include <iostream>

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    Engine engine = Engine();
    GLFWwindow* window = engine.createWindow();

    while (!glfwWindowShouldClose(window)) {

        // Process Input
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        float verticies[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
        };

        // Buffer ID
        unsigned int vbo;
        glGenBuffers(1, &vbo);

        // Bind Buffer Type
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // Fill Buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    std::cout << "Success!" << std::endl;

    return 0;
}