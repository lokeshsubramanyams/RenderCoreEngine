#include "MeshUtil.h"
#include "MeshUtil.h"
#include "MeshUtil.h"
#include "MeshUtil.h"
#include "Debug.h"
#include <vector>
#include <cmath>

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
				float radius = 1.0f; // Sphere radius
				unsigned int sectors = 36; // Longitude lines
				unsigned int stacks = 18; // Latitude lines

				std::vector<Vertex> vertices;
				std::vector<int>indices;
				float const PI = acos(-1);
				float sectorStep = 2 * PI / sectors;
				float stackStep = PI / stacks;
				float sectorAngle, stackAngle;

				for (unsigned int i = 0; i <= stacks; ++i) {
					stackAngle = PI / 2 - i * stackStep; // starting from pi/2 to -pi/2
					float xy = radius * cosf(stackAngle); // r * cos(u)
					float z = radius * sinf(stackAngle); // r * sin(u)

					for (unsigned int j = 0; j <= sectors; ++j) {
						sectorAngle = j * sectorStep; // starting from 0 to 2pi

						// Vertex position (x, y, z)
						Vector3 position(xy * cosf(sectorAngle), xy * sinf(sectorAngle), z);

						// Normalized vertex normal (nx, ny, nz)
						Vector3 normal(position.x / radius, position.y / radius, position.z / radius);

						// Vertex tex coords (s, t) range between [0, 1]
						Vector2 texCoord((float)j / sectors, (float)i / stacks);

						vertices.push_back({ position, normal, texCoord });
					}
				}

				int k1, k2;
				for (int i = 0; i < stacks; ++i) {
					k1 = i * (sectors + 1);
					k2 = k1 + sectors + 1;

					for (int j = 0; j < sectors; ++j, ++k1, ++k2) {
						
						if (i != 0) {
							indices.push_back(k1);
							indices.push_back(k2);
							indices.push_back(k1 + 1);
						}

						// k1+1 => k2 => k2+1
						if (i != (stacks - 1)) {
							indices.push_back(k1 + 1);
							indices.push_back(k2);
							indices.push_back(k2 + 1);
						}
					}
				}
				Vertex* vertexArray = new Vertex[vertices.size()];
				std::copy(vertices.begin(), vertices.end(), vertexArray);
				int* indexArray = new int[indices.size()];
				std::copy(indices.begin(), indices.end(), indexArray);


				return new Mesh(vertexArray, vertices.size(), indexArray, indices.size());
			}

			Mesh* MeshUtil::GetCylinderMesh()
			{
				float height = 2.0f; float radius = 1.0f; int segments = 32;
				const float pi = 3.14159265358979323846;
				float segmentAngle = 2 * pi / segments;

				std::vector<Vertex> vertices;
				std::vector<int>indices;

				// Top and bottom center vertices
				vertices.push_back({ {0, height, 0}, {0, 1, 0}, {0.5f, 0.5f} }); // Top center
				vertices.push_back({ {0, 0, 0}, {0, -1, 0}, {0.5f, 0.5f} }); // Bottom center

				for (int i = 0; i < segments; ++i) {
					float angle = i * segmentAngle;
					float x = cos(angle) * radius;
					float z = sin(angle) * radius;

					// Top vertex
					vertices.push_back({ {x, height, z}, {cos(angle), 0, sin(angle)}, {static_cast<float>(i) / segments, 1} });
					// Bottom vertex
					vertices.push_back({ {x, 0, z}, {cos(angle), 0, sin(angle)}, {static_cast<float>(i) / segments, 0} });

					// Top circle indices
					if (i > 0) {
						indices.push_back(0); // Top center
						indices.push_back(2 + 2 * (i - 1)); // Current top
						indices.push_back(2 + 2 * i); // Next top
					}

					// Bottom circle indices
					if (i > 0) {
						indices.push_back(1); // Bottom center
						indices.push_back(3 + 2 * (i - 1)); // Current bottom
						indices.push_back(3 + 2 * i); // Next bottom
					}

					// Side indices
					if (i > 0) {
						indices.push_back(2 + 2 * (i - 1)); // Previous top
						indices.push_back(3 + 2 * (i - 1)); // Previous bottom
						indices.push_back(2 + 2 * i); // Current top

						indices.push_back(3 + 2 * (i - 1)); // Previous bottom
						indices.push_back(3 + 2 * i); // Current bottom
						indices.push_back(2 + 2 * i); // Current top
					}
				}
			
				Vertex* vertexArray = new Vertex[vertices.size()];
				std::copy(vertices.begin(), vertices.end(), vertexArray);
				int* indexArray = new int[indices.size()];
				std::copy(indices.begin(), indices.end(), indexArray);


				return new Mesh(vertexArray, vertices.size(), indexArray, indices.size());
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

			IMeshAbstract* MeshUtil::IGeometricalShapes(GeometryShapes shape)
      {
				switch (shape)
				{
				case RCEngine::Cube:
					return IGetCubeMesh();
				case RCEngine::Sphere:
					return IGetSphereMesh();
				case RCEngine::Cylinder:
					//return GetCylinderMesh();
				case RCEngine::Cone:
					//return GetMeshCone();
				case RCEngine::Torus:
					//return GetMeshTorus();
				default:
					Debug::LogError(std::string("Shape type is not implemented:" + std::to_string(shape)));
					break;
				}
				return nullptr;
      }

			IMeshAbstract* MeshUtil::IGetCubeMesh()
			{
				VertexNormalTexCoord* cubeVertices = new VertexNormalTexCoord[24]{
					// Front face
					{Vector3(- 1.0f, -1.0f,  1.0f), Vector3(0.0f,  0.0f,  1.0f), Vector2(0.0f, 0.0f)}, // Bottom-left
					{Vector3( 1.0f, -1.0f,  1.0f), Vector3(0.0f,  0.0f,  1.0f), Vector2(1.0f, 0.0f)}, // Bottom-right
					{Vector3( 1.0f,  1.0f,  1.0f), Vector3(0.0f,  0.0f,  1.0f), Vector2(1.0f, 1.0f)}, // Top-right
					{Vector3(-1.0f,  1.0f,  1.0f), Vector3(0.0f,  0.0f,  1.0f), Vector2(0.0f, 1.0f)}, // Top-left

					// Right face
					{ Vector3(1.0f, -1.0f,  1.0f),  Vector3(1.0f, 0.0f, 0.0f), Vector2( 0.0f, 0.0f )},
					{ Vector3(1.0f, -1.0f, -1.0f ), Vector3(1.0f, 0.0f, 0.0f), Vector2( 1.0f, 0.0f )},
					{ Vector3(1.0f,  1.0f, -1.0f ), Vector3(1.0f, 0.0f, 0.0f), Vector2( 1.0f, 1.0f )},
					{ Vector3(1.0f,  1.0f,  1.0f ), Vector3(1.0f,  0.0f,  0.0f), Vector2(0.0f, 1.0f)},

					// Back face
					{Vector3( 1.0f, -1.0f, -1.0f), Vector3(0.0f,  0.0f, -1.0f), Vector2(0.0f, 0.0f)},
					{Vector3(-1.0f, -1.0f, -1.0f), Vector3(0.0f,  0.0f, -1.0f), Vector2(1.0f, 0.0f)},
					{Vector3(-1.0f,  1.0f, -1.0f), Vector3(0.0f,  0.0f, -1.0f), Vector2(1.0f, 1.0f)},
					{Vector3( 1.0f,  1.0f, -1.0f), Vector3(0.0f,  0.0f, -1.0f), Vector2(0.0f, 1.0f)},

					// Left face
					{Vector3(-1.0f, -1.0f, -1.0f), Vector3(-1.0f,  0.0f,  0.0f), Vector2(0.0f, 0.0f)},
					{Vector3(-1.0f, -1.0f,  1.0f), Vector3(-1.0f,  0.0f,  0.0f), Vector2(1.0f, 0.0f)},
					{Vector3(-1.0f,  1.0f,  1.0f), Vector3(-1.0f,  0.0f,  0.0f), Vector2(1.0f, 1.0f)},
					{Vector3(-1.0f,  1.0f, -1.0f), Vector3(-1.0f,  0.0f,  0.0f), Vector2(0.0f, 1.0f)},

					// Top face
					{Vector3(-1.0f,  1.0f,  1.0f), Vector3(0.0f,  1.0f,  0.0f), Vector2(0.0f, 0.0f)},
					{Vector3( 1.0f,  1.0f,  1.0f), Vector3(0.0f,  1.0f,  0.0f), Vector2(1.0f, 0.0f)},
					{Vector3( 1.0f,  1.0f, -1.0f), Vector3(0.0f,  1.0f,  0.0f), Vector2(1.0f, 1.0f)},
					{Vector3(-1.0f,  1.0f, -1.0f), Vector3(0.0f,  1.0f,  0.0f), Vector2(0.0f, 1.0f)},

					// Bottom face
					{Vector3(-1.0f, -1.0f, -1.0f), Vector3(0.0f, -1.0f,  0.0f), Vector2(0.0f, 0.0f)},
					{Vector3( 1.0f, -1.0f, -1.0f), Vector3(0.0f, -1.0f,  0.0f), Vector2(1.0f, 0.0f)},
					{Vector3( 1.0f, -1.0f,  1.0f), Vector3(0.0f, -1.0f,  0.0f), Vector2(1.0f, 1.0f)},
					{Vector3(-1.0f, -1.0f,  1.0f), Vector3(0.0f, -1.0f,  0.0f), Vector2(0.0f, 1.0f)},
				};


				int* cubeIndices = new int[36] {
					// Front face
					0, 1, 2, 2, 3, 0,
						// Right face
						4, 5, 6, 6, 7, 4,
						// Back face
						8, 9, 10, 10, 11, 8,
						// Left face
						12, 13, 14, 14, 15, 12,
						// Top face
						16, 17, 18, 18, 19, 16,
						// Bottom face
						20, 21, 22, 22, 23, 20
					};
				
				IMeshAbstract* cubeIMesh = new IMesh< VertexNormalTexCoord, PrimitiveTopology::TRIANGLES, 3, 3, 2>(cubeVertices, 24, cubeIndices, 36);
				return cubeIMesh;
			}

			IMeshAbstract* MeshUtil::IGetSphereMesh()
			{
				float radius = 1.0f; // Sphere radius
				unsigned int sectors = 36; // Longitude lines
				unsigned int stacks = 18; // Latitude lines

				std::vector<VertexNormalTexCoord> vertices;
				std::vector<int>indices;
				float const PI = acos(-1);
				float sectorStep = 2 * PI / sectors;
				float stackStep = PI / stacks;
				float sectorAngle, stackAngle;

				for (unsigned int i = 0; i <= stacks; ++i) {
					stackAngle = PI / 2 - i * stackStep; // starting from pi/2 to -pi/2
					float xy = radius * cosf(stackAngle); // r * cos(u)
					float z = radius * sinf(stackAngle); // r * sin(u)

					for (unsigned int j = 0; j <= sectors; ++j) {
						sectorAngle = j * sectorStep; // starting from 0 to 2pi

						// Vertex position (x, y, z)
						Vector3 position(xy * cosf(sectorAngle), xy * sinf(sectorAngle), z);

						// Normalized vertex normal (nx, ny, nz)
						Vector3 normal(position.x / radius, position.y / radius, position.z / radius);

						// Vertex tex coords (s, t) range between [0, 1]
						Vector2 texCoord((float)j / sectors, (float)i / stacks);

						vertices.push_back({ position, normal, texCoord });
					}
				}

				int k1, k2;
				for (int i = 0; i < stacks; ++i) {
					k1 = i * (sectors + 1);
					k2 = k1 + sectors + 1;

					for (int j = 0; j < sectors; ++j, ++k1, ++k2) {

						if (i != 0) {
							indices.push_back(k1);
							indices.push_back(k2);
							indices.push_back(k1 + 1);
						}

						// k1+1 => k2 => k2+1
						if (i != (stacks - 1)) {
							indices.push_back(k1 + 1);
							indices.push_back(k2);
							indices.push_back(k2 + 1);
						}
					}
				}
				VertexNormalTexCoord* vertexArray = new VertexNormalTexCoord[vertices.size()];
				std::copy(vertices.begin(), vertices.end(), vertexArray);
				int* indexArray = new int[indices.size()];
				std::copy(indices.begin(), indices.end(), indexArray);

				IMeshAbstract* sphereIMesh = 
					new IMesh<VertexNormalTexCoord, PrimitiveTopology::TRIANGLES, 3, 3, 2>(vertexArray, vertices.size(), indexArray, indices.size());
				return sphereIMesh;
			}

			
			
		}

	}
}