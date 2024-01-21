#include "OpenGL3xEngine.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{

		void OpenGL3xEngine::InitilizeEngine() const
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		}
		void OpenGL3xEngine::Render()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
}
