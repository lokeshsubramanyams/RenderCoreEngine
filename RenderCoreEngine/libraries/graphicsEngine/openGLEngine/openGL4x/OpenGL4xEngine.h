#pragma once
#include "../IOpenGLEngine.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL4xEngine : public IOpenGLEngine
		{
		public:
			void  InitilizeEngine()const override;
			void  Render() override;
		};

	}
}