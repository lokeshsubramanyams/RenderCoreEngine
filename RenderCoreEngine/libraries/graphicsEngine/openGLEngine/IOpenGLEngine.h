#pragma once 
#include "IGraphicsEngine.h"
#include <vector>
#include <GL/glew.h>//this is there in vcpkg and emsdk

namespace  RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class IOpenGLEngine : public IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine(Rect viewport) const;
			virtual void  RenderLoop() = 0;

			ShaderProgram CompileShader(ShaderMetaData vertex, ShaderMetaData fragment)const override;
			
			void RegisterCustomShader(ShaderMetaData customShader)const override;
						

			void UpdateLoop(double delta) override;
			void Renderable(Mesh* mesh)override;
			void Renderable(Mesh* mesh, ShaderProgram program)override;
		

		protected:
			int vBufferCount = 1;
			GLuint vb[1] = { 0 };
		private:
			GLuint CompileToShaderProgram(ShaderMetaData mData)const;

		
		};


	}
}
