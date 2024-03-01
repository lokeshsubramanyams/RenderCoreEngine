#pragma once 
#include "IRenderer.h"
#include "RcMath.h"
#include "IMaterial.h"
#include "Line.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace MathLib;
		using namespace RCEngine::RenderCore::Graphics;
		class ILineRenderer:public IRenderer
		{
		public:
			IMaterial* material;
			Line* line;
			Color4 color;
			explicit ILineRenderer(Line* line ,IMaterial* mat) :line(line), material(mat), IRenderer(ComponentType::LineRendererComp) {};
			
			IMaterial* GetMaterial()override { return material; }

			IMeshFilter* GetMeshFilter()override { return nullptr; }

		};
	}
}