#pragma once 
#include "IGraphicsEngine.h"
#include <vector>
#include <memory>
#include <GL/glew.h>//this is there in vcpkg and emsdk

#include "OpenGLShaderBuilder.h"
#include "OpenGLComponentFactory.h"
#include "IRenderer.h"

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
			IShader* GetLoadedShader(std::string shader)override;
			IComponentFactory* GetFactory()override;
			void Render(RCEngine::RenderCore::IRenderer* renderer)override;
			
			void UpdateLoop(double delta) override;
			void RegisterCustomShader(ShaderMetaData customShader)const override;
		

		protected:
		
			std::unique_ptr<IShaderBuilder> shaderBuilder;
			std::unique_ptr<IComponentFactory>componentFactory;

			std::vector<IRenderer*> renderers;

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
