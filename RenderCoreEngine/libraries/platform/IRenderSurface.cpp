#include "IRenderSurface.h"

using namespace RCEngine::Platform;
namespace RCEngine
{
	namespace Platform
	{
		RCEngine::Platform::IRenderSurface::IRenderSurface(Rect _viewport)
			:viewport(_viewport)
		{

		}

		Rect IRenderSurface::GetSurfaceRect()
		{
			return { viewport.x, viewport.y, viewport.width, viewport.height };
		}

		void IRenderSurface::PollEvents()
		{

		}

		RCEngine::Platform::IRenderSurface::~IRenderSurface()
		{
			
		}
	}
}