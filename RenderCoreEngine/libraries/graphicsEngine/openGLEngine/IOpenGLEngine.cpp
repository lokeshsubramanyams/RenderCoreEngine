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
			 
			GLuint uniformKey = glGetUniformLocation(shaderProgram, vertex.unifromKey);
			Debug::Log("uniformKey:",std::to_string(uniformKey));
			return { vertex.shaderKey,fragment.shaderKey,shaderProgram,uniformKey };
		}

		void IOpenGLEngine::Renderable(Mesh* mesh, ShaderProgram program)
		{
			shaderProgram = program;
			this->Renderable(mesh);
		}

    void IOpenGLEngine::Renderable(Mesh* mesh)
    {
			GLuint VBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, mesh->SizeOfVertices(), mesh->vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE, mesh->SizeOfVertexDataStructure(), (void*)0);
			glEnableVertexAttribArray(0);
		
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
			testVariable += delta * direction*0.1;
			if (testVariable > 1.0 || testVariable < -1.0)direction *= -1.0;

			transformation = glm::scale(glm::mat4(1.0f), glm::vec3(testVariable, testVariable, testVariable));
		
		}
	
		void IOpenGLEngine::RegisterCustomShader(ShaderMetaData customShader) const
		{

		}
	}
}

