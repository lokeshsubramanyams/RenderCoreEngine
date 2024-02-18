#include "Line.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			Line::Line(Vector3* verts, int vlength)
			{
				this->vertices = verts;
				this->verticesCount = vlength;
			}

			int Line::SizeOfVertices()
			{
				return sizeof(Vector3) * this->verticesCount;
			}

			int Line::SizeOfVertexDataStructure()
			{
				return sizeof(Vector3);
			}
		
			Line::~Line()
			{
				delete vertices;
			}

		}
	}
}

