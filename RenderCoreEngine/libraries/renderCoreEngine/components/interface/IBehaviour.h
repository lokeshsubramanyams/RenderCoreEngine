#pragma once
#include "IComponent.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class IBehaviour : public IComponent
		{
		public:
			explicit IBehaviour():IComponent(ComponentType::BehaviourComp) {};
			virtual void Update(float deltaTime) = 0;
		};
	}
}