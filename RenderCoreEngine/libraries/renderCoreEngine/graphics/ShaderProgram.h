#pragma once
#include<string>
#include<vector>

namespace RCEngine
{
	struct ShaderProgram
	{
		std::string vertexkey;
		std::string fragmentkey;
		std::string generatedShaderKey;
		std::vector<const char*> uniformKeys;
	};

}