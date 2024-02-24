#include "RenderSurfaceGlfwBrowser.h"
#include "rcEmscripten/RcEmscripten.h"


namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::Debugger;
		using namespace RCEngine::Platform::Browser;

		RenderSurfaceGlfwBrowser::RenderSurfaceGlfwBrowser(Rect screenRect)
			:IRenderSurface(screenRect)
		{
			glfwCanvas = CreateGlfwWindow("RCEngine", screenRect.width, screenRect.height);

			glfwGetFramebufferSize(glfwCanvas, &screenRect.width, &screenRect.height);

			MakeContextCurrent();

			resizeCallBack = std::bind(&RenderSurfaceGlfwBrowser::FramebufferResizeCallback, this, std::placeholders::_1, std::placeholders::_2);
		}
		void RenderSurfaceGlfwBrowser::FramebufferResizeCallback(GLFWwindow* window, Rect newSurface)
		{
			if (windowResizeEventListenser)
			{
				windowResizeEventListenser(newSurface);
			}
		}
		void RenderSurfaceGlfwBrowser::MakeContextCurrent()
		{
			glfwMakeContextCurrent(glfwCanvas);
		}

		bool RenderSurfaceGlfwBrowser::IsValid() const
		{
			return glfwCanvas != nullptr;
		}


		bool RenderSurfaceGlfwBrowser::ShouldClose()
		{
			return shouldClose;
		}

		void RenderSurfaceGlfwBrowser::SwapBuffers()
		{
			glfwSwapBuffers(glfwCanvas);
		}

		void RenderSurfaceGlfwBrowser::DestroySurface()
		{
			if (glfwCanvas)
			{
				glfwDestroyWindow(glfwCanvas);
				
			}
		}

		RenderSurfaceGlfwBrowser::~RenderSurfaceGlfwBrowser()
		{
			DestroySurface();
		}

		void RenderSurfaceGlfwBrowser::Run(std::function<void()>renderFunction, std::function<void()>updateFunction)
		{
			RcEmscriptenRenderFunctionPtr = renderFunction;
			RcEmscriptenUpdateFunctionPtr = updateFunction;
			RcEmscriptenPollEventFunctionPtr = std::bind(&RenderSurfaceGlfwBrowser::PollEvents, this);
			Debug::Log("Run loop set");
			emscripten_set_main_loop(RcEmscriptenRenderFunction, 0, 1);
		}

		void RenderSurfaceGlfwBrowser::PollEvents()
		{
			glfwPollEvents();
			//Debug::Log("PollEvents");

		}

    std::any RenderSurfaceGlfwBrowser::GetContext()
    {
			return glfwCanvas;
    }

    void RenderSurfaceGlfwBrowser::WindowPlacementOnBigMonitor()
    {

			int width = getWindowWidth();
			int height = getWindowHeight();

			Debug::Log("width:100%:", width);
			Debug::Log("height:100%:", height);

			//glfwGetFramebufferSize(glfwCanvas, &width, &height);
			glfwSetWindowSize(glfwCanvas, width, height);

    }

	
	}
}