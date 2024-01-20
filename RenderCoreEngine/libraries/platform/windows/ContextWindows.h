#include "IContext.h"

#include<GLFW/glfw3.h>

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;

		class ContextWindows :public IContext
		{
		public:
			ContextWindows(MathLib::Rect _viewport);
			~ContextWindows();

		};
	}
}