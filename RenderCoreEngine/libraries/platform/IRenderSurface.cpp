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

		RCEngine::Platform::IRenderSurface::~IRenderSurface()
		{
			
		}
	}
}