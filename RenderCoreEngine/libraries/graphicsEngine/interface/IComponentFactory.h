#pragma once
#include "IComponent.h"
#include "Mesh.h"
#include "IShader.h"

namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::RenderCore::Graphics;
		class IComponentFactory
		{
		public:
			virtual RCEngine::RenderCore::IComponent *CreateMeshRendererComp(Mesh &mesh,IShader &shader) = 0;
		};
	}
}