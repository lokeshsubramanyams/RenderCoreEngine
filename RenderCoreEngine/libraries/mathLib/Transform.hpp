#pragma once
#include "Math.hpp"

namespace RCEngine
{
	namespace MathLib
	{
		struct Transform
		{
			Vector3 position;
			Quaternion rotation;
			Vector3 Scale;
			Transform(Vector3 _pos, Quaternion _rot, Vector3 _scale)
			{
				position = _pos;
				rotation = _rot;
				Scale = _scale;
			}
		};
	}
}