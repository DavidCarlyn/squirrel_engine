#include <IndexBuffer.hpp>
#include <glad/glad.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) {
    glGenBuffers(1, &mRendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &mRendererID);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}