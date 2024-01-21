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
#include "RenderSurfaceBrowser.h"

#endif

#include "IGraphicsEngine.h"



namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Platform;
		using namespace RCEngine::GraphicsEngine;
		using namespace RCEngine::OpenGLEngine;
		class RenderCoreEngine
		{
		public:
			std::unique_ptr<IRenderSurface> renderSurface;
			std::unique_ptr<IGraphicsEngine> graphicsEngine;
			void InitilizeEngine();
			void Renderer();
			void Run();
			
		};

	}
}

