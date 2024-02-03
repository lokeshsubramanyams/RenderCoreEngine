#include "OpenGLMeshRenderer.h"
#include "RenderCore.h"
#include "Debug.h"
namespace RCEngine
{

	namespace RenderCore
	{
		using namespace Debugger;
		OpenGLMeshRenderer::OpenGLMeshRenderer(MeshFilter* filter, IMaterial* material):IMeshRenderer(filter,material)
		{
			
		}

		void OpenGLMeshRenderer::Load()
		{
			GLuint VBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, meshFilter->mesh->SizeOfVertices(), meshFilter->mesh->vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, meshFilter->mesh->SizeOfVertexDataStructure(), (void*)0);
			glEnableVertexAttribArray(0);
		}

		void OpenGLMeshRenderer::LoadInBatch()
		{

		}

		void OpenGLMeshRenderer::Render()
		{
			glBindVertexArray(0);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			glClear(GL_COLOR_BUFFER_BIT);
			
			material->shader->UseProgram();
			
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX, transform->GetMatrix());

			glBindVertexArray(VAO);

			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);
		}
	}
}

