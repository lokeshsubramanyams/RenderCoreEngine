#include "RenderCoreEngine.h"
#include "RenderCoreEngine.h"


namespace RCEngine
{
	namespace RenderCore
	{

		void RenderCoreEngine::InitilizeEngine()
		{
			Rect surface{ 0,0,640,480 };
			
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<OpenGL4xEngine>();
#endif

#elif PLATFORM_WEBASSEMBLY
			
			renderSurface = std::make_unique<RenderSurfaceBrowser>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<OpenGL3xEngine>();
#endif

#endif
			
			graphicsEngine->InitilizeEngine();

			Run();


		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
			graphicsEngine->Render();
		}
		void RenderCore::RenderCoreEngine::Run()
		{
			renderSurface->MakeContextCurrent();
			
			std::function<void()> renderFuncPtr = std::bind(&RenderCoreEngine::Renderer, this);

			renderSurface->Run(renderFuncPtr);

		}
	}
}


/*while (!renderSurface->ShouldClose())
{
	renderSurface->PollEvents();
	graphicsEngine->Render();
	renderSurface->SwapBuffers();
}
*/
