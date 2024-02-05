#include "Screen.h"

namespace RCEngine
{
	namespace RenderCore
	{
		int Screen::screenWidth = 0;
		int Screen::screenHeight = 0;
		Screen::Screen(MathLib::Rect rect) { screenWidth = rect.width; screenHeight = rect.height; }
		int Screen::Width() { return screenWidth; }
		int Screen::Height() { return screenHeight; }

	}
}