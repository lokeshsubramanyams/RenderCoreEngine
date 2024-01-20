#include "IContext.hpp"

using namespace RCEngine::MathLib;
using namespace RCEngine::Platform;
namespace RCEngine
{
	namespace Platform
	{
		RCEngine::Platform::IContext::IContext(MathLib::Rect _viewport)
			:viewport(_viewport)
		{

		}

		Rect IContext::GetViewport()const
		{
			return { viewport.x, viewport.y, viewport.width, viewport.height };
		}

		RCEngine::Platform::IContext::~IContext()
		{

		}
	}
}