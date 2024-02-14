#include "Camera.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace Debugger;
	namespace RenderCore
	{
		Camera::Camera(Settings _setting):ICamera(_setting)
		{
			UpdateSettings(_setting);
		}
		Camera::~Camera()
		{
			
		}
		void Camera::UpdateSettings(Settings _setting)
		{
			this->setting = _setting;
			aspectRatio = (float)setting.screen.width / (float)setting.screen.height;
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
			
			if (setting.cameraSettings.cameraType == CameraType::Perspective)
			{
				float fov = glm::radians(setting.cameraSettings.fieldOfView);
				//float aspectRatio = setting.screen.width / setting.screen.height;
				float nearPlane = setting.cameraSettings.nearZ;
				float farPlane = setting.cameraSettings.farZ;

				return glm::perspective(fov, aspectRatio, nearPlane, farPlane);
			}
			else if(setting.cameraSettings.cameraType == CameraType::Orthographic)
			{
				float scaleFactor = 1.0f/orthographicScaleFactor;

				float left = 0.0f;
				float right = (float)setting.screen.width;
				float bottom = 0.0f;
				float top = (float)setting.screen.height;
				float zNear = setting.cameraSettings.nearZ;
				float zFar =  setting.cameraSettings.farZ;

				float aspectRatio = (float)setting.screen.width / (float)setting.screen.height;
				float orthoHeight = (float)setting.screen.height * scaleFactor;
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
			glm::mat4 viewMatrix = glm::lookAt(cameraPosition(), cameraForward(), cameraUp());

			return viewMatrix;
		}
	}
}