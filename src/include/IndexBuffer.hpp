#pragma once

class IndexBuffer {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

    private:
        unsigned int mRendererID;
        unsigned int mCount;
};