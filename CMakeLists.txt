cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("ColourConverter")

add_subdirectory(libs/glfw)

add_executable (ColourConverter 
    "src/Main.cpp"
    "libs/glad/src/glad.c" 

    "libs/imgui/imgui.cpp"
    "libs/imgui/imgui_demo.cpp"
    "libs/imgui/imgui_draw.cpp"
    "libs/imgui/imgui_tables.cpp"
    "libs/imgui/imgui_widgets.cpp"
    "libs/imgui/ImGuizmo.cpp"
    "libs/imgui/backends/imgui_impl_glfw.cpp"
    "libs/imgui/backends/imgui_impl_opengl3.cpp"
    "libs/stb_image_write.h"
    
    "src/Window.cpp" 
    "src/Window.h"
    "src/Interface.h" 
    "src/Interface.cpp" 
)

target_include_directories(ColourConverter PRIVATE 
    libs/glfw/include
    libs/glad/include 
    libs/imgui
    libs/imgui/backends
)

target_link_libraries(ColourConverter PRIVATE 
    glfw 
    opengl32 
)

target_compile_definitions(ColourConverter PRIVATE IMGUI_DEFINE_MATH_OPERATORS)

install(TARGETS ColourConverter DESTINATION .)