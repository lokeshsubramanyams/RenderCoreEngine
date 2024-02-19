#pragma once 
#include "MathLib.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			using namespace RCEngine::MathLib;

			struct Vertex
			{
				Vector3 position;
				Vector3 normal;
				Vector2 texCoord;
			};

			class Mesh
			{
			public:
				Vector3* vertices;

				Vertex* vertNormalTex;

				int verticesCount;
				int* indices;
				int indicesCount;


				Mesh(Vector3 *verts,int vLength, int *indices,int iLength);

				Mesh(Vertex* vnt, int vLength, int* indices, int iLength);

				int SizeOfVertices();
				int SizeOfVertexDataStructure();
				int SizeOfIndices();

				int SizeOfVertNormalTex();
				int SizeOfVertNormalTexDataStructure();

				~Mesh();

			};
		}
		
	}
}