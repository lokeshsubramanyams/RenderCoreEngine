#pragma once 
#include "MathLib.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			using namespace RCEngine::MathLib;
			class Mesh
			{
			public:
				Vector3* vertices;
				int verticesCount;
				int* indices;
				int indicesCount;


				Mesh(Vector3 *verts,int vLength, int *indices,int iLength);
				int SizeOfVertices();
				int SizeOfVertexDataStructure();
				int SizeOfIndices();

				~Mesh();

			};
		}
		
	}
}