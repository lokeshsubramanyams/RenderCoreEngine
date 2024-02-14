#pragma once
#include <string>
#include <GLFW/glfw3.h>

#define STB_TEXTEDIT_IMPLEMENTATION
#if PLATFORM_WEBASSEMBLY
#define __EMSCRIPTEN__
#endif

#include "imgui.h"
#include "imgui_glfw/imgui_impl_glfw.h"
#include "imgui_glfw/imgui_impl_opengl3.h"

#include "Debug.h"



using namespace RCEngine::Debugger;

class TestUI
{
public:
	
	TestUI(GLFWwindow* window);
	void StartUI();
	void RenderText(const char* str);
	void AfterRender();
	void ShutDown();
};
