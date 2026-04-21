#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

class Window {
public:

	Window(int screenWidth, int screenHeight);
	void destroyWindow();
	void swapBuffer();
	void pollEvents();
	GLFWwindow* getWindow();
	bool shouldClose();

private:

	GLFWwindow* window;
};