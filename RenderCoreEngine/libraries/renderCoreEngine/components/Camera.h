#pragma once
#include "MathLib.h"
#include "IComponent.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::MathLib;

		class Camera :public IComponent
		{
		public:
			Camera();
			~Camera();

		};
	
	}
}