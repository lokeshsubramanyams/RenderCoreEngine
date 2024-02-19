#pragma once
#pragma once
#include "IComponent.h"
#include "IRequiredComponent.h"
#include "Transform.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class ILight :public IComponent,public IRequiredComponent<Transform>
		{
		public:
			explicit ILight() :IComponent(ComponentType::LightComp) {};
			void RequiredComponent(Transform* _transform)override { transform = _transform; };
			
			virtual Vector3 GetLightDirection() = 0;

			Vector3 lightColor;
			float lightIntensity;
		protected:
			Transform* transform;


		};

	}
}