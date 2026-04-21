#include "Window.h"

// Basic Window Setup

Window::Window(int screenWidth, int screenHeight) {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(screenWidth, screenHeight, "ColourConverter", nullptr, nullptr);
	if (!window) {
		std::cout << "GLFW window couldn't be created" << std::endl;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD couldn't be initialized" << std::endl;
	}
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::swapBuffer() {
	glfwSwapBuffers(window);
}

void Window::pollEvents() {
	glfwPollEvents();
}

void Window::destroyWindow() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::setWindowIcon(GLFWwindow* window, const char* filePath) {
	stbi_set_flip_vertically_on_load(false);
	GLFWimage images[1];
	images[0].pixels = stbi_load(filePath, &images[0].width, &images[0].height, 0, 4);
	glfwSetWindowIcon(window, 1, images);
	stbi_image_free(images[0].pixels);
}


GLFWwindow* Window::getWindow() {
	return window;
}