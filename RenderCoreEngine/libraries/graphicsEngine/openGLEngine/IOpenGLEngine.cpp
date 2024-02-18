#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
	
		void IOpenGLEngine::InitilizeEngine(Rect viewport)
		{
			if (glewInit() != GLEW_OK)
			{
				Debug::Log("Glew not initilized-some error!");
			}

			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);

			shaderBuilder = std::make_unique<OpenGLShaderBuilder>();
			componentFactory = std::make_unique<OpenGLComponentFactory>();
			
   	}


    void IOpenGLEngine::LoadShaderBatch(std::vector<ShaderProgram> programs)
    {
			shaderBuilder->PreLoadShaderBatch(programs, this->GetShaderMetaData());
    }

		IShader* IOpenGLEngine::GetLoadedShader(std::string shader)
		{
			return shaderBuilder->GetShader(shader);
		}

		IComponentFactory* IOpenGLEngine::GetFactory()
		{
			return componentFactory.get();
		}

    void IOpenGLEngine::OnWindowResize(Rect viewport)
    {
			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
    }
				
		void IOpenGLEngine::PreRenderSetup()
		{
			Rect full = EngineSetting::GetWindowSurfaceRect();

			glScissor(full.x, full.y, full.width, full.height);

			glEnable(GL_SCISSOR_TEST);

			glViewport(full.x, full.y, full.width, full.height);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			glClear(GL_COLOR_BUFFER_BIT);
			
		}

		void IOpenGLEngine::PreRenderSetup(ICamera* camera)
		{
			Rect viewport = camera->viewport->GetViewport();

			glScissor(viewport.x, viewport.y, viewport.width, viewport.height);

			glEnable(GL_SCISSOR_TEST);

			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);

			Vector4 color = camera->setting.backgroundColor;

			glClearColor(color.r, color.g, color.b, color.a);

			glClear(GL_COLOR_BUFFER_BIT);
		}

		void IOpenGLEngine::PostRenderSetup(ICamera* camera)
		{
			//glDisable(GL_SCISSOR_TEST);

		}

		void IOpenGLEngine::PostRenderSetup()
		{
			//glDisable(GL_SCISSOR_TEST);
		}
		
	}
}

