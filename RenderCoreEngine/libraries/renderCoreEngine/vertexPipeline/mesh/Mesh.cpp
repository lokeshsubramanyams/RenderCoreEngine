#include "Mesh.hpp"

namespace RCEngine
{
	namespace RenderCore
	{
		VertexEngine::Mesh::Mesh(Vector3 verts[], int indices[])
		{
			this->vertices = verts;
			this->indices = indices;
		}
		VertexEngine::Mesh::~Mesh()
		{
			delete vertices;
			delete indices;
		}
	}
}

