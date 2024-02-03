#pragma once 

#include "RenderCore.h"

namespace RCEngine
{
	namespace RenderCore
	{
		template<typename CompType>
		class IRequiredComponent
		{
		protected:
			virtual void RequiredComponent(CompType* _component)=0;
		};
	}
	
}
