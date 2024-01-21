#include "RenderSurfaceWin64.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace Platform
	{

		RenderSurfaceWin64::RenderSurfaceWin64(Rect _viewport) :IRenderSurface(_viewport)
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

			/*while (!glfwWindowShouldClose(window)) {
				// Check and call events
				glfwPollEvents();
			}*/
		}

		RenderSurfaceWin64::~RenderSurfaceWin64()
		{
			if (window)
			{
				glfwDestroyWindow(window);
			}
		}

		void RenderSurfaceWin64::MakeContextCurrent()
		{
			glfwMakeContextCurrent(window);
		}

		void RenderSurfaceWin64::PollEvents()
		{
			glfwPollEvents();
		}

		bool RenderSurfaceWin64::ShouldClose()
		{
			return glfwWindowShouldClose(window);
		}

		void RenderSurfaceWin64::SwapBuffers()
		{
			glfwSwapBuffers(window);
		}

		void RenderSurfaceWin64::DestroySurface()
		{
			glfwDestroyWindow(window);
		}
		bool RenderSurfaceWin64::IsValid()const
		{
			return window != nullptr;
		}

		void RenderSurfaceWin64::Run(std::function<void()>renderFunction)
		{
			while (!ShouldClose())
			{
				PollEvents();
				renderFunction();
				SwapBuffers();
			}
		}
	}
}