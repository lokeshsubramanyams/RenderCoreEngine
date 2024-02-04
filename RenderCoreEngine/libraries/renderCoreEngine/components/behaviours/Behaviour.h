#pragma once
#include "IBehaviour.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class Behaviour : public IBehaviour
		{
		public:
			float speed = 0.1f;
			Behaviour(float _speed);
			void Update(float deltaTime) override;
	
		private:
			float testVariable = 1.0f;
			float direction = 1.0f;

		};
	}
} 
