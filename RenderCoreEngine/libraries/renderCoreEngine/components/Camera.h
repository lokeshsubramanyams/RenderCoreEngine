#pragma once
#include "MathLib.h"
#include "RenderCore.h"
#include "ICamera.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::MathLib;

		class Camera :public ICamera
		{
		public:
			Camera(CameraSetting setting);
			~Camera();
			
		 void UpdateSettings(CameraSetting setting)override;
		 Matrix44 GetViewProjectionMatrix()override;
		 Matrix44 GetViewMatrix()override;
		 Matrix44 GetProjectionMatrix()override;

		 float orthographicScaleFactor = 20.0f;

		protected:
		
			
			Vector3 cameraPosition();
			Vector3 cameraForward();
			Vector3 cameraUp();

			float aspectRatio;
			

			Matrix44 CalculateProjectionMatrix()override;
			Matrix44 CalculateViewMatrix()override;

		};
	
	}
}