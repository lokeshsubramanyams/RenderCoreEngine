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

#include "RenderCore.h"
#include <GraphicsObject.h>
#include <iostream>
#include "Debug.h"
#include <Camera.h>
#include <IMeshRenderer.h>
#include <UserInterface.h>

namespace RCEngine
{
	namespace UI
	{
		class ImguiLibraryOpenGL3 :public IUILibrary
		{
		public:
			ImguiLibraryOpenGL3(unsigned int windowID, const char* shaderVersion);
			
			void UIRender(const char* title,const char* str)override;
			void UIRender(RenderCore::GraphicsObject *gObject)override;

			void ShutDown()override;

		private:
			void ComponentRender(RenderCore::GraphicsObject *graphicsObject);

			void UIRender(RCEngine::RenderCore::Transform* transform);
			void UIRender(RCEngine::RenderCore::Camera* transform);

			

		};
	}
}