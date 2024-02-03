#pragma once
#include "IComponent.h"
#include "IRequiredComponent.h"
#include "Transform.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class IBehaviour : public IComponent,IRequiredComponent<Transform>
		{
		protected:
			Transform* transform;
		public:
			explicit IBehaviour():IComponent(ComponentType::BehaviourComp) {};
			void RequiredComponent(Transform* trans)override { transform = trans; }
			virtual void Update(float deltaTime) = 0;
		};
	}
}