#include "OpenGL3xEngine.h"
#include "OpenGL3xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL3xEngine::InitilizeEngine(Rect viewport)
		{
			Debug::Log("Viewport:",viewport);
			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
			
			shaderBuilder = std::make_unique<OpenGLShaderBuilder>();
			componentFactory = std::make_unique<OpenGLComponentFactory>();
		}

		void OpenGL3xEngine::RenderLoop()
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (int i = 0; i < renderers.size(); i++)
			{
				renderers[i]->Render(GetProjectionViewMatrix());
			}

		}
		std::unordered_map<std::string, ShaderMetaData> OpenGL3xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}

	}
}
