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

			renderSurface = std::make_unique<RenderSurfaceGlfwBrowser>(EngineSetting::GetWindowSurfaceRect());
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

			ShaderProgram defaultShaderProgramV01 =
			{
				CONST::SHADERFILE::DEFAULT_VERTEX_V01,
				CONST::SHADERFILE::DEFAULT_FRAGMENT_V01,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01,
				{
					CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_MODEL_MATRIX,
			  	CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_VIEW_MATRIX,
					CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_PROJECTION_MATRIX,
					CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_LIGHTDIR,
					CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_LIGHTCOLOR,
					CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_OBJECTCOLOR

				}
			};

			graphicsEngine->LoadShaderBatch({ defaultShaderProgram,defaultShaderProgramV01 });

			IShader* defaultShaderv1 = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01);
			defaultShaderv1->Log();

			///////////////////////////////////////////////////////////////

			scene = std::make_unique<Scene>(graphicsEngine.get(), "Sample");
			
			//////////////////////////////////////////////////////////////

		 // scene->AddShape("cube", GeometryShapes::Cube);
		//	scene->GetGraphicsObject("cube")->transform->position = Vector3(0, 0, 10);
			//scene->AttachComponent("cube", new Behaviour(0.25f));

			Vector3 forward =  scene->GetGraphicsObject("DirectionLight")->transform->forward();

			IShader* defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);

			Vector3 p1 = Vector3(0.0f, 0.0f, 0.0f);
			Vector3 p2 = p1 + forward * 10.0f;
			Vector3 *vertices = new Vector3[2]{ p1,p2 };
			Line* lines = new Line(vertices, 2);
			IComponent* component = graphicsEngine->GetFactory()->CreateLineRendererComp(*lines, *defaultShader);
			

		 	scene->AddShape("sphere", GeometryShapes::Sphere);
			scene->GetGraphicsObject("sphere")->transform->scale = Vector3(0.5, 0.5, 0.5);
			scene->AttachComponent("sphere", component);
		   scene->AttachComponent("sphere", new Behaviour(0.25f));


			fps = new FrameRateTracker();
		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
		  scene->Render();
			fps->CalculateFPS();
			uiEngine->Begin();
			uiEngine->UI(scene.get());
			uiEngine->UI(UIText{ {"Stats"},std::to_string(fps->Fps()).c_str() });
			uiEngine->UI(scene->GetGraphicsObject(scene->sceneHierarchySelectedKey));
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

