#pragma once

#include <GLFW/glfw3.h>

class Input
{
public:
    ~Input(){};


    static Input &Instance()
    {
        static Input INSTANCE;
        return INSTANCE;
    }

    Input(const Input &) = delete;
    Input(Input &&) = delete;
    Input &operator=(const Input &) = delete;
    Input &operator=(Input &&) = delete;

    void SetWindow(GLFWwindow *window);
    bool IsKeyPressed(int keyCode);

private:
    Input(){};
    GLFWwindow *window;
};
