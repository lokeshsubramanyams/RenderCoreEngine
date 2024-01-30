#pragma once

#include "MathLib.h"
#include "Mesh.h"
#include "RenderCore.h"
namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{

			using namespace RCEngine::MathLib;
			class MeshUtil
			{
			public:
				static Mesh *ClipperTriangle();
				static Mesh* GeometricalShapes(GeometryShapes shape);

				static Mesh* GetCubeMesh();
				static Mesh* GetSphereMesh();
				static Mesh* GetCylinderMesh();
				static Mesh* GetMeshCone();
				static Mesh* GetMeshTorus();

			};
		}

	}
}