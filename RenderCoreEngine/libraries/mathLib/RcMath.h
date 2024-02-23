#pragma once

#include<glm.hpp>
#include<gtc/quaternion.hpp>
#include<gtc/type_ptr.hpp>

#include<algorithm>

namespace RCEngine
{
	namespace MathLib
	{
		using namespace glm;
	
		typedef vec2 Vector2;
		typedef vec3 Vector3;
		typedef vec4 Vector4;
		typedef quat Quaternion;
		typedef mat3 Matrix33;
		typedef mat4 Matrix44;
		typedef vec3 Color3;
		typedef vec4 Color4;

		template<typename T>
		T clamp01(T value) {
			return std::clamp(value, T(0), T(1));
		}


	}
}
