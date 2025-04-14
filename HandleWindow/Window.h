#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"
#include "iostream"

class HandleWindow
{
public:
    GLFWwindow* g_Window;

    HandleWindow(); // Construtor

    int SetupGlad();
    int SetupGlfw();
    void MainLoop();
    void WindowSetting();
};

#endif
