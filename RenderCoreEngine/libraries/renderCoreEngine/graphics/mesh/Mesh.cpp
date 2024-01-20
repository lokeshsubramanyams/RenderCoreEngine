#include "Mesh.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			Mesh::Mesh(Vector3 verts[], int indices[])
			{
				this->vertices = verts;
				this->indices = indices;
			}
			Mesh::~Mesh()
			{
				delete vertices;
				delete indices;
			}
		}
	}
}

