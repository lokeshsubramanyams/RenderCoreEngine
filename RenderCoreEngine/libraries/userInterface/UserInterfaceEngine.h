#pragma once
#include<any>
#include <memory>
#include "IUILibrary.h"
#include "UserInterface.h"
namespace RCEngine
{
	namespace UI
	{
		class UserInterfaceEngine
		{
		public:
			UserInterfaceEngine(unsigned int windowID, const char* shaderVersion );
			~UserInterfaceEngine();
			
			void UIRender(UIText text);
			
		protected:
			std::unique_ptr<IUILibrary> uiLibraryImpl;
		};
	
	

	}
}