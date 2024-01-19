#pragma once
#include "GraphicsEngine.hpp"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class WebGpuEngine : public IGraphicsEngine
		{
		public:
			void TestAPIs();
		};

	}
}