#pragma once

#include "imgui.h"
#define STB_TEXTEDIT_IMPLEMENTATION
#include <string>
#include <GLFW/glfw3.h>

class TestUI
{
public:
	TestUI(GLFWwindow* window);
	void StartUI();
	void RenderText(const char* str);
	void AfterRender();
	void ShutDown();
};
