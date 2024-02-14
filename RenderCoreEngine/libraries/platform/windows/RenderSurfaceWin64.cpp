#include "RenderSurfaceWin64.h"
#include "Debug.h"


namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace Platform
	{

		RenderSurfaceWin64::RenderSurfaceWin64(Rect _viewport) :IRenderSurface(_viewport)
		{
			
		  window = CreateGlfwWindow("RCEngine", screenRect.width, screenRect.height);

			glfwMakeContextCurrent(window);

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

		void RenderSurfaceWin64::Run(std::function<void()>renderFunction, std::function<void()>updateFunction)
		{
			while (!ShouldClose())
			{
				PollEvents();
			 
				updateFunction();
				renderFunction();//Debug::Log("renderBuffer");
			
				SwapBuffers();// Debug::Log("swapBuffer");
				
			}
			
		}
    std::any RenderSurfaceWin64::GetContext()
    {
			return window;
    }
	}
}