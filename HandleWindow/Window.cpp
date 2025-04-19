#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "iostream"
#include "Window.h" 
#include "vector"

#include "../../playground/HandlePipeline/Pipeline.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"

// triangle
std::vector<float> myTriangle{
     0.5f, -0.5f, 0.0f,
    -0.2f, -0.5f, 0.0f,
     0.0f, -0.3f, 0.0f
};

glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(0.8f, -1.0f, -0.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};

// second
std::vector<float> mySecondTriangle{
     0.5f, 0.4f, 0.0f,
    -0.2f, 0.2f, 0.0f,
    -0.4f, 0.2f, 0.0f,
    
    0.7f, 0.2f, 0.0f,
    -0.2f, 0.4f, 0.0f,
    0.4f, 0.2f, 0.0f,

    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

std::vector<float> textureCoords = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f
};

// Color
std::vector<float> color{
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,

    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 1.0f,

    1.0f, 0.1f, 0.0f,
    1.0f, 1.0f, 0.0f,
    0.8f, 0.5f, 1.0f
};

std::vector<float> cubeV = {
    // Face de trás
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    // Face da frente
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    // Face esquerda
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

    // Face direita
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

     // Face inferior
     -0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f, -0.5f,  0.5f,
     -0.5f, -0.5f,  0.5f,
     -0.5f, -0.5f, -0.5f,

     // Face superior
     -0.5f,  0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f, -0.5f
};

HandleWindow::HandleWindow() {
    g_Window = nullptr; 
}

void HandleWindow::MainLoop() 
{
    this->WindowSetting();

    // fisrt draw
    Pipeline pipeline;
    pipeline.defineVertex(cubeV, cubeV, textureCoords);

    while (!glfwWindowShouldClose(g_Window)) {
        glClearColor(1.0f, 1.0f, 0.5f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glBindVertexArray(pipeline.VAO);

        pipeline.handleShaders("vert.glsl", "frag.glsl", cubePositions[0], 0);
        pipeline.handleTextures();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        pipeline.handleShaders("vert.glsl", "frag.glsl", cubePositions[1], 1);
        pipeline.handleTextures();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        pipeline.handleShaders("vert.glsl", "frag.glsl", cubePositions[2], 2);
        pipeline.handleTextures();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        pipeline.handleShaders("vert.glsl", "frag.glsl", cubePositions[3], 3);
        pipeline.handleTextures();
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(g_Window);
        glfwPollEvents(); 
    }
}

void HandleWindow::WindowSetting() 
{
    this->SetupGlfw();
    this->SetupGlad();
}

int HandleWindow::SetupGlad()
{
    if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "GLAD has been initialized!!! I'm glad :-)" << std::endl;
        return 0;
    }
    else {
        std::cout << "GLAD initialization has failed" << std::endl;
        glfwTerminate();
        return -1;
    }
}

int HandleWindow::SetupGlfw() 
{
    if (!glfwInit()) {
        std::cout << "GLFW initialization failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    g_Window = glfwCreateWindow(640, 480, "I am not ok", NULL, NULL);

    if (g_Window == NULL) {
        std::cout << "g_Window creation has failed!!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(g_Window);

    return 0;
}