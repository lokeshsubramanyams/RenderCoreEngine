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
			Camera(Settings setting);
			~Camera();
			
		 void UpdateSettings(Settings setting)override;
		 Matrix44 GetViewProjectionMatrix()override;
		 Matrix44 GetViewMatrix()override;
		 Matrix44 GetProjectionMatrix()override;

		protected:
		
			
			Vector3 cameraPosition();
			Vector3 cameraForward();
			Vector3 cameraUp();

			float aspectRatio;
			float orthographicScaleFactor = 0.05f;

			Matrix44 CalculateProjectionMatrix()override;
			Matrix44 CalculateViewMatrix()override;

		};
	
	}
}