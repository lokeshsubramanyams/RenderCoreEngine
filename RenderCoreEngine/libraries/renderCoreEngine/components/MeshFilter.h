#pragma once
#include "Mesh.h"
#include "IComponent.h"
#include "IMesh.h"
#include<vector>
namespace RCEngine
{
	using namespace MathLib;
	using namespace RCEngine::RenderCore::Graphics;
	namespace RenderCore
	{

		class MeshFilter : public IComponent
		{
		public:
			Mesh* mesh;
			MeshFilter(Mesh* mesh);

		};

		class IMeshFilter:public IComponent
		{
		public:
			IMeshAbstract* mesh;
			IMeshFilter(IMeshAbstract* mesh);
			PrimitiveTopology GetToplogy();
			int SizeOfDataStructure();
			std::tuple<void*, int> GetVertices();
			std::vector<int> GetDataStructureSequenceSize();
			std::string GetSequenceHash();
			int GetSequenceTotalElementsCount();

		private:
			std::string squenceHash;
			int sequenceTotalElementsCount;

		};
		
	}
}