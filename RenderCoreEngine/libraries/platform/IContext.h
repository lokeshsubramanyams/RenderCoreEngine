#pragma once
#include "MathLib.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace MathLib;
		class IContext
		{
		protected:
			const Rect viewport;
		public:
			 IContext(Rect viewport);
			 virtual ~IContext();
			 Rect GetViewport();
			 virtual void makeContextCurrent()  = 0;
			 virtual bool shouldClose()  = 0;
			 virtual void swapBuffers()  = 0;
			 virtual void DestroyContext()  = 0;
			 virtual bool IsValidContext() = 0;
		};
	}
}