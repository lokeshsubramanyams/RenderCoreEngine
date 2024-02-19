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
			glEnable(GL_CULL_FACE);
			glFrontFace(GL_CCW);
			glCullFace(GL_BACK);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, meshFilter->mesh->SizeOfVertNormalTex(), meshFilter->mesh->vertNormalTex, GL_STATIC_DRAW);

			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshFilter->mesh->SizeOfIndices(), meshFilter->mesh->indices, GL_STATIC_DRAW);

			//position
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, meshFilter->mesh->SizeOfVertNormalTexDataStructure(), (void*)0);
			
			// Normals
			glEnableVertexAttribArray(1); 
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, meshFilter->mesh->SizeOfVertNormalTexDataStructure(), (void*)offsetof(Vertex, normal));

			// Normals
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, meshFilter->mesh->SizeOfVertNormalTexDataStructure(), (void*)offsetof(Vertex, texCoord));

		}

		void OpenGLMeshRenderer::LoadInBatch()
		{

		}

		void OpenGLMeshRenderer::Render()
		{
			glBindVertexArray(0);

			material->shader->UseProgram();
			
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX, transform->GetMatrix());
			material->ApplyDefaultColor();

			glBindVertexArray(VAO);

			glDrawElements(GL_TRIANGLES, meshFilter->mesh->indicesCount, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);

		
		}
		void OpenGLMeshRenderer::Render(Matrix44 projectView)
		{
			glBindVertexArray(0);

			material->shader->UseProgram();

			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX, projectView * transform->GetMatrix());

			material->ApplyDefaultColor();

			glBindVertexArray(VAO);

			glDrawElements(GL_TRIANGLES, meshFilter->mesh->indicesCount, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);

		}
		void OpenGLMeshRenderer::Render(ICamera* camera, ILight* light)
		{
			glBindVertexArray(0);

			material->shader->UseProgram();

			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_MODEL_MATRIX, transform->GetMatrix());
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_VIEW_MATRIX, camera->GetViewMatrix());
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_PROJECTION_MATRIX, camera->GetProjectionMatrix());

			
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_LIGHTDIR, light->GetLightDirection());
			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_LIGHTCOLOR, light->lightColor);

			material->shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_FRAGMENT_UNIFORM_OBJECTCOLOR, Vector3(1.0f,1.0f,1.0f));

			glBindVertexArray(VAO);

			glDrawElements(GL_TRIANGLES, meshFilter->mesh->indicesCount, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);
		}
		void OpenGLMeshRenderer::UnLoad()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
		}
	}
}

