#pragma once 
#include "MathLib.h"
namespace RCEngine
{
	namespace RenderCore
	{
		namespace Graphics
		{

			using namespace RCEngine::MathLib;
			class Mesh
			{
			public:
				Vector3* vertices;
				int* indices;

				Mesh(Vector3 *verts, int *indices);
				Mesh(Vector3 *verts);
				~Mesh();

			};
		}
		
	}
}