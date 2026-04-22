#include "Interface.h"
#include <stdio.h>

void Interface::init(GLFWwindow* window) {
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();

    titleFont = io.Fonts->AddFontFromFileTTF(
        "resources/Poppins-Medium.ttf",
        28.0f
    );
}

void Interface::startFrame(const char* title) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    const ImGuiViewport* viewport = ImGui::GetMainViewport();

    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
    ImGui::Begin(title, nullptr, flags);
}

void Interface::endFrame() {
    ImGui::End();
    ImGui::PopStyleVar();
}

void Interface::render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Interface::destroyFrame() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Interface::Style() {
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 0.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 1.0f;
    style.TabBorderSize = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1, 1, 1, 1);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.70f, 0.38f, 0.38f, 0.54f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.83f, 0.65f, 0.65f, 0.4f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.83f, 0.65f, 0.65f, 0.67f);
}

void Interface::Text(const char* text) {
    ImGui::Text("%s", text);
}

void Interface::InputBox(const char* label, char* buffer, size_t size) {
    ImGui::InputText(label, buffer, size);
}

/* ---------- COLOR CONVERSIONS ---------- */

static void RGBtoHSV(const float col[4], float& h, float& s, float& v) {
    ImGui::ColorConvertRGBtoHSV(col[0], col[1], col[2], h, s, v);
}

static void HSVtoRGB(float h, float s, float v, float col[4]) {
    ImGui::ColorConvertHSVtoRGB(h, s, v, col[0], col[1], col[2]);
}

static void RGBtoHEX(const float col[4], char* out) {
    sprintf(out, "#%02X%02X%02X",
        (int)(col[0] * 255),
        (int)(col[1] * 255),
        (int)(col[2] * 255));
}

static bool HEXtoRGB(const char* hex, float col[4]) {
    unsigned int r, g, b;
    if (sscanf(hex, "#%02X%02X%02X", &r, &g, &b) == 3) {
        col[0] = r / 255.0f;
        col[1] = g / 255.0f;
        col[2] = b / 255.0f;
        return true;
    }
    return false;
}

/* ---------- COLOR UI ---------- */

void ColorConverter::draw() {
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 6);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 10));

    ImGui::BeginChild("ColorConverter", ImVec2(0, 0), true);

    ImGui::Columns(2, nullptr, false);

    ImGui::Text("Picker");
    ImGui::ColorPicker4("##picker", color,
        ImGuiColorEditFlags_NoSidePreview |
        ImGuiColorEditFlags_NoSmallPreview);

    ImGui::NextColumn();

    ImGui::Text("Values");
    ImGui::Separator();

    ImGui::Text("RGB (0-255)");
    ImGui::Text("%d, %d, %d",
        (int)(color[0] * 255),
        (int)(color[1] * 255),
        (int)(color[2] * 255));

    ImGui::Text("RGBA (float)");
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::DragFloat4("##rgba", color, 0.01f, 0.0f, 1.0f);

    float h, s, v;
    RGBtoHSV(color, h, s, v);

    ImGui::Text("HSV");
    ImGui::SetNextItemWidth(-FLT_MIN);

    float hsv_edit[3] = { h, s, v };
    if (ImGui::DragFloat3("##hsv", hsv_edit, 0.01f, 0.0f, 1.0f)) {
        HSVtoRGB(hsv_edit[0], hsv_edit[1], hsv_edit[2], color);
    }

    RGBtoHEX(color, hex);

    ImGui::Text("HEX");
    ImGui::SetNextItemWidth(-FLT_MIN);

    if (ImGui::InputText("##hex", hex, IM_ARRAYSIZE(hex))) {
        HEXtoRGB(hex, color);
    }

    ImGui::Spacing();
    ImGui::Text("Preview");

    ImGui::ColorButton("##preview",
        ImVec4(color[0], color[1], color[2], 1.0f),
        ImGuiColorEditFlags_NoTooltip,
        ImVec2(120, 60));

    ImGui::Columns(1);

    ImGui::EndChild();
    ImGui::PopStyleVar(2);
}