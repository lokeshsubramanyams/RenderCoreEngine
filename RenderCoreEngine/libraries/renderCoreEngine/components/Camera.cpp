#include "Camera.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace Debugger;
	namespace RenderCore
	{
		Camera::Camera(CameraSetting _setting):ICamera(_setting)
		{
			UpdateSettings(_setting);
		}
		Camera::~Camera()
		{
			
		}
		void Camera::UpdateSettings(CameraSetting _setting)
		{
			this->setting = _setting;
			
		}
		Matrix44 Camera::GetViewProjectionMatrix()
		{
			return CalculateProjectionMatrix() * CalculateViewMatrix();
		}

		Matrix44 Camera::GetViewMatrix()
		{
			return CalculateViewMatrix();
		}

		Matrix44 Camera::GetProjectionMatrix()
		{
			return CalculateProjectionMatrix();
		}

		Vector3 Camera::cameraPosition()
		{
			return transform->position;
		}
		Vector3 Camera::cameraForward()
		{
			return glm::normalize(transform->forward());
		}
		Vector3 Camera::cameraUp()
		{
			return glm::normalize(transform->up());
		}

		Matrix44 Camera::CalculateProjectionMatrix()
		{
			Rect viewport = this->viewport->GetViewport();
			//Debug::Log("Width:", viewport.width);
		 //Debug::Log("Height:", viewport.height);

			aspectRatio = (float)viewport.width / (float)viewport.height;

			if (setting.cameraType == CameraType::Perspective)
			{
				float fov = glm::radians(setting.fieldOfView);
				float nearPlane = setting.nearZ;
				float farPlane = setting.farZ;

				return glm::perspective(fov, aspectRatio, nearPlane, farPlane);
			}
			else if(setting.cameraType == CameraType::Orthographic)
			{
				float scaleFactor = 1.0f/orthographicScaleFactor;

				float left = 0.0f;
				float right = (float)viewport.width;
				float bottom = 0.0f;
				float top = (float)viewport.height;
				float zNear = setting.nearZ;
				float zFar =  setting.farZ;

				float orthoHeight = (float)viewport.height * scaleFactor;
				float orthoWidth = orthoHeight * aspectRatio;
						
				left = -orthoWidth *0.5f;
				right = orthoWidth *0.5f;
				bottom = -orthoHeight *0.5f;
				top = orthoHeight *0.5f;

				
				return glm::ortho(left, right, bottom, top, zNear, zFar);
			}

			return Matrix44(1.0f);
		}
		Matrix44 Camera::CalculateViewMatrix()
		{
			glm::mat4 viewMatrix = glm::lookAt(cameraPosition(), cameraPosition()+cameraForward(), cameraUp());

			return viewMatrix;
		}
	}
}