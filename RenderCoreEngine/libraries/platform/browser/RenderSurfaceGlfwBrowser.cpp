#include "RenderSurfaceGlfwBrowser.h"
#include "rcEmscripten/RcEmscripten.h"


namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::Debugger;
		using namespace RCEngine::Platform::Browser;

		RenderSurfaceGlfwBrowser::RenderSurfaceGlfwBrowser(Rect screenRect)
			:IRenderSurfaceGlfw(screenRect)
		{
			window = CreateGlfwWindow("RCEngine", screenRect.width, screenRect.height);

			glfwGetFramebufferSize(window, &screenRect.width, &screenRect.height);

			MakeContextCurrent();

			resizeCallBack = std::bind(&RenderSurfaceGlfwBrowser::FramebufferResizeCallback, this, std::placeholders::_1, std::placeholders::_2);

			cursorPositionCallBack = std::bind(&RenderSurfaceGlfwBrowser::MousePositionCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

			mouseClickCallBack = std::bind(&RenderSurfaceGlfwBrowser::MouseClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

			mouseScrollCallBack = std::bind(&RenderSurfaceGlfwBrowser::MouseScrollCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);;
		}
		void RenderSurfaceGlfwBrowser::MakeContextCurrent()
		{
			glfwMakeContextCurrent(window);
		}

		bool RenderSurfaceGlfwBrowser::IsValid() const
		{
			return window != nullptr;
		}


		bool RenderSurfaceGlfwBrowser::ShouldClose()
		{
			return shouldClose;
		}

		void RenderSurfaceGlfwBrowser::SwapBuffers()
		{
			glfwSwapBuffers(window);
		}

		void RenderSurfaceGlfwBrowser::DestroySurface()
		{
			if (window)
			{
				glfwDestroyWindow(window);
				
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
			return window;
    }

    void RenderSurfaceGlfwBrowser::WindowPlacementOnBigMonitor()
    {

			int width = getWindowWidth();
			int height = getWindowHeight();

			Debug::Log("width:100%:", width);
			Debug::Log("height:100%:", height);

			//glfwGetFramebufferSize(glfwCanvas, &width, &height);
			glfwSetWindowSize(window, width, height);

    }

	
	}
}