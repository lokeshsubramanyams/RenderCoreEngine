#include "OpenGL4xEngine.h"
#include "OpenGL4xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void OpenGL4xEngine::InitilizeEngine(Rect viewport)
		{
			IOpenGLEngine::InitilizeEngine(viewport);
		}

		void OpenGL4xEngine::RenderLoop()
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (int i = 0; i < renderers.size(); i++)
			{
				renderers[i]->Render(GetProjectionViewMatrix());
			}
				
		}

		std::unordered_map<std::string, ShaderMetaData> OpenGL4xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}
	}
}
