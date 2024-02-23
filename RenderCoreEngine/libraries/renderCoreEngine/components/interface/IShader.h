#pragma once
#include<vector>
#include "RcMath.h"
#include <ShaderMetaData.h>

namespace RCEngine
{
	namespace RenderCore
	{
		class IShader
		{
		public:
		  
			IShader(std::vector<UniformMeta> uniforms) {uniformMeta = uniforms;}

			virtual void UseProgram() = 0;
			
			virtual void ApplyProperty(const char* uniformKey, MathLib::Matrix44 value) = 0;
			virtual void ApplyProperty(const char* uniformKey, MathLib::Matrix33 value) = 0;
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector4 value) = 0;
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector3 value) = 0;
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector2 value) = 0;
			virtual void ApplyProperty(const char* uniformKey, float value) = 0;
			virtual void ApplyProperty(const char* uniformKey, int value) = 0;
			

			virtual void Log() = 0;

			 std::vector<UniformMeta> uniformMeta;
			 

		};
	}
}