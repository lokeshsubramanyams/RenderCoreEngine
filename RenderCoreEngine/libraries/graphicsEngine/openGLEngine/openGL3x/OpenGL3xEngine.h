#pragma once
#include "IGraphicsEngine.h"
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