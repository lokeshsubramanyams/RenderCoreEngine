#pragma once
#include "IRenderer.h"
#include "MeshFilter.h"
#include "IMaterial.h"
#include "Transform.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class IMeshRenderer : public IRenderer
		{
		protected:
			MeshFilter *meshFilter;
			IMaterial *material;
			explicit IMeshRenderer(MeshFilter* filter, IMaterial* mat):meshFilter(filter), material(mat), IRenderer(ComponentType::MeshRendererComp) {};
		public:
			IMaterial *GetMaterial() {	return material;}
		};
	}
}