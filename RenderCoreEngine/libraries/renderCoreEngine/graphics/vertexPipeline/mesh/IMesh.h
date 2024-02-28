#pragma once
#include<type_traits>
#include "RenderCore.h"
#include<vector>
#include <cassert>
#include "Debug.h"

namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{
			struct VertexBase
			{
				RCEngine::MathLib::Vector3 position;
			};
			struct VertexNormal :VertexBase
			{
				RCEngine::MathLib::Vector3 normal;
			};
			struct VertexNormalTexCoord :VertexNormal
			{
				RCEngine::MathLib::Vector2 texCoord;
			};


			class IMeshAbstract
			{
			public:
				virtual PrimitiveTopology GetToplogy() = 0;
				virtual std::tuple<void*, int> GetVertices() = 0;
				virtual std::tuple<int*, int>GetIndicies() = 0;
				virtual int SizeOfVertices() = 0;
				virtual int SizeOfVertexDataStructure()=0;
				virtual int SizeOfIndices()=0;
				virtual std::vector<int> GetDataStructureSequenceSize() = 0;
			};

			template<typename T>
			concept MeshStructType = std::is_base_of_v<VertexBase, T>;

			template<MeshStructType T, PrimitiveTopology primitiveType,int... sizes>
			class IMesh :public IMeshAbstract
			{
			public:
				PrimitiveTopology topology;

				std::vector<int>variableSizeList;
				T* vertices;
				int verticesCount;

				int* indices;
				int indicesCount;

				IMesh(T* vertices, int count);
				IMesh(T* vertices, int vcount, int* indicies, int iCount);
				~IMesh();

				 PrimitiveTopology GetToplogy()override;
				 std::tuple<void*, int> GetVertices()override;
				 std::tuple<int*, int>GetIndicies() override;
				 std::vector<int> GetDataStructureSequenceSize()override;

				 int SizeOfVertices()override;
				 int SizeOfVertexDataStructure()override;
				 int SizeOfIndices() override;
				 

			};

			template<MeshStructType T, PrimitiveTopology primitiveType, int... sizes>
			PrimitiveTopology IMesh<T, primitiveType, sizes...>::GetToplogy() { return topology; }

			template<MeshStructType T, PrimitiveTopology primitiveType, int... sizes>
			std::tuple<void*, int> IMesh<T, primitiveType, sizes...>::GetVertices() { return std::make_tuple(vertices, verticesCount); }

			template<MeshStructType T, PrimitiveTopology primitiveType, int... sizes>
			std::tuple<int*, int> IMesh<T, primitiveType, sizes...>::GetIndicies() { return std::make_tuple(indices, indicesCount); }

			template<MeshStructType T, PrimitiveTopology primitiveType, int... sizes>
			std::vector<int> IMesh<T, primitiveType, sizes...>::GetDataStructureSequenceSize() { return variableSizeList; }


			template<MeshStructType T, PrimitiveTopology primitiveType,int... sizes>
			inline IMesh<T, primitiveType, sizes...>::IMesh(T* vertices, int count) 
				: vertices(vertices), verticesCount(count), indices(nullptr), indicesCount(0), variableSizeList{ sizes... }, topology(primitiveType)
			{
				  int totalSize = 0;
					for (int i = 0; i < variableSizeList.size(); i++)totalSize += variableSizeList[i];
					totalSize *= sizeof(float);
					
					if (totalSize != SizeOfVertexDataStructure())
					{
						Debugger::Debug::LogError(
							std::string(std::to_string(totalSize) +
								" size is not equal to SizeOfVertexDataStructure" +
								std::to_string(SizeOfVertexDataStructure())));
					}
					//assert(totalSize == SizeOfVertexDataStructure() && "total size equal to SizeOfVertexDataStructure");

			}

			template<MeshStructType T, PrimitiveTopology primitiveType,int... sizes>
			inline IMesh<T, primitiveType, sizes...>::IMesh(T* vertices, int vcount, int* indicies, int iCount)
				: vertices(vertices), verticesCount(vcount), indices(indicies), indicesCount(iCount), variableSizeList{ sizes... }, topology(primitiveType)
			{
			}

			template<MeshStructType T, PrimitiveTopology primitiveType, int...sizes>
			int IMesh<T, primitiveType, sizes...>::SizeOfVertices()
			{
				return sizeof(T) * this->verticesCount;
			}

			template<MeshStructType T, PrimitiveTopology primitiveType, int...sizes>
			int IMesh<T, primitiveType, sizes...>::SizeOfVertexDataStructure()
			{
				return sizeof(T);
			}

			template<MeshStructType T, PrimitiveTopology primitiveType, int...sizes>
			int IMesh<T, primitiveType, sizes...>::SizeOfIndices()
			{
				return sizeof(int) * this->indicesCount;
			}

			template<MeshStructType T, PrimitiveTopology primitiveType, int...sizes>
			IMesh<T, primitiveType, sizes...>::~IMesh()
			{
				delete vertices;
				delete indices;
			}
		}
	}
}