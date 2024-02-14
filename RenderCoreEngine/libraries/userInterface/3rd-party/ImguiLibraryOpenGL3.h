#pragma once
#include "IUILibrary.h"
#include <string>
#include <GLFW/glfw3.h>

#define STB_TEXTEDIT_IMPLEMENTATION
#if PLATFORM_WEBASSEMBLY
#define __EMSCRIPTEN__
#endif

#include "imgui.h"
#include "imgui_glfw/imgui_impl_glfw.h"
#include "imgui_glfw/imgui_impl_opengl3.h"

namespace RCEngine
{
	namespace UI
	{
		class ImguiLibraryOpenGL3 :public IUILibrary
		{
		public:
			ImguiLibraryOpenGL3(std::any context, const char* shaderVersion);
			
			void UIRender()override;
			void UIRender(const char* title,const char* str)override;

			void ShutDown()override;
		};
	}
}