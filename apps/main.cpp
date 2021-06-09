#include <Engine.hpp>
#include <iostream>

int main() {
    Engine engine = Engine();
    GLFWwindow* window = engine.createWindow();

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    std::cout << "Success!" << std::endl;

    return 0;
}