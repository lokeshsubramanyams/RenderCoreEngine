#include "OpenGL4xEngine.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		OpenGL4xEngine::OpenGL4xEngine()
		{

		}
		void OpenGL4xEngine::InitilizeEngine() const
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		}
		void OpenGL4xEngine::Render()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
}
