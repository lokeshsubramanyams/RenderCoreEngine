#include "MeshUtil.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			Mesh *MeshUtil::ClipperTriangle()
			{
				Vector3 *vertices = new Vector3[3];
				vertices[0] = Vector3(-1.0, -1.0, 0.0);
				vertices[1] = Vector3(1.0, -1.0, 0.0);
				vertices[2] = Vector3(0.0, 1.0, 0.0);
				Mesh* mesh = new Mesh(vertices);

				return mesh;
			}
			
		}

	}
}