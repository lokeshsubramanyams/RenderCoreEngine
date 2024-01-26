#pragma once 
#include "Mesh.h"


namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RenderCore::Graphics;
		class IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine() const = 0;
			virtual void  Render() = 0;
			virtual void Update(double delta) = 0;
			virtual void Renderable(Mesh* mesh)=0;
		};

	}
}