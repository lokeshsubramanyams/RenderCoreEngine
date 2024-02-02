#pragma once

#include "IMaterial.h"
#include <GL/glew.h>

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		class OpenGLMaterial : public IMaterial
		{
		public:
			OpenGLMaterial(IShader *shader);

		};
	}
}