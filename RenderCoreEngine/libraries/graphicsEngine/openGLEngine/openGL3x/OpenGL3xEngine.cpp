#include "OpenGL3xEngine.h"
#include "OpenGL3xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL3xEngine::InitilizeEngine(Rect viewport)
		{
			Debug::Log(viewport);
			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
			
			shaderBuilder = std::make_unique<OpenGLShaderBuilder>();
			componentFactory = std::make_unique<OpenGLComponentFactory>();
		}

		void OpenGL3xEngine::RenderLoop()
		{
		/*	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram.shaderProgram);

			glUniformMatrix4fv(shaderProgram.uniformTransformationMatrix, 1, GL_FALSE, glm::value_ptr(transformation));

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);
			*/
			for (int i = 0; i < renderers.size(); i++)
			{
				renderers[i]->Render();
			}

		}
		std::unordered_map<std::string, ShaderMetaData> OpenGL3xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}

	}
}
