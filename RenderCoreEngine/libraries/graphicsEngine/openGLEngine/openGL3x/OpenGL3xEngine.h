#pragma once
#include "../IOpenGLEngine.h"
#include <GLES3/gl3.h>
#include "Debug.h"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		using namespace RCEngine::Debugger;
		class OpenGL3xEngine : public IOpenGLEngine
		{
		public:
			void InitilizeEngine(Rect viewport) const override;
			void  RenderLoop() override;
			std::unordered_map<std::string, ShaderMetaData> GetShaderMetaData()override;
		};

	}
}