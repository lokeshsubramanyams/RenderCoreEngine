#include "IContext.hpp"

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