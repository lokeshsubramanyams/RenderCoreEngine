#pragma once 
#include "ShaderProgram.h"
#include "IShader.h"
#include "ShaderMetaData.h"
#include <unordered_map>
#include <vector>
#include <memory>
namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RenderCore;
		class IShaderBuilder
		{
		public:
			virtual void PreLoadShaderBatch(std::vector<ShaderProgram>programsToLoad, std::unordered_map<std::string, ShaderMetaData> engineMetaData) = 0;

			virtual RCEngine::RenderCore::IShader* GetShader(std::string generatedShaderKey) = 0;

		};
	}
}