#pragma once
#include "GraphicsEngine.hpp"
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