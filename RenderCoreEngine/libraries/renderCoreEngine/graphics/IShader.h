#pragma once
#include "RcMath.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class IShader
		{
		public:
		
			virtual void UseProgram() = 0;
			
			virtual void ApplyProperty(const char* uniformKey, MathLib::Matrix44& value);
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector4& value);
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector3& value);
			virtual void ApplyProperty(const char* uniformKey, MathLib::Vector2& value);

		
			 

		};
	}
}