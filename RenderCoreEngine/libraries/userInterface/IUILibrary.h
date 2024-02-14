#pragma once
#include<any>
#include "UserInterface.h"
#include <GraphicsObject.h>
namespace RCEngine
{
	namespace UI
	{
		class IUILibrary
		{
		public:
			
			virtual void UIRender(const char* title, const char* str) = 0;

			virtual void UIRender(RenderCore::GraphicsObject *gObject) = 0;

			virtual void ShutDown() = 0;

		};
	}
}