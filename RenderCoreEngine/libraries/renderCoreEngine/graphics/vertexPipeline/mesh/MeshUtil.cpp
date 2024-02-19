#include "MeshUtil.h"
#include "MeshUtil.h"
#include "Debug.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Debugger;
		namespace Graphics
		{
			Mesh *MeshUtil::Triangle()
			{
				Vector3 *vertices = new Vector3[3];
				vertices[0] = Vector3(-1.0, -1.0, 0.0);
				vertices[1] = Vector3(1.0, -1.0, 0.0);
				vertices[2] = Vector3(0.0, 1.0, 0.0);

				int* indices = new int[3] {0, 1, 2};

				Mesh* mesh = new Mesh(vertices,3, indices,3);

				return mesh;
			}

			Mesh* MeshUtil::Quad()
			{
				Vector3* vertices = new Vector3[4];
				vertices[0] = Vector3(-1.0, -1.0, 0.0);//bottom left
				vertices[1] = Vector3(1.0, -1.0, 0.0);//bottom right
				vertices[2] = Vector3(1.0, 1.0, 0.0);//top right
				vertices[3] = Vector3(-1.0, 1.0, 0.0);//top left

				int* indices = new int[6] {0, 1, 2, 0, 2, 3};

				Mesh* mesh = new Mesh(vertices, 4, indices, 6);

				return mesh;
			}

			Mesh* MeshUtil::GeometricalShapes(GeometryShapes shape)
			{
				switch (shape)
				{
					case RCEngine::Cube:
						return GetCubeMesh();
					case RCEngine::Sphere:
						return GetSphereMesh();
					case RCEngine::Cylinder:
						return GetCylinderMesh();
					case RCEngine::Cone:
						return GetMeshCone();
					case RCEngine::Torus:
						return GetMeshTorus();
					default:
						Debug::LogError(std::string("Shape type is not implemented:"+std::to_string(shape)));
						break;
				}
				return nullptr;
			}

			Mesh* MeshUtil::GetCubeMesh()
			{
				Vector3* vertices = new Vector3[8];

				vertices[0] = Vector3(0.5f, 0.5f, 0.5f);
				vertices[1] = Vector3(-0.5f, 0.5f, -0.5f);
				vertices[2] = Vector3(-0.5f, 0.5f, 0.5f);
				vertices[3] = Vector3(0.5f, -0.5f, -0.5f);
				vertices[4] = Vector3(-0.5f, -0.5f, -0.5f);
				vertices[5] = Vector3(0.5f, 0.5f, -0.5f);
				vertices[6] = Vector3(0.5f, -0.5f, 0.5f);
				vertices[7] = Vector3(-0.5f, -0.5f, 0.5f);

				//12*3 = 36
				int *indices = new int[36] {
					
					0, 1, 2,
					1, 3, 4,
					
					5, 6, 3,
					7, 3, 6,
					
					2, 4, 7,
					0, 7, 6,
					
					0, 5, 1,
					1, 5, 3,
					
					5, 0, 6,
					7, 4, 3,
					
					2, 1, 4,
					0, 2, 7
				};
				
				Mesh* mesh = new Mesh(vertices, 8, indices, 36);

				return mesh;
			}

			Mesh* MeshUtil::GetSphereMesh()
			{
				Debug::LogError("Sphere is not implemented:");
				return nullptr;
			}

			Mesh* MeshUtil::GetCylinderMesh()
			{
				Debug::LogError("Cylinder is not implemented:");
				return nullptr;
			}

			Mesh* MeshUtil::GetMeshCone()
			{
				Debug::LogError("Cone is not implemented:");
				return nullptr;
			}

			Mesh* MeshUtil::GetMeshTorus()
			{
				Debug::LogError("Torus is not implemented:");
				return nullptr;
			}

			Line* MeshUtil::GetGridLines()
			{
				
				int rows = 10 * 4;
				int columns = 10 * 4;
				int count = rows * columns;
				Vector3* vertices = new Vector3[count];

				float length = count;
					
				for (int i = 0; i < count-8; i+=8)
				{
					vertices[i] = Vector3(i, 0.0f, -length);
					vertices[i+1] = Vector3(i, 0.0f, length);

					vertices[i+2] = Vector3(-i, 0.0f, -length);
					vertices[i +3] = Vector3(-i, 0.0f, length);
					
					vertices[i+4] = Vector3(-length, 0.0f, i);
					vertices[i + 5] = Vector3(length, 0.0f, i);

					vertices[i + 6] = Vector3(-length, 0.0f, -i);
					vertices[i + 7] = Vector3(length, 0.0f, -i);
				}

			
				Line* lines = new Line(vertices, count);

				return lines;
			}

			
			
		}

	}
}