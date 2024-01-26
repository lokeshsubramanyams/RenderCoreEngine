#include "RenderCoreEngine.h"


namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Debugger;
		void RenderCoreEngine::InitilizeEngine()
		{
			Rect surface{ 0,0,640,480 };
			
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL4xEngine>();
#endif

#elif PLATFORM_WEBASSEMBLY
			
			renderSurface = std::make_unique<RenderSurfaceBrowser>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL3xEngine>();
#endif

#endif
			
			graphicsEngine->InitilizeEngine();
			fps = new FrameRateTracker();
			Run();


		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
			graphicsEngine->Render();
			fps->CalculateFPS();
		}
		void RenderCoreEngine::Update()
		{
			Debug::Log("Fps:", fps->Fps());
			graphicsEngine->Update(fps->DeltaTime());
		}
		void RenderCore::RenderCoreEngine::Run()
		{
			renderSurface->MakeContextCurrent();
			
			std::function<void()> renderFuncPtr = std::bind(&RenderCoreEngine::Renderer, this);
			std::function<void()> updateFuncPtr = std::bind(&RenderCoreEngine::Update, this);

			renderSurface->Run(renderFuncPtr, updateFuncPtr);

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
