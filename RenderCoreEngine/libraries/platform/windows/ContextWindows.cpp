#include "ContextWindows.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace Platform
	{

		ContextWindows::ContextWindows(Rect _viewport) :IContext(_viewport)
		{
			if (!glfwInit())
			{
				Debug::LogError("glfw init failed with return code -1");
				return;
			}
			else
				Debug::Log("glfw init");
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			window = glfwCreateWindow(viewport.width, viewport.height, "RCEngine", NULL, NULL);



			if (!window) {
				// Window or OpenGL context creation failed
				glfwTerminate();
				Debug::LogError("glfw Window or OpenGL context creation failed with return code -1");
				return;
			}
			else
				Debug::Log("glfw Window or OpenGL context created");

			glfwMakeContextCurrent(window);

			while (!glfwWindowShouldClose(window)) {
				// Check and call events
				glfwPollEvents();
			}
		}

		ContextWindows::~ContextWindows()
		{
			if (window)
			{
				glfwDestroyWindow(window);
			}
		}

		void ContextWindows::makeContextCurrent() 
		{
			glfwMakeContextCurrent(window);
		}

		bool ContextWindows::shouldClose() 
		{
			return glfwWindowShouldClose(window);
		}

		void ContextWindows::swapBuffers() 
		{
			glfwSwapBuffers(window);
		}

		void ContextWindows::DestroyContext() 
		{
			glfwDestroyWindow(window);
		}
		bool ContextWindows::IsValidContext()
		{
			return window != nullptr;
		}
	}
}