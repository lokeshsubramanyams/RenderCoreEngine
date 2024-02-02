#pragma once 
#include "IComponent.h"
#include "IShader.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		class IMaterial:public IComponent
		{
		public:
			IShader* shader;
			explicit IMaterial(IShader *_shader) :shader(_shader),IComponent(ComponentType::MaterialComp) {};
		};
	}
}