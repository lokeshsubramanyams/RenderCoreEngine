#pragma once 

#include "RenderCore.h"

namespace RCEngine
{
	namespace RenderCore
	{
		template<typename CompType>
		class IRequiredComponent
		{
		public:
			virtual void RequiredComponent(CompType* _component)=0;
			virtual ~IRequiredComponent() = default;
		};
	}
	
}
