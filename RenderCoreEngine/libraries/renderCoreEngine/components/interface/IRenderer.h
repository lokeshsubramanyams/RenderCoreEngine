#pragma once
#include "IComponent.h"
#include "IShader.h"
#include "Transform.h"
namespace RCEngine
{
	namespace RenderCore
	{
		
		class IRenderer : public IComponent
		{
		public:
			Transform* thisTransform;

			explicit IRenderer(ComponentType t) :IComponent(t) {}

			virtual void Load() = 0;

			virtual void LoadInBatch() = 0;

			virtual void Render() = 0;
		protected:
			virtual void LinkTransform(IComponent* transform) { thisTransform = static_cast<Transform*>(transform); };



		};
	}
}