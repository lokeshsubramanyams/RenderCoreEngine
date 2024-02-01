#pragma once
#include "RcMath.h"

namespace RCEngine
{
	namespace MathLib
	{
		struct Transform
		{
			Vector3 position;
			Quaternion rotation;
			Vector3 scale;
			Transform(Vector3 _pos, Quaternion _rot, Vector3 _scale)
			{
				position = _pos;
				rotation = _rot;
				scale = _scale;
			}
			Matrix44 GetTransformationMatrix()
			{
				 Matrix44 translation =  glm::translate(Matrix44(1.0f), position);
				 Matrix44 roation = glm::mat4_cast(rotation);
				 Matrix44 scaleMat = glm::scale(Matrix44(1.0f), scale);
				 return translation * roation * scaleMat;
			}
		};
	}
}