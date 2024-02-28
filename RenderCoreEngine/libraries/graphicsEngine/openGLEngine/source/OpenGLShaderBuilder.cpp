#include "OpenGLShaderBuilder.h"
#include "OpenGLShader.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		
		void OpenGLShaderBuilder::PreLoadShaderBatch(std::vector<ShaderProgram>programsToLoad
			, std::unordered_map<std::string, ShaderMetaData> engineMetaData)
		{
			
			for (int index = 0; index < programsToLoad.size(); index++)
			{
				if (shaders.count(programsToLoad[index].generatedShaderKey) > 0)continue;

				std::string vkey = programsToLoad[index].vertexkey;
				std::string fkey = programsToLoad[index].fragmentkey;

				if (engineMetaData.count(vkey) <=0)
				{
					Debug::LogError("ShaderMetaData not exists:"+vkey);
					continue;
				}
				if(engineMetaData.count(fkey) <=0)
				{
					Debug::LogError("ShaderMetaData not exists:" + fkey);
					continue;
				}
				else
				{
					GLuint shaderProgram = this->LoadShader(engineMetaData[vkey], engineMetaData[fkey]);
					
					if (shaderProgram != -1)
					{

						std::vector<UniformMeta> metas(engineMetaData[vkey].uniforms);
						metas.insert(metas.end(), engineMetaData[fkey].uniforms.begin(), engineMetaData[fkey].uniforms.end());
						shaders.insert({ programsToLoad[index].generatedShaderKey,std::make_unique<RCEngine::OpenGLEngine::OpenGLShader>(shaderProgram,metas) });
						
					}

				}

				
			}
			
		}

		RCEngine::RenderCore::IShader* OpenGLShaderBuilder::GetShader(std::string generatedShaderKey)
		{
			if (shaders.count(generatedShaderKey) > 0)
			{
				return shaders[generatedShaderKey].get();
			}

			return nullptr;
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

		GLuint OpenGLShaderBuilder::LoadShader(ShaderMetaData vertices, ShaderMetaData fragment)
		{


			GLuint vertexShader = this->Compile(vertices);
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

			return shaderProgram;
		}
	}
}
