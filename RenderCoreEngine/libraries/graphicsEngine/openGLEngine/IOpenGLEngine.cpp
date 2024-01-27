#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void IOpenGLEngine::InitilizeEngine() const
		{
			if (glewInit() != GLEW_OK)
			{
				Debug::Log("Glew not initilized-some error!");
			}

			glViewport(0, 0, 640, 480);
			
   	}
		std::vector<Shader> IOpenGLEngine::CompileShaders(std::vector<ShaderMetaData> shadersMeta) const
		{
			std::vector<Shader>shaders;
			
			for (int i = 0; i < shadersMeta.size(); i++)
			{
				Debug::Log("Compiling Shader:", shadersMeta[i].shaderKey);
				GLenum shaderType{};
				switch(shadersMeta[i].shaderType)
				{
					case ShaderType::VERTEX:shaderType = GL_VERTEX_SHADER; break;
					case ShaderType::FRAGMENT:shaderType = GL_FRAGMENT_SHADER; break;
				}
				 
				GLuint shaderObj = glCreateShader(shaderType);
				if (shaderObj == 0)
				{
					Debug::LogError("Error on creating shader type\n" + std::to_string(shaderType));
					continue;
				}
				glShaderSource(shaderObj, 1, &shadersMeta[i].source, NULL);
				glCompileShader(shaderObj);
				GLint status;
				glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &status);
				if (!status)
				{
					GLchar logError[1024];
					glGetShaderInfoLog(shaderObj, 1024, NULL, logError);
					Debug::LogError(logError);
					continue;
				}
				else
					Debug::Log("success on compile:", shadersMeta[i].shaderKey);
				
				
				shaders.push_back({ shadersMeta[i].shaderKey ,shaderObj});
			}
			return shaders;
		}

		void IOpenGLEngine::Renderable(Mesh* mesh, Shader vertex, Shader fragment)
		{
			GLuint shaderProgram = glCreateProgram();
			if (shaderProgram == 0)
			{
				Debug::LogError("Error on creating shader program\n");
				return;
			}
			
			glAttachShader(shaderProgram, vertex.shaderObject);
			glAttachShader(shaderProgram, fragment.shaderObject);
			glLinkProgram(shaderProgram);
			
			
			GLint status = 0;
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
			if (status == 0)
			{
				GLchar ErrorLog[1024] = { 0 };
				glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
				Debug::LogError(ErrorLog);
				return;
			}
			
			glUseProgram(shaderProgram);
			this->Renderable(mesh);
		}



    void IOpenGLEngine::Renderable(Mesh* mesh)
    {
			//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			
			Vector3 vertices[3];
			vertices[0] = Vector3(-1.0, -1.0, 0.0);
			vertices[1] = Vector3(1.0, -1.0, 0.0);
			vertices[2] = Vector3(0.0, 1.0, 0.0);

			Debug::Log("size of mesh vertices:", std::to_string(sizeof(vertices)));

			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }

	

		void IOpenGLEngine::UpdateLoop(double delta)
		{

		}
		void IOpenGLEngine::RegisterCustomShader(ShaderMetaData customShader) const
		{

		}
	}
}

