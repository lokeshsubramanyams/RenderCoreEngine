#include "RenderCoreEngine.h"
#include "IContext.h"
#include "RenderCore.h"
#if  PLATFORM_WINDOWS
#include "ContextWindows.h"
#elif PLATFORM_WEBASSEMBLY
#include "ContextBrowser.h"
#endif

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Platform;
		void RenderCoreEngine::InitilizeEngine()
		{
			
			IContext* context ;
#if  PLATFORM_WINDOWS
			context = new ContextWindows({ 0,0,640,480 });
#elif PLATFORM_WEBASSEMBLY
			context = new ContextBrowser({ 0,0,640,480 });
#endif


		}
	}
}
