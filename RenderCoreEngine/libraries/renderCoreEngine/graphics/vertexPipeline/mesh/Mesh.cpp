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
			Mesh::Mesh(Vector3 *verts,int vLength)
			{
				this->vertices = verts;
				this->verticesCount = vLength;
			}

			int Mesh::SizeOfVertices()
			{
				return sizeof(Vector3) * this->verticesCount;
			}

      int Mesh::SizeOfVertexDataStructure()
      {
          return sizeof(Vector3);
      }

			Mesh::~Mesh()
			{
				delete vertices;
				delete indices;
			}

		}
	}
}

