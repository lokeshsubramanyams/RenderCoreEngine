#pragma once
#include "IRenderer.h"
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

			IMeshFilter* iMeshFilter;
			explicit IMeshRenderer(IMeshFilter* iFilter,IMaterial*mat):iMeshFilter(iFilter),material(mat),IRenderer(ComponentType::MeshRendererComp) {};

			

		public:
			IMaterial *GetMaterial()override {	return material;}

			IMeshFilter* GetMeshFilter()override {return iMeshFilter;}

			
		};
	}
}