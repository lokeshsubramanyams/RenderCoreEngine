#include "OpenGL4xEngine.h"
#include "OpenGL4xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void OpenGL4xEngine::InitilizeEngine(Rect viewport) const
		{
			IOpenGLEngine::InitilizeEngine(viewport);
		}

		void OpenGL4xEngine::RenderLoop()
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
				
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
