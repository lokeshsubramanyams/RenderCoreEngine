#pragma once
#include "MathLib.h"
#include <functional>
#include<any>

#include "Test.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace MathLib;


		class IRenderSurface
		{
		protected:
			const Rect screenRect;
			std::function<void(Rect)>windowResizeEventListenser;
		public:

			 IRenderSurface(Rect surfaceInfo);
			 virtual ~IRenderSurface();
			 Rect GetSurfaceRect();
			 virtual void MakeContextCurrent() = 0;
			 virtual bool ShouldClose() = 0;
			 virtual void SwapBuffers() = 0;
			 virtual bool IsValid() const = 0;
			 virtual void DestroySurface() = 0;
			 virtual void Run(std::function<void()>renderFunction,std::function<void()>updateFunction) = 0;
       virtual void PollEvents();
			 
			 virtual std::any GetContext() = 0;
			
			 virtual void AddWindowResizeListener(std::function<void(Rect)>windowResizeEventHandler);
			 
			 virtual void WindowPlacementOnBigMonitor() = 0;
			 
		};

		

	}
}