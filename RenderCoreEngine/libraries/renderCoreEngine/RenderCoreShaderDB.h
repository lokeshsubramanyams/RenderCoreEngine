#pragma once
#include<vector>
#include <ShaderProgram.h>
#include <RenderCore.h>

namespace RCEngine
{
	class RenderCoreShaderDB
	{
	public:
		std::vector<ShaderProgram> shadersDB =
		{
			{
				CONST::SHADERFILE::DEFAULT_VERTEX,
				CONST::SHADERFILE::DEFAULT_FRAGMENT,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT

			},
			{
				CONST::SHADERFILE::DEFAULT_VERTEX_V01,
				CONST::SHADERFILE::DEFAULT_FRAGMENT_V01,
				CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01
			}
		};
	};
}