#define STB_IMAGE_IMPLEMENTATION
#include "../../../LearnOpenGL/playground/stb_image.h"
#include "Pipeline.h"
#include "iostream"
#include <fstream>
#include <sstream>

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "../glm/gtx/string_cast.hpp"

GLuint VBOs[3];

void Pipeline::defineVertex(std::vector<float> vertex, std::vector<float> color, std::vector<float> coord)
{
	std::cout << "vert: " << vertex.size() << " color: " << color.size() << " coord: " << coord.size() << "\n";
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(3, VBOs);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float), vertex.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 *sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, color.size() * sizeof(float), color.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, coord.size() * sizeof(float), coord.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Pipeline::handleShaders(const char* vertexPath, const char* fragmentPath, const glm::vec3 valueTrans, int angle)
{
    // 1. Ler os arquivos
    std::ifstream vFile(vertexPath);
    std::ifstream fFile(fragmentPath);

    std::cout << "valueTrans: " << glm::to_string(valueTrans) << "\n";

    if (!vFile.is_open() || !fFile.is_open()) {
        std::cerr << "Erro ao abrir os arquivos de shader.\n";
        return;
    }
    std::stringstream vBuffer, fBuffer;
    vBuffer << vFile.rdbuf();
    fBuffer << fFile.rdbuf();
    std::string vCode = vBuffer.str();
    std::string fCode = fBuffer.str();

    const char* vSource = vCode.c_str();
    const char* fSource = fCode.c_str();

    // 2. Criar e compilar shaders
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, nullptr);
    glCompileShader(vShader);

    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, nullptr);
    glCompileShader(fShader);

    // 3. Linkar o programa
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vShader);
    glAttachShader(shaderProgram, fShader);
    glLinkProgram(shaderProgram);

    // 4. Usar o programa
    
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(valueTrans)); 
    float test = 20.0f;
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(test * angle), glm::vec3(1.0f, 0.3f, 0.5f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    GLuint projectionLoc = glGetUniformLocation(shaderProgram, "projection");
    GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");

    glUseProgram(shaderProgram);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glBindVertexArray(VAO);

    // 5. Apagar shaders (opcional)
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Pipeline::handleTextures()
{
    // Generating a texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("C:/Users/wally/Downloads/container.jpg", &width, &height, &nrChannels, 0);
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);

    stbi_image_free(data);
    // Applying textures
}