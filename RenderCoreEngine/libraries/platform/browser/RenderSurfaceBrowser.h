#include "IRenderSurface.h"
#include <emscripten/emscripten.h>
#include<emscripten/html5.h>
#include "FramesPerSecond.h"
namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;
		using namespace RCEngine::Debugger;
		class RenderSurfaceBrowser :public IRenderSurface
		{
		private:
			EMSCRIPTEN_WEBGL_CONTEXT_HANDLE canvas;
			FramesPerSecond *fps;
		public:
			RenderSurfaceBrowser(Rect _viewport);
			~RenderSurfaceBrowser();
			void MakeContextCurrent()  override;
			bool ShouldClose()  override;
			void SwapBuffers()  override;
			void DestroySurface()  override;
			bool IsValid()const  override;
			void Run(std::function<void()>renderFunction) override;
			void RenderLoop();// void* arg);
		
		};
	}
}