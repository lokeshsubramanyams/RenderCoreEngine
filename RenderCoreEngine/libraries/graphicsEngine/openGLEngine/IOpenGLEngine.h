#pragma once 
#include "IGraphicsEngine.h"
namespace  RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class IOpenGLEngine : public IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine() const = 0;
			virtual void  Render() = 0;
			void Update(double delta) override;
			float testVariable = 0.001f;
			float testVariable1 = 1.0f;
			
		
		};


	}
}
