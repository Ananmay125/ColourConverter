#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Interface {
public:

	void init(GLFWwindow* window);
	void startFrame(const char* title);
	void endFrame();
	void render();
	void destroyFrame();

private:


};