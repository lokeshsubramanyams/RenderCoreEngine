#pragma once
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
			void InitilizeEngine(Rect viewport) override;
  		void  RenderLoop() override;
			std::unordered_map<std::string, ShaderMetaData> GetShaderMetaData()override;
		  
		};

	}
}