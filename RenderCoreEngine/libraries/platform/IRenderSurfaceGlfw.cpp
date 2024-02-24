#include "IRenderSurfaceGlfw.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;

		IRenderSurfaceGlfw::IRenderSurfaceGlfw(Rect _viewport):IRenderSurface(_viewport){
   	}

		IRenderSurfaceGlfw::~IRenderSurfaceGlfw(){	}

		void IRenderSurfaceGlfw::FramebufferResizeCallback(GLFWwindow* window, Rect newViewport)
		{
			if (this->window != window)return;

			if (windowResizeEventListenser)
			{
				windowResizeEventListenser(newViewport);
			}
		}

		void IRenderSurfaceGlfw::MousePositionCallback(GLFWwindow* window, double x, double y)
		{
			if (this->window != window)return;

			if (mousePositionEventListenser)
			{
				mousePositionEventListenser(x,y);
			}
		}

		void IRenderSurfaceGlfw::MouseClickCallback(GLFWwindow* window, int button, int action, int mods)
		{
			if (this->window != window)return;

			if (mouseClickEventListener)
			{
				mouseClickEventListener(button, action,mods);
			}
		}

		void IRenderSurfaceGlfw::MouseScrollCallback(GLFWwindow* window, double x, double y)
		{
			if (this->window != window)return;

			if (mouseScrollEventListener)
			{
				mouseScrollEventListener(x, y);
			}
		}

		void IRenderSurfaceGlfw::AddWindowResizeListener(std::function<void(Rect)> windowResizeEventHandler)
		{
			this->windowResizeEventListenser = windowResizeEventHandler;
		}
		void IRenderSurfaceGlfw::AddMousePositionListener(std::function<void(double, double)>mousePosEventHandler)
		{
			this->mousePositionEventListenser = mousePosEventHandler;
		}
		void IRenderSurfaceGlfw::AddMouseClickListener(std::function<void(int, int, int)>mouseClickEventHandler)
		{
			this->mouseClickEventListener = mouseClickEventHandler;
		}
		void IRenderSurfaceGlfw::AddMouseScrollListener(std::function<void(double, double)>mouseScrollEventHandler)
		{
			this->mouseScrollEventListener = mouseScrollEventHandler;
		}



	}
}