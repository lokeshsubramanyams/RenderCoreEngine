#pragma once
#include "IBehaviour.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class Behaviour : public IBehaviour
		{
		public:
			void Update(float deltaTime) override;
		};
	}
} 
