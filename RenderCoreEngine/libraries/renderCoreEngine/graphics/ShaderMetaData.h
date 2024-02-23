#pragma once 

#include "RenderCore.h"
#include <string>
#include<vector>
namespace RCEngine
{
	struct UniformVertexConst
	{
		static constexpr char modelMatrix[] = "MODEL_MATRIX";
		static constexpr char viewMatrix[] = "VIEW_MATRIX";
		static constexpr char projectionMatrix[] = "PROJECTION_MATRIX";
	};
	struct UniformMeta
	{
		const char* name;
		VariableType variableType;
	};
	struct ShaderMetaData
	{
		const char* source;
		int  length;
		RCEngine::ShaderType shaderType;
		const char* shaderKey;
		std::vector<UniformMeta> uniforms;
	};

}

