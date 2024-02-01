#pragma once 
#include "IRenderer.h"
#include "RcMath.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace MathLib;

		class ILineRenderer:public IRenderer
		{
		protected:
			Vector3[] linePoints;
		};
	}
}