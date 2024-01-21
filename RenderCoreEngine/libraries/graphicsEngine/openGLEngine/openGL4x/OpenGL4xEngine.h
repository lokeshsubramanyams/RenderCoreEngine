#pragma once
#include "IGraphicsEngine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL4xEngine : public IGraphicsEngine
		{
		public:
			OpenGL4xEngine();
			void  InitilizeEngine()const override;
			void  Render() override;
		};

	}
}