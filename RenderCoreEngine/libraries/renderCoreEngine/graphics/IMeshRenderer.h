#pragma once
#include "IRenderer.h"
#include "Mesh.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::RenderCore::Graphics;
		class IMeshRenderer : public IRenderer
		{
		protected:
			Mesh *mesh;
			IShader *shader;
			explicit IMeshRenderer(Mesh& _mesh, IShader& _shader) :mesh(&_mesh), shader(&_shader), IRenderer(ComponentType::MeshRendererComp){};
		};
	}
}