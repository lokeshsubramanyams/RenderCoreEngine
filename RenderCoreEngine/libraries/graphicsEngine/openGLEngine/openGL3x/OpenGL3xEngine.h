#pragma once
#include "IGraphicsEngine.h"
#include <GLES3/gl3.h>
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL3xEngine : public IGraphicsEngine
		{
		public:
			void  InitilizeEngine()const override;
			void  Render() override;
		};

	}
}