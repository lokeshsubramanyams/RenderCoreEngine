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
				CONST::SHADERFILE::DEFAULT_VERTEX,
				CONST::SHADERFILE::DEFAULT_FRAGMENT,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT
				
			};

			ShaderProgram defaultShaderProgramV01 =
			{
				CONST::SHADERFILE::DEFAULT_VERTEX_V01,
				CONST::SHADERFILE::DEFAULT_FRAGMENT_V01,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01
			
			};

			graphicsEngine->LoadShaderBatch({ defaultShaderProgram,defaultShaderProgramV01 });

			IShader* defaultShaderv1 = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01);
			defaultShaderv1->Log();

			///////////////////////////////////////////////////////////////

			scene = std::make_unique<Scene>(graphicsEngine.get(), "Sample");

			inputHandler = std::make_unique<DesktopInputHandler>(renderSurface.get(), uiEngine.get());

			inputHandler->HandleTransformByInput(scene->GetGraphicsObject("MainCamera")->transform);

			//////////////////////////////////////////////////////////////

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
		  

			scene->AddShape("sphere1", GeometryShapes::Sphere);
			scene->GetGraphicsObject("sphere1")->transform->position = Vector3(0, 0, 10);

			scene->AddShape("sphere2", GeometryShapes::Sphere);
			scene->GetGraphicsObject("sphere2")->transform->position = Vector3(0, 0, 20);
			 
			scene->AddShape("Cube", GeometryShapes::Cube);
			scene->GetGraphicsObject("Cube")->transform->position = Vector3(0, 0, 30);



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

