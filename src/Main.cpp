#include "Window.h"
#include "Interface.h"

int main() {

	Window window(400, 400);
	GLFWwindow* getWindow = window.getWindow();

	Interface interface;
	interface.init(window.getWindow());
	interface.Style();

	ColorConverter converter;

	// variables
	static float color[4] = { 1, 0, 0, 1 };

	window.setWindowIcon(getWindow, "resources/moan.jpg");
	
	while (!window.shouldClose()) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		interface.startFrame("Colour Converter");
		ImGui::PushFont(interface.titleFont);
		ImGui::Text("Colour Converter");
		ImGui::PopFont();
		converter.draw();
		interface.endFrame();
		interface.render();
		
		window.swapBuffer();
		window.pollEvents();
	}

	interface.destroyFrame();
	window.destroyWindow();
	return 0;
}
