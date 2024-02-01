#pragma once 
#include "IMeshRenderer.h"
#include <GL/glew.h>
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::RenderCore::Graphics;

		class OpenGLMeshRenderer : public IMeshRenderer
		{
		private:
			GLuint VAO;
		public:
			OpenGLMeshRenderer(Mesh &mesh, IShader& shader);

			void Load()override;
			void LoadInBatch()override;
			void Render()override;

		};
	}
}