#pragma once
#include "RcMath.h"
#include "IComponent.h"
namespace RCEngine
{
	using namespace MathLib;
	namespace RenderCore
	{
		
		class Transform : public  RCEngine::RenderCore::IComponent
		{
		public:
			Vector3 position;
			Quaternion rotation;
			Vector3 scale;
			Transform();
			Transform(Vector3 _pos, Quaternion _rot, Vector3 _scale);
			Matrix44 GetMatrix();

			Vector3 forward();
			Vector3 up();
			Vector3 right();

			Vector3 EularAnglesInDegrees();
			Vector3 EularAnglesRadians();
			void ApplyEularAnglesInDegree();

			Vector3 eularAnglesInDegrees;
			
		};
	}
}