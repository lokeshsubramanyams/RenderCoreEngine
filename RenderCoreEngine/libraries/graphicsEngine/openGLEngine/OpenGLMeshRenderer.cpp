#include "OpenGLMeshRenderer.h"
#include "RenderCore.h"
#include "Debug.h"
namespace RCEngine
{

	namespace RenderCore
	{
		using namespace Debugger;
		OpenGLMeshRenderer::OpenGLMeshRenderer(Mesh &_mesh, IShader &_shader):IMeshRenderer(_mesh,_shader)
		{
			mesh = &_mesh;
			shader = &_shader;
		}

		void OpenGLMeshRenderer::Load()
		{
			GLuint VBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, mesh->SizeOfVertices(), mesh->vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, mesh->SizeOfVertexDataStructure(), (void*)0);
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

			shader->UseProgram();

			shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX, glm::mat4(1.0f));

			glBindVertexArray(VAO);

			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);
		}
	}
}

