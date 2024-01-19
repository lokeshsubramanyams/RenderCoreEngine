#pragma once
#include "IGraphicsEngine.hpp"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL3xEngine : public IGraphicsEngine
		{
		public:
			void TestAPIs();
		};

	}
}