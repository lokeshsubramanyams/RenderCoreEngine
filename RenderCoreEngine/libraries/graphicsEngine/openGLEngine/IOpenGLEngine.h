#pragma once 
#include "IGraphicsEngine.h"
#include <vector>
#include <memory>
#include <GL/glew.h>//this is there in vcpkg and emsdk

#include "OpenGLShaderBuilder.h"

namespace  RCEngine
{
	namespace OpenGLEngine
	{
		using namespace GraphicsEngine;
		class IOpenGLEngine : public IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine(Rect viewport);
			virtual void  RenderLoop() = 0;


			void LoadShaderBatch(std::vector<ShaderProgram> programs)override;


			
			void RegisterCustomShader(ShaderMetaData customShader)const override;
						
			void UpdateLoop(double delta) override;

		

		protected:
		
			std::unique_ptr<IShaderBuilder> shaderBuilder;

			int vBufferCount = 1;
			GLuint vb[1] = { 0 };
			GLuint VAO;
			ShaderProgram shaderProgram;

			double testVariable = 1.0;
			double direction = 1.0;
			Matrix44 transformation;

		
		};


	}
}
