#include "OpenGL4xEngine.h"
#include "OpenGL4xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void OpenGL4xEngine::InitilizeEngine() const
		{
			IOpenGLEngine::InitilizeEngine();
		}

		void OpenGL4xEngine::RenderLoop()
		{
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			
			for (int i = 0; i < vBufferCount; i++)
			{
			  glBindBuffer(GL_ARRAY_BUFFER, vb[0]);
			  glEnableVertexAttribArray(0);
			  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);
			  glDrawArrays(GL_TRIANGLES, 0, 3);
			  glDisableVertexAttribArray(0);
			}
				
		}
		std::vector<ShaderMetaData> OpenGL4xEngine::GetShaderMetaData()
		{
			std::vector<ShaderMetaData>data;
			data.push_back(defaultVertShader);
			data.push_back(defaultFragShader);
			return data;
		}
	}
}
