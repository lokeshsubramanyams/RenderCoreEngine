#include "IRenderSurface.h"
#include<GLFW/glfw3.h>
namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;

		class RenderSurfaceWin64 :public IRenderSurface
		{
		private:
			 GLFWwindow* window;
		public:
			RenderSurfaceWin64(Rect _viewport);
			~RenderSurfaceWin64();
			void MakeContextCurrent()  override;
			bool ShouldClose()  override;
			void SwapBuffers()  override;
			void DestroySurface()  override;
			bool IsValid()const override;
			void PollEvents() override;
			void Run(std::function<void()>renderFunction) override;
		};
	}
}