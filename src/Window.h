#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "stb_image.h"

class Window {
public:

	Window(int screenWidth, int screenHeight);
	void destroyWindow();
	void swapBuffer();
	void pollEvents();
	GLFWwindow* getWindow();
	bool shouldClose();

	void setWindowIcon(GLFWwindow* window, const char* filePath);

private:

	GLFWwindow* window;
};