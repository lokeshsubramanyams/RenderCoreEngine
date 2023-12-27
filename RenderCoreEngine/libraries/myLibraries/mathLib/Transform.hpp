#pragma once
#include <Math.hpp>
namespace RCEngine::MathLib
{
	struct Transform
	{
		Vector3 position;
		Quaternion rotation;
		Vector3 Scale;
	};
}