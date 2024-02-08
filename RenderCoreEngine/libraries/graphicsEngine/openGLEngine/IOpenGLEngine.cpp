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

    

		void IOpenGLEngine::SetCamera(ICamera *camera)
		{
			this->camera = camera;
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

		void IOpenGLEngine::Render(RCEngine::RenderCore::IRenderer* renderer)
		{
			renderer->Load();
			renderers.push_back(renderer);

		}
	
		void IOpenGLEngine::RegisterCustomShader(ShaderMetaData customShader) const
		{

		}
		Matrix44 IOpenGLEngine::GetProjectionViewMatrix()
		{
			if (this->camera != nullptr)
			{
				return camera->GetProjectionMatrix() * camera->GetViewMatrix();
			}
			return Matrix44(1.0f);
	  }
	}
}

