#include "Transform.h"

namespace RCEngine
{
	namespace RenderCore
	{
		Transform::Transform() :IComponent(ComponentType::TransformComp)
		{
			position = Vector3(0,0,0);
			rotation = Quaternion(0,0,0,0);
			scale = Vector3(1,1,1);
		}
		Transform::Transform(Vector3 _pos, Quaternion _rot, Vector3 _scale):IComponent(ComponentType::TransformComp)
		{
			position = _pos;
			rotation = _rot;
			scale = _scale;
		}
		Matrix44 Transform::GetMatrix()
		{
			Matrix44 translation = glm::translate(Matrix44(1.0f), position);
			Matrix44 roation = glm::mat4_cast(rotation);
			Matrix44 scaleMat = glm::scale(Matrix44(1.0f), scale);
			return translation * roation * scaleMat;
		}
	}
}