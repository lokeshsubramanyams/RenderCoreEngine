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
			virtual void InitilizeEngine() const;
			virtual void  RenderLoop() = 0;

			std::vector<Shader> CompileShaders(std::vector<ShaderMetaData> shadersMeta)const override;
			void RegisterCustomShader(ShaderMetaData customShader)const override;
						

			void UpdateLoop(double delta) override;
			void Renderable(Mesh* mesh)override;
			void Renderable(Mesh* mesh, Shader vertex, Shader fragment)override;
		

		protected:
			int vBufferCount = 1;
			GLuint vb[1] = { 0 };
			
		
		};


	}
}
