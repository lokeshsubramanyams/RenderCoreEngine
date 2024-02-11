#include "IRenderSurface.h"
#include "GlfwWindow.h"

#include <emscripten/emscripten.h>
#include<emscripten/html5.h>


#include "Test.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;
		using namespace RCEngine::Debugger;
		class RenderSurfaceGlfwBrowser :public IRenderSurface
		{
		private:
			GLFWwindow* glfwCanvas;

			TestUI* UI;
		public:
			RenderSurfaceGlfwBrowser(Rect _viewport);
			~RenderSurfaceGlfwBrowser();
			void MakeContextCurrent()  override;
			bool ShouldClose()  override;
			void SwapBuffers()  override;
			void DestroySurface()  override;
			bool IsValid()const  override;
			void Run(std::function<void()>renderFunction, std::function<void()>updateFunction) override;
			void PollEvents() override;

			void UIRender();

		};
	}
}