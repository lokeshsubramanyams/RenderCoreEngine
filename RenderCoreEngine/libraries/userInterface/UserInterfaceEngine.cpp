#include "UserInterfaceEngine.h"
#include "ImguiLibraryOpenGL3.h"
#include "Debug.h"
namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace UI
	{
		UserInterfaceEngine::UserInterfaceEngine(std::any context, const char* shaderVersion)
		{
			Debug::Log("user interface engine");
			uiLibraryImpl = std::make_unique<RCEngine::UI::ImguiLibraryOpenGL3>(context,shaderVersion);
		}
		

		void UserInterfaceEngine::UIRender(UIText text)
		{
			uiLibraryImpl->UIRender(text.title, text.text);
		}
		
		

		UserInterfaceEngine::~UserInterfaceEngine()
		{
			uiLibraryImpl->ShutDown();
		}
		
	}
}

