#pragma once 
#include "IComponentFactory.h"
#include "OpenGLMeshRenderer.h"
#include "OpenGLShader.h"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::GraphicsEngine;
		using namespace RCEngine::RenderCore::Graphics;
		class OpenGLComponentFactory:public IComponentFactory
		{
		public:
			RCEngine::RenderCore::IComponent *CreateMeshRendererComp(Mesh& mesh, IShader& shader) override;

		};
	}
}