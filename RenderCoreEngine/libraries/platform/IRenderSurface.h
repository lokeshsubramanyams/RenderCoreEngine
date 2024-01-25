#pragma once
#include "MathLib.h"
#include <functional>

namespace RCEngine
{
	namespace Platform
	{
		using namespace MathLib;


		class IRenderSurface
		{
		protected:
			const Rect screenRect;
			
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
			 
			 
		};

		

	}
}