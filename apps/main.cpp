#include <VertexBuffer.hpp>
#include <IndexBuffer.hpp>
#include <Engine.hpp>
#include <iostream>

const char *vertexShaderSource = "#version 460 core\n"
    "layout (location = 0) in vec4 aPos;\n"
    "void main() {\n"
    "   gl_Position = aPos;\n"
    "}\0";

const char *fragmentShaderSource = "#version 460 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.2f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    Engine engine = Engine();
    GLFWwindow* window = engine.createWindow();

    float positions[] = {
         0.5f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f,  0.5f
    };

    unsigned int indicies[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    // Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Shader Program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // Buffers
    VertexBuffer vb = VertexBuffer(positions, sizeof(positions));
    IndexBuffer ib = IndexBuffer(indicies, 6);

    glBindVertexArray(VAO);

    // Vertex Layout
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    // Enable Vertex Attribute Array
    glEnableVertexAttribArray(0); 

    vb.unbind();
    ib.unbind();


    while (!glfwWindowShouldClose(window)) {

        // Process Input
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        // Draw Triangle
        glUseProgram(shaderProgram); // Which shaders to use
        glBindVertexArray(VAO); // Which Vertex Array to use
        ib.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // How to draw
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);

    std::cout << "Success!" << std::endl;

    return 0;
}