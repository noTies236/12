// Default lib C++
#include "iostream" 
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// Header
#include "HandleWindow/Window.h"

int main()
{
	HandleWindow Window;
	Window.MainLoop();

	return 0;
}