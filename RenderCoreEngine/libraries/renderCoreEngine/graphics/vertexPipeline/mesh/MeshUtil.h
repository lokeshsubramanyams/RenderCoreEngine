#pragma once

#include "MathLib.h"
#include "Mesh.h"
namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{

			using namespace RCEngine::MathLib;
			class MeshUtil
			{
			public:
				static Mesh *ClipperTriangle();

			};
		}

	}
}