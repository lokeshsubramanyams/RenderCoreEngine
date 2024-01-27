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
			
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			
			for (int i = 0; i < vBufferCount; i++)
			{
			  glBindBuffer(GL_ARRAY_BUFFER, vb[0]);
			  glEnableVertexAttribArray(0);
			  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE,3*sizeof(double), 0);
			  glDrawArrays(GL_TRIANGLES, 0, 3);
			  glDisableVertexAttribArray(0);
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
