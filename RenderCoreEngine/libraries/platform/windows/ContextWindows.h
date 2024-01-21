#include "IContext.h"
#include<GLFW/glfw3.h>
namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;

		class ContextWindows :public IContext
		{
		private:
			 GLFWwindow* window;
		public:
			ContextWindows(Rect _viewport);
			~ContextWindows();
			void makeContextCurrent()  override;
			bool shouldClose()  override;
			void swapBuffers()  override;
			void DestroyContext()  override;
			bool IsValidContext() override;
		};
	}
}