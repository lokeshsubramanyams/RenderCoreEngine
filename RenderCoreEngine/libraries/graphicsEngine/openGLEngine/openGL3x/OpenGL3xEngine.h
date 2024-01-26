#pragma once
#include "../IOpenGLEngine.h"
#include <GLES3/gl3.h>
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL3xEngine : public IOpenGLEngine
		{
		public:
			//void  InitilizeEngine()const override;
			void  Render() override;
			
		};

	}
}