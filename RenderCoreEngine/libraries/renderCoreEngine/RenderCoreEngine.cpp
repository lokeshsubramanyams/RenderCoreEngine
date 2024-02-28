#include "RenderCoreEngine.h"

#include "RenderCoreEngine.h"
#include "MeshUtil.h"
#include "Mesh.h"

#include "Behaviour.h"
#include "Screen.h"
#include "Camera.h"
#include "IMesh.h"

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

			RenderCoreShaderDB shaderdB;

			graphicsEngine->LoadShaderBatch(shaderdB.shadersDB);

			///////////////////////////////////////////////////////////////

			scene = std::make_unique<Scene>(graphicsEngine.get(), "Sample");

			inputHandler = std::make_unique<DesktopInputHandler>(renderSurface.get(), uiEngine.get());

			inputHandler->HandleTransformByInput(scene->GetGraphicsObject("MainCamera")->transform);

			////////////////////////////////////////////////////////////// 

		 	scene->AddShape("sphere", GeometryShapes::Sphere);

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
			uiEngine->UIMenuBar(scene.get());
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

