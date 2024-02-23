#include "DirectionalLight.h"
#include "Debug.h"
namespace RCEngine
{
	namespace RenderCore
	{
		DirectionalLight::DirectionalLight()
		{
			lightColor = Vector3(1.0f, 1.0f, 1.0f);
		}
		Vector3 DirectionalLight::GetLightDirection()
		{
			return transform->forward();
		}

	}
}