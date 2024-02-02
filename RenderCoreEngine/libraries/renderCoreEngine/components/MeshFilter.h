#pragma once
#include "Mesh.h"
#include "IComponent.h"

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
			MeshFilter(Mesh *mesh);

		};
	}
}