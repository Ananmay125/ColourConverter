#include "Window.h"
#include "Interface.h"

int main() {

	Window window(400, 400);

	Interface interface;
	interface.init(window.getWindow());
	
	while (!window.shouldClose()) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		interface.startFrame("Colour Converter");
		interface.endFrame();
		interface.render();
		
		window.swapBuffer();
		window.pollEvents();
	}

	interface.destroyFrame();
	window.destroyWindow();
	return 0;
}
