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
			
			virtual void Begin() = 0;
			virtual void End() = 0;

			virtual void UI() = 0;

			virtual void UI(const char* title, const char* str) = 0;

			virtual void UI(RenderCore::GraphicsObject *gObject) = 0;

			virtual void ShutDown() = 0;

		};
	}
}