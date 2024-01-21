#include "IContext.h"

using namespace RCEngine::Platform;
namespace RCEngine
{
	namespace Platform
	{
		RCEngine::Platform::IContext::IContext(Rect _viewport)
			:viewport(_viewport)
		{

		}

		Rect IContext::GetViewport()
		{
			return { viewport.x, viewport.y, viewport.width, viewport.height };
		}

		RCEngine::Platform::IContext::~IContext()
		{
			
		}
	}
}