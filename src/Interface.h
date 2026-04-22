#pragma once
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
    void Style();

    void Text(const char* text);
    void InputBox(const char* label, char* buffer, size_t size);

    ImFont* titleFont = nullptr;
};

struct ColorConverter {
    float color[4] = { 1, 0, 0, 1 };
    float hsv[3] = { 0, 0, 0 };
    char hex[16] = "#FF0000";

    void draw();
};