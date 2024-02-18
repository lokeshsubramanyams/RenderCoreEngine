#include "RenderCoreEngine.h"

#include "RenderCoreEngine.h"
#include "MeshUtil.h"
#include "Mesh.h"

#include "Behaviour.h"
#include "Screen.h"
#include "Camera.h"


namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Debugger;
		using namespace Graphics;
		void RenderCoreEngine::OnWindowsResize(Rect screen)
		{
			EngineSetting::SetWindowSurfaceRect(screen);
			graphicsEngine->OnWindowResize(screen);
		}

		void RenderCoreEngine::InitilizeEngine()
		{

			engineSetting = new EngineSetting({ 0,0, 1024, 760 });
		
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(EngineSetting::GetWindowSurfaceRect());
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL4xEngine>();
			uiEngine = std::make_unique<RCEngine::UI::UserInterfaceEngine>(0, "#version 330 core");
#endif

#elif PLATFORM_WEBASSEMBLY

			renderSurface = std::make_unique<RenderSurfaceGlfwBrowser>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL3xEngine>();
			uiEngine = std::make_unique<RCEngine::UI::UserInterfaceEngine>(0, "#version 300 es");
#endif

#endif

			renderSurface->AddWindowResizeListener(std::bind(&RenderCoreEngine::OnWindowsResize, this, std::placeholders::_1));

			renderSurface->WindowPlacementOnBigMonitor();
			
			///////////////////////////////////////////////////////////

			graphicsEngine->InitilizeEngine(EngineSetting::GetWindowSurfaceRect());

			ShaderProgram defaultShaderProgram =
			{
				CONST::SHADERFILE::DEFAULT_VERTEX,CONST::SHADERFILE::DEFAULT_FRAGMENT,CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT,
				{CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX,	CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR}
			};

			graphicsEngine->LoadShaderBatch({ defaultShaderProgram });

			///////////////////////////////////////////////////////////////

			scene = std::make_unique<Scene>(graphicsEngine.get(), "Sample");
			
			//////////////////////////////////////////////////////////////

			scene->AddLines("Lines");
		//	scene->GetGraphicsObject("Lines")->transform->position = Vector3(0, 1, 0);

		  //scene->AddShape("cube", GeometryShapes::Cube);
		//	scene->AttachComponent("cube", new Behaviour(0.5f));

			fps = new FrameRateTracker();
		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
		  scene->Render();
			fps->CalculateFPS();
			uiEngine->Begin();
			uiEngine->UI(scene->GetGraphicsObject("MainCamera"));
			uiEngine->UI(UIText{ {"performance"},std::to_string(fps->Fps()).c_str()});
			uiEngine->End();
		}

		void RenderCoreEngine::Update()
		{
			scene->Update(fps->DeltaTime());
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

