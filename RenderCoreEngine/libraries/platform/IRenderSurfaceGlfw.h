#pragma once 
#include "IRenderSurface.h"
#include "GlfwWindow.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;

		class IRenderSurfaceGlfw :public IRenderSurface
		{
		protected:
			GLFWwindow* window;

		public:

			IRenderSurfaceGlfw(Rect _viewport);
			virtual ~IRenderSurfaceGlfw();
		
			void AddWindowResizeListener(std::function<void(Rect)>windowResizeEventHandler)override;
			void AddMousePositionListener(std::function<void(double, double)>mousePosEventHandler)override;
			void AddMouseClickListener(std::function<void(int, int, int)>mouseClickEventHandler)override;
			void AddMouseScrollListener(std::function<void(double, double)>mouseScrollEventHandler)override;

			virtual void FramebufferResizeCallback(GLFWwindow* window, Rect newViewport);
			virtual void MousePositionCallback(GLFWwindow* window, double x, double y);
			virtual void MouseClickCallback(GLFWwindow* window, int button,int action,int mods);
			virtual void MouseScrollCallback(GLFWwindow* window, double x, double y);

		};
	}
}