#pragma once
//#include <GLFW/glfw3.h>
#include "../IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL4xEngine : public IOpenGLEngine
		{
		public:
			void InitilizeEngine() const override;
  		void  RenderLoop() override;
			std::vector<ShaderMetaData> GetShaderMetaData()override;
			
		};

	}
}