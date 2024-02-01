#include "RenderCoreEngine.h"
#include "MeshUtil.h"
#include "Mesh.h"




namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Debugger;
		using namespace Graphics;
		void RenderCoreEngine::InitilizeEngine()
		{
			Rect surface{ 0,0,640,480 };
			
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL4xEngine>();
#endif

#elif PLATFORM_WEBASSEMBLY
			
			renderSurface = std::make_unique<RenderSurfaceBrowser>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL3xEngine>();
#endif

#endif

			ShaderProgram defaultShaderProgram =
			{
				CONST::SHADERFILE::DEFAULT_VERTEX,
				CONST::SHADERFILE::DEFAULT_FRAGMENT,
				CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX,
				CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLORVEC4,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT

			};
		

			
			///////////////////////////////////////////////////////////
			graphicsEngine->InitilizeEngine(surface);

		//std::unordered_map<std::string,ShaderMetaData> shadersMeta =  graphicsEngine->GetShaderMetaData();

			fps = new FrameRateTracker();
			//////////////////////////////////////////////////////////////
			
		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
		// graphicsEngine->RenderLoop();
			//fps->CalculateFPS();
		}
		void RenderCoreEngine::Update()
		{
			//Debug::Log("DeltaTime:", fps->DeltaTime());
			//graphicsEngine->UpdateLoop(fps->DeltaTime());
		}
		void RenderCore::RenderCoreEngine::Run()
		{
			renderSurface->MakeContextCurrent();
			
			std::function<void()> renderFuncPtr = std::bind(&RenderCoreEngine::Renderer, this);
		 	std::function<void()> updateFuncPtr = std::bind(&RenderCoreEngine::Update, this);

			renderSurface->Run(renderFuncPtr, updateFuncPtr);

		}
		RenderCoreEngine::~RenderCoreEngine()
		{
			delete fps;
		
		}
	}
}

