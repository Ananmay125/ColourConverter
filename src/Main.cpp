#include "Window.h"
#include "Interface.h"

int main() {

	Window window(400, 400);
	GLFWwindow* getWindow = window.getWindow();

	Interface interface;
	interface.init(window.getWindow());
	interface.Style();

	window.setWindowIcon(getWindow, "resources/moan.jpg");
	
	while (!window.shouldClose()) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		interface.startFrame("Colour Converter");
		interface.Text("yo");
		interface.endFrame();
		interface.render();
		
		window.swapBuffer();
		window.pollEvents();
	}

	interface.destroyFrame();
	window.destroyWindow();
	return 0;
}
