#pragma once
#include "MathLib.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			using namespace RCEngine::MathLib;
			class Line
			{
			public:
				Vector3* vertices;
				int verticesCount;
			
				Line(Vector3* verts, int vLength);
				int SizeOfVertices();
				int SizeOfVertexDataStructure();
			
				~Line();

			};
		}

	}
}