#pragma once
#include "IRenderer.h"
#include "MeshFilter.h"
#include "IMaterial.h"
#include "Transform.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		
		class IMeshRenderer : public IRenderer
		{
		protected:
			MeshFilter *meshFilter;
			IMaterial *material;
			explicit IMeshRenderer(MeshFilter* filter, IMaterial* mat):meshFilter(filter), material(mat), IRenderer(ComponentType::MeshRendererComp) {};

		};
	}
}