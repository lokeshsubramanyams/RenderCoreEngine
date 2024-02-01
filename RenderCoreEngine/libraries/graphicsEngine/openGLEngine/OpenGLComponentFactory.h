#pragma once 
#include "IComponentFactory.h"
#include "OpenGLMeshRenderer.h"
#include "OpenGLShader.h"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::GraphicsEngine;
		class OpenGLComponentFactory:public IComponentFactory
		{
		public:
			RCEngine::RenderCore::IComponent* CreateMeshRendererComp(RCEngine::RenderCore::Graphics::Mesh& mesh, IShader& shader) override;

		};
	}
}