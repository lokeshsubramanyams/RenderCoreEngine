#include "MeshUtil.h"
#include "Debug.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::Debugger;
		namespace Graphics
		{
			Mesh *MeshUtil::ClipperTriangle()
			{
				Vector3 *vertices = new Vector3[3];
				vertices[0] = Vector3(-1.0, -1.0, 0.0);
				vertices[1] = Vector3(1.0, -1.0, 0.0);
				vertices[2] = Vector3(0.0, 1.0, 0.0);
				Mesh* mesh = new Mesh(vertices,3);

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
				Debug::LogError("Cube is not implemented:");
				return nullptr;
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

			
			
		}

	}
}