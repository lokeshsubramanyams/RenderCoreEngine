#include "OpenGLLineRenderer.h"
#include "RenderCore.h"
#include "Debug.h"
namespace RCEngine
{

	namespace RenderCore
	{
		using namespace Debugger;
		OpenGLLineRenderer::OpenGLLineRenderer(Line* line, IMaterial* material) :ILineRenderer(line, material)
		{

		}

		void OpenGLLineRenderer::Load()
		{
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, line->SizeOfVertices(), line->vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, line->SizeOfVertexDataStructure(), (void*)0);
			glEnableVertexAttribArray(0);

		}

		void OpenGLLineRenderer::LoadInBatch()
		{

		}

		void OpenGLLineRenderer::Render()
		{

		}
		void OpenGLLineRenderer::Render(Matrix44 projectView)
		{
			glBindVertexArray(0);

			material->UseProgram();

			material->SetTransformationMatrix(projectView * transform->GetMatrix());

			material->ApplyColor(color);

			glBindVertexArray(VAO);

			glDrawArrays(GL_LINES, 0, line->verticesCount);

			glBindVertexArray(0);

		}
		void OpenGLLineRenderer::Render(ICamera* camera,ILight* light)
		{
			glBindVertexArray(0);

			material->UseProgram();

			material->SetTransformationMatrix(camera->GetViewProjectionMatrix() * transform->GetMatrix());

			material->ApplyColor(color);

			glBindVertexArray(VAO);

			glDrawArrays(GL_LINES, 0, line->verticesCount);

			glBindVertexArray(0);
		}
		void OpenGLLineRenderer::UnLoad()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
		}
	}
}

