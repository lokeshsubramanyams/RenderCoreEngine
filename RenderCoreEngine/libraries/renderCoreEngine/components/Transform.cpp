#include "Transform.h"
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
	namespace RenderCore
	{
		Transform::Transform() :IComponent(ComponentType::TransformComp)
		{
			position = Vector3(0,0,0);
			rotation = Quaternion();
			scale = Vector3(1,1,1);

			eularAnglesInDegrees = EularAnglesInDegrees();
			Debug::Log("->", eularAnglesInDegrees);
		}
		Transform::Transform(Vector3 _pos, Quaternion _rot, Vector3 _scale):IComponent(ComponentType::TransformComp)
		{
			position = _pos;
			rotation = _rot;
			scale = _scale;
			eularAnglesInDegrees = EularAnglesInDegrees();
			Debug::Log("->", eularAnglesInDegrees);
		}
		Matrix44 Transform::GetMatrix()
		{
			Matrix44 translation = glm::translate(Matrix44(1.0f), position);
			Matrix44 roation = glm::mat4_cast(rotation);
			Matrix44 scaleMat = glm::scale(Matrix44(1.0f), scale);
			return translation * roation * scaleMat;
		}
		Vector3 Transform::forward() {

			Quaternion quaternion = glm::normalize(rotation);
			glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
			
			return  glm::normalize(glm::vec3(rotationMatrix[0][2], rotationMatrix[1][2], rotationMatrix[2][2]));
		}
		Vector3 Transform::up() {
			
			Quaternion quaternion = glm::normalize(rotation);
			glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
			return glm::normalize(glm::vec3(rotationMatrix[0][1], rotationMatrix[1][1], rotationMatrix[2][1]));

		}
		Vector3 Transform::right() {
			Quaternion quaternion = glm::normalize(rotation);
			glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
			return glm::normalize(glm::vec3(rotationMatrix[0][0], rotationMatrix[1][0], rotationMatrix[2][0]));
		}

		Vector3 Transform::EularAnglesRadians()
		{
			return glm::eulerAngles(rotation);
		}
		
		Vector3 Transform::EularAnglesInDegrees()
		{
			return glm::degrees(EularAnglesRadians());
		}

		void Transform::ApplyEularAnglesInDegree()
		{
			rotation = Quaternion(Vector3(glm::radians(eularAnglesInDegrees.x), glm::radians(eularAnglesInDegrees.y), glm::radians(eularAnglesInDegrees.z)));
		}

		void Transform::Rotation(Quaternion rotation)
		{
			this->rotation = rotation;
			this->eularAnglesInDegrees = EularAnglesInDegrees();
		}
	}
}