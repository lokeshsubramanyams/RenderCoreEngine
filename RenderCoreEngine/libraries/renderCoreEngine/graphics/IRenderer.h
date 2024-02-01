#pragma once
#include "IComponent.h"
#include "IShader.h"
namespace RCEngine
{
	namespace RenderCore
	{
		
		class IRenderer : public IComponent
		{
		public:

			explicit IRenderer(ComponentType t) :IComponent(t) {}

			virtual void Load() = 0;

			virtual void LoadInBatch() = 0;

			virtual void Render() = 0;


		};
	}
}