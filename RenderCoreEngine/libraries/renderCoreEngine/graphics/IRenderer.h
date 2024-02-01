#pragma once
#include "IComponent.h"
#include "IShader.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class IRenderer : public IComponent
		{
		protected:
			IShader shader;
		};
	}
}