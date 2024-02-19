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
				Vertex *cubeVertices = new Vertex[24]{
					// Front face
					{{-1.0f, -1.0f,  1.0f}, {0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}}, // Bottom-left
					{{ 1.0f, -1.0f,  1.0f}, {0.0f,  0.0f,  1.0f}, {1.0f, 0.0f}}, // Bottom-right
					{{ 1.0f,  1.0f,  1.0f}, {0.0f,  0.0f,  1.0f}, {1.0f, 1.0f}}, // Top-right
					{{-1.0f,  1.0f,  1.0f}, {0.0f,  0.0f,  1.0f}, {0.0f, 1.0f}}, // Top-left

					// Right face
					{{1.0f, -1.0f,  1.0f}, {1.0f,  0.0f,  0.0f}, {0.0f, 0.0f}},
					{{1.0f, -1.0f, -1.0f}, {1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}},
					{{1.0f,  1.0f, -1.0f}, {1.0f,  0.0f,  0.0f}, {1.0f, 1.0f}},
					{{1.0f,  1.0f,  1.0f}, {1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}},

					// Back face
					{{ 1.0f, -1.0f, -1.0f}, {0.0f,  0.0f, -1.0f}, {0.0f, 0.0f}},
					{{-1.0f, -1.0f, -1.0f}, {0.0f,  0.0f, -1.0f}, {1.0f, 0.0f}},
					{{-1.0f,  1.0f, -1.0f}, {0.0f,  0.0f, -1.0f}, {1.0f, 1.0f}},
					{{ 1.0f,  1.0f, -1.0f}, {0.0f,  0.0f, -1.0f}, {0.0f, 1.0f}},

					// Left face
					{{-1.0f, -1.0f, -1.0f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 0.0f}},
					{{-1.0f, -1.0f,  1.0f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}},
					{{-1.0f,  1.0f,  1.0f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 1.0f}},
					{{-1.0f,  1.0f, -1.0f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}},

					// Top face
					{{-1.0f,  1.0f,  1.0f}, {0.0f,  1.0f,  0.0f}, {0.0f, 0.0f}},
					{{ 1.0f,  1.0f,  1.0f}, {0.0f,  1.0f,  0.0f}, {1.0f, 0.0f}},
					{{ 1.0f,  1.0f, -1.0f}, {0.0f,  1.0f,  0.0f}, {1.0f, 1.0f}},
					{{-1.0f,  1.0f, -1.0f}, {0.0f,  1.0f,  0.0f}, {0.0f, 1.0f}},

					// Bottom face
					{{-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f,  0.0f}, {0.0f, 0.0f}},
					{{ 1.0f, -1.0f, -1.0f}, {0.0f, -1.0f,  0.0f}, {1.0f, 0.0f}},
					{{ 1.0f, -1.0f,  1.0f}, {0.0f, -1.0f,  0.0f}, {1.0f, 1.0f}},
					{{-1.0f, -1.0f,  1.0f}, {0.0f, -1.0f,  0.0f}, {0.0f, 1.0f}},
				};
				

				int *cubeIndices = new int[36]{
					// Front face
					0, 1, 2,    2, 3, 0,
					// Right face
					4, 5, 6,    6, 7, 4,
					// Back face
					8, 9, 10,   10, 11, 8,
					// Left face
					12, 13, 14, 14, 15, 12,
					// Top face
					16, 17, 18, 18, 19, 16,
					// Bottom face
					20, 21, 22, 22, 23, 20
				};
				
				Mesh* mesh = new Mesh(cubeVertices, 24, cubeIndices, 36);
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
					
				for (int i = 0; i < count; i+=8)
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