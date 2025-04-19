#include "iostream" 
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "vector"
#include "../glm/glm.hpp"

class Pipeline
{
public:
	GLuint VAO;
	GLuint VBO;
	GLuint shaderProgram;
	unsigned int texture;

	void defineVertex(std::vector<float> vertex, std::vector<float> color, std::vector<float> cord);
	void handleShaders(const char* vertexFile, const char* fragmentFile, const glm::vec3 valueTrans, int angle);
	void handleTextures();
};