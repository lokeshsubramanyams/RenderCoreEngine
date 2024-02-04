#pragma once 
#include "IMeshRenderer.h"
#include "MeshFilter.h"
#include "OpenGLMaterial.h"
#include <GL/glew.h>
namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
	
		class OpenGLMeshRenderer : public IMeshRenderer
		{
		private:
			GLuint VAO,VBO,EBO;
		public:
			OpenGLMeshRenderer(MeshFilter *filter,IMaterial *material);

			void Load()override;
			void LoadInBatch()override;
			void Render()override;
			void UnLoad()override;

		};
	}
}