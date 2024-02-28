#pragma once

#include "MathLib.h"
#include "Mesh.h"
#include "Line.h"
#include "RenderCore.h"
#include "IMesh.h"

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
				static Mesh *Triangle();
				static Mesh* Quad();

				static Mesh* GeometricalShapes(GeometryShapes shape);

				static Mesh* GetCubeMesh();
				static Mesh* GetSphereMesh();
				static Mesh* GetCylinderMesh();
				static Mesh* GetMeshCone();
				static Mesh* GetMeshTorus();

				static Line* GetGridLines();


			};
		}

	}
}