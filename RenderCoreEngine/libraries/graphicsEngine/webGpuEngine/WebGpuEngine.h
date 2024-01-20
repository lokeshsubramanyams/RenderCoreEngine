#pragma once
#include "IGraphicsEngine.h"
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