#pragma once
#include<any>
namespace RCEngine
{
	namespace UI
	{
		class IUILibrary
		{
		public:
			virtual void UIRender() = 0;
			
			virtual void UIRender(const char* title, const char* str) = 0;

			virtual void ShutDown() = 0;

		};
	}
}