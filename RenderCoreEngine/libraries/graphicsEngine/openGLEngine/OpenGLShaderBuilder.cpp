#include "OpenGLShaderBuilder.h"
#include "ShaderMetaData.h"
#include "OpenGLShader.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		
		std::unordered_map<std::string, std::unique_ptr<RCEngine::RenderCore::IShader>> OpenGLShaderBuilder::PreLoadShaderBatch(std::vector<ShaderProgram>programsToLoad
			, std::unordered_map<std::string, ShaderMetaData> engineMetaData)
		{
			
			std::unordered_map<std::string, std::unique_ptr<RCEngine::RenderCore::IShader>> shaders;
			for (int index = 0; index < programsToLoad.size(); index++)
			{
				std::string vkey = programsToLoad[index].vertexkey;
				std::string fkey = programsToLoad[index].fragmentkey;

				if (engineMetaData.count(vkey) < 0)
				{
					Debug::LogError("ShaderMetaData not exists:"+vkey);
					continue;
				}
				if(engineMetaData.count(fkey) < 0)
				{
					Debug::LogError("ShaderMetaData not exists:" + fkey);
					continue;
				}
				else
				{
					GLuint shaderProgram = this->LoadShader(engineMetaData[vkey], engineMetaData[fkey]);
					
					GLuint uniformKey = glGetUniformLocation(shaderProgram, programsToLoad[index].uniformTransformationMatrix.c_str());

				}

				
			}
			
			return shaders;
		}

		GLuint OpenGLShaderBuilder::Compile(ShaderProgram program)
		{


			return GLuint();
		}


		GLuint OpenGLShaderBuilder::Compile(ShaderMetaData mData)
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

		GLuint OpenGLShaderBuilder::LoadShader(ShaderMetaData vertex, ShaderMetaData fragment)
		{


			GLuint vertexShader = this->Compile(vertex);
			GLuint fragmentShader = this->Compile(fragment);

			GLuint shaderProgram = glCreateProgram();

			if (shaderProgram == 0)
			{
				Debug::LogError("Error on creating shader program\n");
				return -1;
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
				return -1;
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			//GLuint uniformKey = glGetUniformLocation(shaderProgram, vertex.unifromKey);
		//	Debug::Log("uniformKey:", std::to_string(uniformKey));
			//return { vertex.shaderKey,fragment.shaderKey,shaderProgram,uniformKey };
			return shaderProgram;
		}
	}
}
