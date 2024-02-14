#pragma once 
namespace RCEngine
{
	namespace UI
	{
		struct UIElement
		{

		};
		struct UIWindow
		{
			const char* title;
		};

		struct UIText :UIWindow
		{
			const char* text;
		};
	}
}