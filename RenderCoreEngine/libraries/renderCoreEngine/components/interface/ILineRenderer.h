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
			explicit ILineRenderer(Line* line ,IMaterial* mat) :line(line), material(mat), IRenderer(ComponentType::LineRendererComp) {};
			
		};
	}
}