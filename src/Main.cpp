#include "Window.h"

int main() {

	Window window(400, 400);
	
	while (!window.shouldClose()) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		window.swapBuffer();
		window.pollEvents();
	}

	window.destroyWindow();
	return 0;
}
