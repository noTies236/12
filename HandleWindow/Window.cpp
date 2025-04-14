#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "iostream"
#include "Window.h" 
#include "vector"

#include "../../playground/HandlePipeline/Pipeline.h"

// triangle
std::vector<float> myTriangle{
     0.5f, -0.5f, 0.0f,
    -0.2f, -0.5f, 0.0f,
     0.0f, -0.3f, 0.0f
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

std::vector<float> coord{
    // telhado
    0.5f, 1.0f,  // topo
    0.0f, 0.5f,  // canto esquerdo
    1.0f, 0.5f,  // canto direito
    
    // base (retângulo) — 1º triângulo
    0.0f, 0.5f,
    0.0f, 0.0f,
    1.0f, 0.0f,
    
    // base — 2º triângulo
    0.0f, 0.5f,
    1.0f, 0.0f,
    1.0f, 0.5f
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

std::vector<float> house1 {
    // triangle             
    0.1f, 0.6f, 0.0f,      
    -0.3f, 0.4f, 0.0f, 
    0.5f, 0.4f, 0.0f, 

    -0.3f, 0.4f, 0.0f,  
    -0.3f, 0.0f, 0.0f,
    0.5f, 0.0f, 0.0f, 

    -0.3f, 0.4f, 0.0f, 
    0.5f, 0.0f, 0.0f,   
    0.5f, 0.4f, 0.0f,

    1.0f, 0.1f, 0.0f,
    1.0f, 1.0f, 0.0f,
    0.8f, 0.5f, 1.0f
};

HandleWindow::HandleWindow() {
    g_Window = nullptr; 
}

void HandleWindow::MainLoop() 
{
    this->WindowSetting();

    // fisrt draw
    Pipeline pipeline;
    pipeline.defineVertex(house1, color, coord);
    pipeline.handleShaders("vert.glsl", "frag.glsl");
    pipeline.handleTextures();
    
    //Pipeline pipeline2;
    //pipeline2.defineVertex(mySecondTriangle, mySecondTriangle);
    //pipeline.handleShaders("vert.glsl", "frag.glsl");

    while (!glfwWindowShouldClose(g_Window)) {
        glClearColor(1.0f, 1.0f, 0.5f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(pipeline.VAO);
        //glPointSize(10.0f);
        glDrawArrays(GL_TRIANGLES, 0, 9);

        //glBindVertexArray(pipeline2.VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 6);

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