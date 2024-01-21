#include "RenderCoreEngine.h"
#include "RenderCoreEngine.h"


namespace RCEngine
{
	namespace RenderCore
	{

		void RenderCoreEngine::InitilizeEngine()
		{
			
			
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(Rect{ 0,0,640,480 });
#if (OPENGL)
			graphicsEngine = std::make_unique<OpenGL4xEngine>();
#endif

#elif PLATFORM_WEBASSEMBLY
			
			renderSurface = std::make_unique<RenderSurfaceBrowser>(Rect{ 0,0,640,480 });
#if (OPENGL)
			graphicsEngine = std::make_unique<OpenGL3xEngine>();
#endif

#endif
			
			graphicsEngine->InitilizeEngine();

			Run();


		}
		void RenderCore::RenderCoreEngine::Run()
		{
			renderSurface->MakeContextCurrent();

			while (!renderSurface->ShouldClose())
			{
				renderSurface->PollEvents();
				graphicsEngine->Render();
				renderSurface->SwapBuffers();
			}
			
		}
	}
}
