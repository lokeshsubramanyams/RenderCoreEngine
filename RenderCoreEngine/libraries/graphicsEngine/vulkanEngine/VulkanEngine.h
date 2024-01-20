#pragma once
#include "IGraphicsEngine.h"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class VulkanEngine : public IGraphicsEngine
		{
		public:
			void TestAPIs();
		};

	}
}