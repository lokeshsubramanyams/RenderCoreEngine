#pragma once 
#include "IShaderBuilder.h"
#include <GL/glew.h>//this is there in vcpkg and emsdk
#include "Debug.h"
#include <utility>

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace Debugger;
		using namespace RenderCore;
		class OpenGLShaderBuilder : public RCEngine::GraphicsEngine::IShaderBuilder
		{
		public:
			void PreLoadShaderBatch(std::vector<ShaderProgram>programsToLoad, std::unordered_map<std::string, ShaderMetaData> engineMetaData) override;
			RCEngine::RenderCore::IShader* GetShader(std::string generatedShaderKey)override;
		private:
			GLuint Compile(ShaderMetaData mData);
			GLuint LoadShader(ShaderMetaData vertices, ShaderMetaData fragment);
			std::unordered_map<std::string,std::unique_ptr<RCEngine::RenderCore::IShader>> shaders;
		};
	}
}