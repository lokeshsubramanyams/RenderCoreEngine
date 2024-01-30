#pragma once

#include<glm.hpp>
#include<gtc/quaternion.hpp>

namespace RCEngine
{
	namespace MathLib
	{
		using namespace glm;
#if PRECISION_DOUBLE
		typedef highp_dvec2 Vector2;
		typedef highp_dvec3 Vector3;
		typedef highp_dvec4 Vector4;
		typedef highp_dquat Quaternion;
		typedef highp_dmat4 Matrix44;
#else				

		typedef highp_f32vec2 Vector2;
		typedef highp_f32vec3 Vector3;
		typedef highp_f32vec4 Vector4;
		typedef highp_f32quat Quaternion;
		typedef highp_f32mat4 Matrix44;
#endif
	}
}
