#include "OpenGL4xEngine.h"
#include "OpenGL4xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void OpenGL4xEngine::InitilizeEngine(Rect viewport)
		{
			IOpenGLEngine::InitilizeEngine(viewport);
		}

		void OpenGL4xEngine::RenderLoop()
		{
			
		}

		std::unordered_map<std::string, ShaderMetaData> OpenGL4xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}
	}
}
