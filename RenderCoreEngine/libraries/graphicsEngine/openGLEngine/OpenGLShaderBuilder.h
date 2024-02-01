#pragma once 
#include "IShaderBuilder.h"
#include <GL/glew.h>//this is there in vcpkg and emsdk
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace Debugger;
		using namespace RenderCore;
		class OpenGLShaderBuilder : public RCEngine::GraphicsEngine::IShaderBuilder
		{
		public:
			std::unordered_map<std::string, std::unique_ptr<RCEngine::RenderCore::IShader>> PreLoadShaderBatch(std::vector<ShaderProgram>programsToLoad, std::unordered_map<std::string, ShaderMetaData> engineMetaData) override;
		private:
			GLuint Compile(ShaderMetaData mData);
			GLuint Compile(ShaderProgram program);
			GLuint LoadShader(ShaderMetaData vertex, ShaderMetaData fragment);
		};
	}
}