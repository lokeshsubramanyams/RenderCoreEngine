#include "UserInterfaceEngine.h"
#include "UserInterfaceEngine.h"
#include "ImguiLibraryOpenGL3.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace UI
	{
		UserInterfaceEngine::UserInterfaceEngine(unsigned int windowID, const char* shaderVersion)
		{
			Debug::Log("user interface engine");
			uiLibraryImpl = std::make_unique<RCEngine::UI::ImguiLibraryOpenGL3>(windowID,shaderVersion);
		}
		

		void UserInterfaceEngine::Begin()
		{
			uiLibraryImpl->Begin();
		}

		void UserInterfaceEngine::UI()
		{
			uiLibraryImpl->UI();
		}

		void UserInterfaceEngine::UI(UIText text)
		{
			uiLibraryImpl->UI(text.title, text.text);
		}

    void UserInterfaceEngine::UI(RenderCore::GraphicsObject *graphicsObject)
    {
			uiLibraryImpl->UI(graphicsObject);
    }

		void UserInterfaceEngine::UI(RenderCore::Scene* scene)
		{
			uiLibraryImpl->UI(scene);
		}

		void UserInterfaceEngine::End()
		{
			uiLibraryImpl->End();
		}
		
		

		UserInterfaceEngine::~UserInterfaceEngine()
		{
			uiLibraryImpl->ShutDown();
		}
		
	}
}

