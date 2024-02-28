#include "MeshFilter.h"

namespace RCEngine
{
	namespace RenderCore
	{
		MeshFilter::MeshFilter(Mesh *_mesh):IComponent(ComponentType::MeshFilterComp)
		{
			mesh = _mesh;
		}

		IMeshFilter::IMeshFilter(IMeshAbstract* mesh) :mesh(mesh),IComponent(ComponentType::MeshFilterComp){}
		
		PrimitiveTopology IMeshFilter::GetToplogy()
		{
			return mesh->GetToplogy();
		}

		int IMeshFilter::SizeOfDataStructure()
		{
			return mesh->SizeOfVertexDataStructure();
		}

		std::tuple<void*, int> IMeshFilter::GetVertices()
		{
			return mesh->GetVertices();
		}
		
		std::vector<int> IMeshFilter::GetDataStructureSequenceSize()
		{
			return mesh->GetDataStructureSequenceSize();
		}
	}
}

