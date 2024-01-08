#include "IContext.hpp"
//#include<emscripten.h>

namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::MathLib;
		
		class ContextBrowser :public IContext
		{
		public:
			ContextBrowser(MathLib::Rect _viewport);
			~ContextBrowser();

		};
	}
}