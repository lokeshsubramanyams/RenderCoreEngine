#pragma once 
#include "RenderCore.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class IUpdate
		{
		public:
			virtual void Update(float deltaTime) = 0;
		};
	}

}
