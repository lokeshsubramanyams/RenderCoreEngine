#pragma once
#include<any>
#include <memory>
#include "IUILibrary.h"
#include <GraphicsObject.h>
namespace RCEngine
{
	namespace UI
	{
		class UserInterfaceEngine
		{
		public:
			UserInterfaceEngine(unsigned int windowID, const char* shaderVersion );
			~UserInterfaceEngine();
			
			void Begin();
			void UI();
			void UI(UIText text);
			void UI(RenderCore::GraphicsObject *graphicsObject);
			void End();
		protected:
			std::unique_ptr<IUILibrary> uiLibraryImpl;
		};
	
	

	}
}