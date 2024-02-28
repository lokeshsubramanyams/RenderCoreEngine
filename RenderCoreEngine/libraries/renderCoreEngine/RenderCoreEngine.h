#pragma once
#include <memory>

#include "RenderCore.h"

#if  PLATFORM_WINDOWS
#if OPENGL
#include "OpenGL4xEngine.h"
#endif
#include "RenderSurfaceWin64.h"

#elif PLATFORM_WEBASSEMBLY
#if OPENGL
#include "OpenGL3xEngine.h"
#endif
//#include "RenderSurfaceBrowser.h"
#include "RenderSurfaceGlfwBrowser.h"

#endif

#include "IGraphicsEngine.h"
#include "FrameRateTracker.h"
#include "DesktopInputHandler.h"
#include "Debug.h"
#include "GraphicsObject.h"
#include "Camera.h"

#include "UserInterfaceEngine.h"
#include "Scene.h"
#include "RenderCoreShaderDB.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Platform;
		using namespace RCEngine::GraphicsEngine;
		using namespace RCEngine::UI;
		
		class RenderCoreEngine
		{
		private:

			EngineSetting *engineSetting;
			FrameRateTracker* fps;
			void OnWindowsResize(Rect screen);

		public:
			std::unique_ptr<IRenderSurface> renderSurface;
			std::unique_ptr<IGraphicsEngine> graphicsEngine;
			std::unique_ptr<UserInterfaceEngine> uiEngine;

			std::unique_ptr<Scene> scene;
			std::unique_ptr<IInputHandler> inputHandler;

			void InitilizeEngine();
			void Renderer();
			void Update();
			void Run();

			~RenderCoreEngine();
			
		};

	}
}

