#include "IContext.h"
#include <emscripten/emscripten.h>
#include<emscripten/html5.h>

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;
		
		class ContextBrowser :public IContext
		{
		private:
			EMSCRIPTEN_WEBGL_CONTEXT_HANDLE canvas;
		public:
			ContextBrowser(Rect _viewport);
			~ContextBrowser();
			void makeContextCurrent()  override;
			bool shouldClose()  override;
			void swapBuffers()  override;
			void DestroyContext()  override;
			bool IsValidContext() override;
		};
	}
}