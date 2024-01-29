#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void IOpenGLEngine::InitilizeEngine(Rect viewport) const
		{
			if (glewInit() != GLEW_OK)
			{
				Debug::Log("Glew not initilized-some error!");
			}

			glViewport(viewport.x, viewport.y, viewport.width, viewport.height);
			
   	}
		
		ShaderProgram IOpenGLEngine::CompileShader(ShaderMetaData vertex, ShaderMetaData fragment) const
		{
			

			GLuint vertexShader =  this->CompileToShaderProgram(vertex);
			GLuint fragmentShader = this->CompileToShaderProgram(fragment);

			GLuint shaderProgram = glCreateProgram();

			if (shaderProgram == 0)
			{
				Debug::LogError("Error on creating shader program\n");
				return ShaderProgram();
			}

			glAttachShader(shaderProgram, vertexShader);
			glAttachShader(shaderProgram, fragmentShader);
			glLinkProgram(shaderProgram);


			GLint status = 0;
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
			if (status == 0)
			{
				GLchar ErrorLog[512] = { 0 };
				glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
				Debug::LogError(ErrorLog);
				return ShaderProgram();
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			return { vertex.shaderKey,fragment.shaderKey,shaderProgram };
		}

		void IOpenGLEngine::Renderable(Mesh* mesh, ShaderProgram program)
		{
			shaderProgram = program.shaderProgram;
			this->Renderable(mesh);
		}

    void IOpenGLEngine::Renderable(Mesh* mesh)
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

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);

    }

		GLuint IOpenGLEngine::CompileToShaderProgram(ShaderMetaData mData)const
		{
			Debug::Log("Compiling Shader:", mData.shaderKey);
			GLenum shaderType{};
			switch (mData.shaderType)
			{
			case ShaderType::VERTEX:shaderType = GL_VERTEX_SHADER; break;
			case ShaderType::FRAGMENT:shaderType = GL_FRAGMENT_SHADER; break;
			}

			GLuint shaderObj = glCreateShader(shaderType);
			if (shaderObj == 0)
			{
				Debug::LogError("Error on creating shader type\n" + std::to_string(shaderType));
			}
			glShaderSource(shaderObj, 1, &mData.source, NULL);
			glCompileShader(shaderObj);
			GLint status;
			glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &status);
			if (!status)
			{
				GLchar logError[512];
				glGetShaderInfoLog(shaderObj, 512, NULL, logError);
				Debug::LogError(logError);

			}
			else
				Debug::Log("success on compile:", mData.shaderKey);

			return shaderObj;

		}

		void IOpenGLEngine::UpdateLoop(double delta)
		{

		}
	
		void IOpenGLEngine::RegisterCustomShader(ShaderMetaData customShader) const
		{

		}
	}
}

