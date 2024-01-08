#include "OpenGL4x.hpp"


namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL4x::TestAPIs()
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// Draw the triangle
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
	}
}