#include "IRenderSurface.h"

using namespace RCEngine::Platform;
namespace RCEngine
{
	namespace Platform
	{
		RCEngine::Platform::IRenderSurface::IRenderSurface(Rect _screen)
			:screenRect(_screen)
		{
	
		}

		Rect IRenderSurface::GetSurfaceRect()
		{
			return { screenRect.x, screenRect.y, screenRect.width, screenRect.height };
		}

		void IRenderSurface::PollEvents()
		{

		}

		void IRenderSurface::AddWindowResizeListener(std::function<void(Rect)> windowResizeEventHandler)
		{
			this->windowResizeEventListenser = windowResizeEventHandler;
		}

		RCEngine::Platform::IRenderSurface::~IRenderSurface()
		{
			
		}
	}
}