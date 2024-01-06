#pragma once
#include "MathLib.hpp"

namespace RCEngine
{
	namespace Platform
	{
		class Context
		{
		private:
			MathLib::Rect viewport;
		public:
			Context();
			~Context();
			static Context* CreateContext(MathLib::Rect _viewport);
			MathLib::Rect GetViewport();
		};
	}
}