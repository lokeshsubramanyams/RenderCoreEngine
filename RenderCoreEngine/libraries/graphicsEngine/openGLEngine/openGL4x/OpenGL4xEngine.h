#pragma once
#include "../IOpenGLEngine.h"

//#include <GLFW/glfw3.h>

#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL4xEngine : public IOpenGLEngine
		{
		public:

  		void  Render() override;
			
		};

	}
}