#include "MeshFilter.h"

namespace RCEngine
{
	namespace RenderCore
	{
		MeshFilter::MeshFilter(Mesh *_mesh):IComponent(ComponentType::MeshFilterComp)
		{
			mesh = _mesh;


		}

		IMeshFilter::IMeshFilter(IMeshAbstract* mesh) :mesh(mesh),IComponent(ComponentType::MeshFilterComp)
		{
			squenceHash = "";
			sequenceTotalElementsCount = 0;
			for (int i = 0; i < mesh->GetDataStructureSequenceSize().size(); i++)
			{
				squenceHash += std::to_string(mesh->GetDataStructureSequenceSize()[i]) + "_";

				sequenceTotalElementsCount += mesh->GetDataStructureSequenceSize()[i];

			}
			Debugger::Debug::Log("Mesh Sequence string hash:", squenceHash.c_str());
			Debugger::Debug::Log("Mesh Sequence total :", sequenceTotalElementsCount);

		}
		
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
		std::string IMeshFilter::GetSequenceHash()
		{
			return squenceHash;
		}
		int IMeshFilter::GetSequenceTotalElementsCount()
		{
			return sequenceTotalElementsCount;
		}
		
	}
}

