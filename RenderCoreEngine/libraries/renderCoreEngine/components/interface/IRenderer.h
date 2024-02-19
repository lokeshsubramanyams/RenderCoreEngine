#pragma once
#include "IComponent.h"
#include "IShader.h"
#include "Transform.h"
#include "IRequiredComponent.h"
#include "Camera.h"

namespace RCEngine
{
	namespace RenderCore
	{
		
		class IRenderer : public IComponent,IRequiredComponent<Transform>
		{

		protected:
			Transform* transform;
		public:
		
			explicit IRenderer(ComponentType t) :IComponent(t) {}

			virtual void Load() = 0;

			virtual void LoadInBatch() = 0;

			virtual void Render() = 0;

			virtual void Render(Matrix44 matrix) = 0;

			virtual void Render(ICamera* camera) = 0;

			virtual void UnLoad() = 0;

			void RequiredComponent(Transform* trans)override { transform = trans; }

		};
	}
}