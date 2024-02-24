#include "RenderSurfaceWin64.h"
#include "Debug.h"


namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace Platform
	{

		RenderSurfaceWin64::RenderSurfaceWin64(Rect _viewport) :IRenderSurfaceGlfw(_viewport)
		{
			
		  window = CreateGlfwWindow("RCEngine", screenRect.width, screenRect.height);

			glfwMakeContextCurrent(window);
			
			resizeCallBack = std::bind(&RenderSurfaceWin64::FramebufferResizeCallback, this, std::placeholders::_1, std::placeholders::_2);

			cursorPositionCallBack = std::bind(&RenderSurfaceWin64::MousePositionCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

			mouseClickCallBack = std::bind(&RenderSurfaceWin64::MouseClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

			mouseScrollCallBack = std::bind(&RenderSurfaceWin64::MouseScrollCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);;
			
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
				renderFunction();
			
				SwapBuffers();
				
			}
			
		}

    void RenderSurfaceWin64::WindowPlacementOnBigMonitor()
    {

			GLFWmonitor* highResMonitor = GetMonitorWithHighestResolution();
			if (!highResMonitor) {
				std::cerr << "Failed to get highResMonitor monitor" << std::endl;
				return;
			}
			const GLFWvidmode* mode = glfwGetVideoMode(highResMonitor);

			int monitorX, monitorY;

			glfwGetMonitorPos(highResMonitor, &monitorX, &monitorY);

			int left, right, top, bottom;
			glfwGetWindowFrameSize(window, &left, &top, &right, &bottom);

			int windowWidth = mode->width - (left+right);
			int windowHeight = mode->height - (top+bottom);

			int windowX = monitorX;// +(mode->width - windowWidth) / 2;
			int windowY = monitorY;// +(mode->height - windowHeight) / 2;

			std::cout <<"width:" << windowWidth <<"height:"<< windowHeight<< std::endl;
			std::cout << "windowX:" << windowX << "windowY:" << windowY << std::endl;

			glfwSetWindowPos(window, windowX+left, windowY+top);
			glfwSetWindowSize(window, windowWidth, windowHeight);

    }

		GLFWmonitor* RenderSurfaceWin64::GetMonitorWithHighestResolution()
		{
			int monitorCount;
			GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
			if (monitorCount == 0) {
				return nullptr;
			}

			GLFWmonitor* highestResMonitor = monitors[0];
			const GLFWvidmode* highestResMode = glfwGetVideoMode(highestResMonitor);

			for (int i = 0; i < monitorCount; ++i) 
			{
				const GLFWvidmode* mode = glfwGetVideoMode(monitors[i]);

				int monitorX, monitorY;
				glfwGetMonitorPos(monitors[i], &monitorX, &monitorY);

				std::cout << "monitor: " << glfwGetMonitorName(monitors[i])
					<< " (" << mode->width << "x" << mode->height << ")" <<"x:"<< monitorX <<"y:"<< monitorY << std::endl;

	
				if ((mode->width * mode->height) >= (highestResMode->width * highestResMode->height)) {
					highestResMonitor = monitors[i];
					highestResMode = mode;
				}

				
			}

			return highestResMonitor;
		}

    std::any RenderSurfaceWin64::GetContext()
    {
			return window;
    }
	}
}