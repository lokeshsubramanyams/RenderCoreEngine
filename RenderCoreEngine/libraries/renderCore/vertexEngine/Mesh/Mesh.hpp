#include "MathLib.hpp"
namespace RCEngine
{
	namespace RenderCore
	{
		namespace VertexEngine
		{
			using namespace RCEngine::MathLib;
			class Mesh
			{
			public:
				Vector3* vertices;
				int* indices;

				Mesh(Vector3 verts[], int indices[]);
				~Mesh();

			};
		}
	}
}