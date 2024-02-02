#pragma once
#include "RenderCore.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class IComponent
		{
		public:
			const ComponentType type;
			explicit IComponent(ComponentType t) : type(t) {};
			virtual void LinkTransform(IComponent *component) {};
		};
	}
}