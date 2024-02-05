#pragma once 
#include "IComponent.h"
#include "IRequiredComponent.h"
#include "Transform.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class ICamera : public IComponent,public IRequiredComponent<Transform>
		{
		public:
			explicit ICamera(Settings _settings) :IComponent(ComponentType::CameraComp) { setting = _settings; };
			void RequiredComponent(Transform* _transform)override { transform = _transform; };
			virtual void UpdateSettings(Settings setting) = 0;
			
			virtual Matrix44 GetViewProjectionMatrix() = 0;
			virtual Matrix44 GetViewMatrix() = 0;
			virtual Matrix44 GetProjectionMatrix() =0;

		protected:
			Settings setting;
			Transform* transform;
			
			virtual Matrix44 CalculateProjectionMatrix() = 0;
			virtual  Matrix44 CalculateViewMatrix() = 0;
			
		};
	}
}
