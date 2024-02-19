#pragma once
#include "ILight.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class DirectionalLight :public ILight
		{
		public:
			DirectionalLight();
			
			Vector3 GetLightDirection() override;

		};

	}
}