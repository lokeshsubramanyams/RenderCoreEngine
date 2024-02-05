#pragma once 

#include <vector>
#include <memory>
#include <GL/glew.h>//this is there in vcpkg and emsdk

#include "IGraphicsEngine.h"
#include "Source/OpenGLShaderBuilder.h"
#include "Source/OpenGLComponentFactory.h"
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

			void SetCamera(ICamera *camera)override;

			void LoadShaderBatch(std::vector<ShaderProgram> programs)override;
			IShader* GetLoadedShader(std::string shader)override;
			IComponentFactory* GetFactory()override;
			void Render(RCEngine::RenderCore::IRenderer* renderer)override;
			void RegisterCustomShader(ShaderMetaData customShader)const override;
		

		protected:
		
			std::unique_ptr<IShaderBuilder> shaderBuilder;
			std::unique_ptr<IComponentFactory>componentFactory;
			std::vector<IRenderer*> renderers;
			ICamera* camera;

			Matrix44 GetProjectionViewMatrix() override;

			
		
		};


	}
}
