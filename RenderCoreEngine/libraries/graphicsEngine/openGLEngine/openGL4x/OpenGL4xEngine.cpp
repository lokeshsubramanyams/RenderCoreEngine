#include "OpenGL4xEngine.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
	  void OpenGL4xEngine::Render()
		{
			glClear(GL_COLOR_BUFFER_BIT);
			//glClearColor(testVariable, 0.3f, 0.3f, 1.0f);

			//for (int i = 0; i < vBufferCount; i++)
			//{
				//Debug::Log("vb:", i);
			  glBindBuffer(GL_ARRAY_BUFFER, vb[0]);
			  glEnableVertexAttribArray(0);
			  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);
			  glDrawArrays(GL_TRIANGLES, 0, 3);
			  glDisableVertexAttribArray(0);
			//}

		}
	}
}
