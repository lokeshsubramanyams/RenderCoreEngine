#include "MeshFilter.h"

namespace RCEngine
{
	namespace RenderCore
	{
		MeshFilter::MeshFilter(Mesh *_mesh):IComponent(ComponentType::MeshFilterComp)
		{
			mesh = _mesh;
		}
	}
}

