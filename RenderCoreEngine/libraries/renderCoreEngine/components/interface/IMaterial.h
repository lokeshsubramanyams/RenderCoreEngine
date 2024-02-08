#pragma once 
#include "IComponent.h"
#include "IShader.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::MathLib;
		class IMaterial:public IComponent
		{
		public:
			IShader* shader;
			explicit IMaterial(IShader *_shader) :shader(_shader),IComponent(ComponentType::MaterialComp) {};
			virtual void ApplyDefaultColor() = 0;

		};
	}
}