#pragma once
#include<string>
namespace RCEngine
{
	struct ShaderProgram
	{
		std::string vertexkey;
		std::string fragmentkey;
		std::string uniformTransformationMatrix;
		std::string uniformFragmentColor;
		std::string generatedShaderKey;
	};

}