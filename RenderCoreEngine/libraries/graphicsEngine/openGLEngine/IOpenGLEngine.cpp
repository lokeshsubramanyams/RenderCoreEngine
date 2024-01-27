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
			glUseProgram(program.shaderProgram);
			this->Renderable(mesh);
		}

    void IOpenGLEngine::Renderable(Mesh* mesh)
    {
			glGenBuffers(1, &vb[0]);
			glBindBuffer(GL_ARRAY_BUFFER, vb[0]);

			Vector3 vertices[3];
			vertices[0] = Vector3(-1.0, -1.0, 0.0);
			vertices[1] = Vector3(1.0, -1.0, 0.0);
			vertices[2] = Vector3(0.0, 1.0, 0.0);

			Debug::Log("size of mesh vertices:", std::to_string(sizeof(vertices)));

			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
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

