#include "OpenGL3xEngine.h"
#include "OpenGL3xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL3xEngine::InitilizeEngine(Rect viewport) const
		{
			Debug::Log(viewport);
			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		}

		void OpenGL3xEngine::RenderLoop()
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);
		}
		std::unordered_map<std::string, ShaderMetaData> OpenGL3xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}

		void OpenGL3xEngine::Renderable(Mesh* mesh, ShaderProgram program)
		{
			shaderProgram = program.shaderProgram;
			this->Renderable(mesh);
		}

		void OpenGL3xEngine::Renderable(Mesh* mesh)
		{
			Vector3f vertices[3];
			vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
			vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
			vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

			float floatVertex[] = { -1.0f, -1.0f, 0.0f ,
			1.0f, -1.0f, 0.0f ,
				0.0f, 1.0f, 0.0f
			};

			GLuint VBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(floatVertex), floatVertex, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);


			//glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);



		}
	}
}
