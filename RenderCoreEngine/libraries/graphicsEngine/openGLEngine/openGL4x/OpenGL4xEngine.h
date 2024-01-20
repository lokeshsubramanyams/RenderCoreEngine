#pragma once
#include "IGraphicsEngine.h"


namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class OpenGL4xEngine : public IGraphicsEngine
		{
		public:
			void  InitilizeEngine()const override;
		
		};

	}
}