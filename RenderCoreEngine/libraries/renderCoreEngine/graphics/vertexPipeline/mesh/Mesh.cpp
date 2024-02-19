#include "Mesh.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			Mesh::Mesh(Vector3 *verts,int vlength, int *indices,int iLength)
			{
				this->vertices = verts;
				this->verticesCount = vlength;
				this->indices = indices;
				this->indicesCount = iLength;
			}
			Mesh::Mesh(Vertex* vnt, int vLength, int* indices, int iLength)
			{
				this->vertNormalTex = vnt;
				this->verticesCount = vLength;
				this->indices = indices;
				this->indicesCount = iLength;
			}
			int Mesh::SizeOfVertices()
			{
				return sizeof(Vector3) * this->verticesCount;
			}

      int Mesh::SizeOfVertexDataStructure()
      {
          return sizeof(Vector3);
      }
			int Mesh::SizeOfIndices()
			{
				return sizeof(int) *  this->indicesCount;
			}


			Mesh::~Mesh()
			{
				delete vertices;
				delete indices;
			}

		}
	}
}

