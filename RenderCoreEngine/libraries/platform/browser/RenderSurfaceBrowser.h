#include "IRenderSurface.h"
#include <emscripten/emscripten.h>
#include<emscripten/html5.h>

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;
		
		class RenderSurfaceBrowser :public IRenderSurface
		{
		private:
			EMSCRIPTEN_WEBGL_CONTEXT_HANDLE canvas;
		public:
			RenderSurfaceBrowser(Rect _viewport);
			~RenderSurfaceBrowser();
			void MakeContextCurrent()  override;
			bool ShouldClose()  override;
			void SwapBuffers()  override;
			void DestroySurface()  override;
			bool IsValid()const  override;
			
				
		
		};
	}
}