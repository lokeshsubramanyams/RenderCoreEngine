#pragma once 
#include "IGraphicsEngine.h"
#include <GL/glew.h>//this is there in vcpkg and emsdk

namespace  RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class IOpenGLEngine : public IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine() const;
			virtual void  Render() = 0;
			void Update(double delta) override;
			void Renderable(Mesh* mesh)override;
		protected:
			float testVariable = 0.001f;
			float testVariable1 = 1.0f;
			int vBufferCount = 1;
			GLuint vb[1] = { 0 };
			
		
		};


	}
}
