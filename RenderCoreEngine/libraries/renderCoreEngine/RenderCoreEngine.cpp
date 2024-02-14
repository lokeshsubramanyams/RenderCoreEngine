
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
		void RenderCoreEngine::InitilizeEngine()
		{
			Rect surface{ 0,0,1024,760 };

			
			
#if  PLATFORM_WINDOWS
			
			renderSurface = std::make_unique<RenderSurfaceWin64>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL4xEngine>();

			uiEngine = std::make_unique<RCEngine::UI::UserInterfaceEngine>(0, "#version 330 core");
#endif

#elif PLATFORM_WEBASSEMBLY
			
			renderSurface = std::make_unique<RenderSurfaceGlfwBrowser>(surface);
#if (OPENGL)
			graphicsEngine = std::make_unique<RCEngine::OpenGLEngine::OpenGL3xEngine>();
			uiEngine = std::make_unique<RCEngine::UI::UserInterfaceEngine>(renderSurface.get()->GetContext(), "#version 300 es");
#endif


#endif

			
			
			ShaderProgram defaultShaderProgram =
			{
				CONST::SHADERFILE::DEFAULT_VERTEX,
				CONST::SHADERFILE::DEFAULT_FRAGMENT,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT,

				{CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX,
					CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR}

			};
		

			
			///////////////////////////////////////////////////////////

			graphicsEngine->InitilizeEngine(surface);

			graphicsEngine->LoadShaderBatch({ defaultShaderProgram });

			IShader *defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);

			defaultShader->Log();

			///////////////////////////////////////////////////////////////

			RCEngine::CameraSetting  cameraSetting = {
				CameraType::Perspective,
				45.0f,
				0.1f,
				1000.0f
			};

			RCEngine::Settings settings = {
				surface,
				cameraSetting
			};

			GraphicsObject* cameraObject = new GraphicsObject("MainCamera");
			Camera* camera = new Camera(settings);
			cameraObject->AttachComponent(camera);

			cameraObject->transform->position = Vector3(0.0f, 0.3f, -1.0f);

			graphicsEngine->SetCamera(camera);
			/////////////////////////////////////////////////////////////

			
		/*	triangle = new GraphicsObject("TestTriangle");
			Mesh* mesh = MeshUtil::Triangle();
			IComponent* component =  graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh, *defaultShader);
			triangle->AttachComponent(component);
			IBehaviour *behaviour = new Behaviour(0.1f);
			triangle->AttachComponent(behaviour);
			triangle->transform->scale = Vector3(0.5f, 0.5f, 0.5f);
			graphicsEngine->Render(static_cast<IRenderer*>(component));
			
			quad = new GraphicsObject("TestQuad");
			Mesh* mesh1 = MeshUtil::Quad();
			IComponent* component1 = graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh1, *defaultShader);
			quad->AttachComponent(component1);
			IBehaviour* behaviour1 = new Behaviour(5.0f);
			quad->AttachComponent(behaviour1);
			quad->transform->scale = Vector3(0.5f, 0.5f, 0.5f);

			graphicsEngine->Render(static_cast<IRenderer*>(component1));
			*/

			cube = new GraphicsObject("TestCube");
			Mesh* mesh2 = MeshUtil::GeometricalShapes(GeometryShapes::Cube);
			IComponent* component2 = graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh2, *defaultShader);
			cube->AttachComponent(component2);
			IBehaviour* behaviour2 = new Behaviour(0.25f);
			cube->AttachComponent(behaviour2);

			cube->transform->scale = Vector3(0.5f,0.5f, 0.5f);

			graphicsEngine->Render(static_cast<IRenderer*>(component2));

			
			
			//////////////////////////////////////////////////////////////
			fps = new FrameRateTracker();

			
		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
			

		  graphicsEngine->RenderLoop();
			fps->CalculateFPS();

			uiEngine->UIRender(UIText{ { "Performance"}, string("fps:" + std::to_string(fps->Fps())).c_str() });

			
		}
		void RenderCoreEngine::Update()
		{
			//Debug::Log("DeltaTime:", fps->DeltaTime());
			//graphicsEngine->UpdateLoop(fps->DeltaTime());
			//triangle->Update(fps->DeltaTime());
			//quad->Update(fps->DeltaTime());
			
			cube->Update(fps->DeltaTime());

			
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
			delete cube;
			delete quad;
			delete triangle;
		}
	}
}

