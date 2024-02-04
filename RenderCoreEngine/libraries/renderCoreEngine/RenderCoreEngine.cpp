#include "RenderCoreEngine.h"
#include "MeshUtil.h"
#include "Mesh.h"

#include "Behaviour.h"


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
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT,

				{CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX,
				CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLORVEC4}

			};
		

			
			///////////////////////////////////////////////////////////
			graphicsEngine->InitilizeEngine(surface);

			graphicsEngine->LoadShaderBatch({ defaultShaderProgram });

			IShader *defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);

			defaultShader->Log();

			triangle = new GraphicsObject("TestTriangle");
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
			IBehaviour* behaviour1 = new Behaviour(0.5f);
			quad->AttachComponent(behaviour1);

			quad->transform->scale = Vector3(0.5f, 0.5f, 0.5f);

			graphicsEngine->Render(static_cast<IRenderer*>(component1));



			fps = new FrameRateTracker();
			//////////////////////////////////////////////////////////////
			
		}
		void RenderCore::RenderCoreEngine::Renderer()
		{
		  graphicsEngine->RenderLoop();
			fps->CalculateFPS();
		}
		void RenderCoreEngine::Update()
		{
			//Debug::Log("DeltaTime:", fps->DeltaTime());
			//graphicsEngine->UpdateLoop(fps->DeltaTime());
			triangle->Update(fps->DeltaTime());
			quad->Update(fps->DeltaTime());
			
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

