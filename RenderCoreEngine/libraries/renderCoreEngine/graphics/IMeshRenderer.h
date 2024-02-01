#pragma once
#include "IRenderer.h"
#include "Mesh.h"
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore::Graphics;
		class IMeshRenderer : public IRenderer
		{
		protected:
			Mesh mesh;
		};
	}
}