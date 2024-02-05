#pragma once

#include "Rect.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class Screen
		{
		private:
			static int screenWidth;
			static int screenHeight;
		public:
			Screen(MathLib::Rect rect);// { width = rect.width; height = rect.height; }
			static int Width();// { return width; }
			static int Height();// { return height; }

		};
	}
}
