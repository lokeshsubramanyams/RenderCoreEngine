#pragma once
#include "IComponent.h"
#include "Mesh.h"
#include "IShader.h"

namespace RCEngine
{
	namespace GraphicsEngine
	{
		class IComponentFactory
		{
		public:
			virtual RCEngine::RenderCore::IComponent* CreateMeshRendererComp(RCEngine::RenderCore::Graphics::Mesh &mesh, RCEngine::RenderCore::IShader &shader) = 0;
		};
	}
}