#include "OpenGL4xEngine.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL4xEngine::InitilizeEngine() const
		{

		}
	  void OpenGL4xEngine::Render()
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(testVariable, 0.3f, 0.3f, 1.0f);
		}
	}
}
