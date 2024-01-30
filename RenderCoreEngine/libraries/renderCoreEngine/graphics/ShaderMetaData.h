#pragma once 

#include "RenderCore.h"
#include <string>

namespace RCEngine
{
	struct ShaderMetaData
	{
		const char* source;
		int  length;
		RCEngine::ShaderType shaderType;
		const std::string shaderKey;
		const char* unifromKey;
	};
}

