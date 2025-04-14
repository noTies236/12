#include "iostream" 
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "vector"

class Pipeline
{
public:
	GLuint VAO;
	GLuint VBO;
	GLuint shaderProgram;
	unsigned int texture;

	void defineVertex(std::vector<float> vertex, std::vector<float> color, std::vector<float> cord);
	void handleShaders(const char* vertexFile, const char* fragmentFile);
	void handleTextures();
};