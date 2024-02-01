#include "OpenGLShader.h"
#include "Debug.h"

namespace RCEngine
{
	using namespace Debugger;
	namespace OpenGLEngine
	{
		OpenGLShader::OpenGLShader(GLuint shaderProgram,std::vector<const char*> uniformKeys)
			:thisShaderProgram(shaderProgram)
		{
			for (int i = 0; i < uniformKeys.size(); i++)
			{
				this->AddUniform(uniformKeys[i]);
			}
		}

		void OpenGLShader::UseProgram()
		{
			glUseProgram(thisShaderProgram);
		}
		
		GLuint OpenGLShader::GetUniform(const char* uniformKey)
		{
			if (uniformLocations.count(uniformKey) <= 0)
			{
				AddUniform(uniformKey);
			}
			return uniformLocations[uniformKey];
		}
		void OpenGLEngine::OpenGLShader::AddUniform(const char* uniformKey)
		{
			GLuint id = glGetUniformLocation(thisShaderProgram, uniformKey);
			if (id == -1)
			{
				Debug::LogError("Error getting uniform loacaton of:" + std::string(uniformKey));
				
			}
			uniformLocations.insert({ uniformKey, id });
		}

		void OpenGLShader::ApplyProperty(const char* uniformKey, MathLib::Matrix44 value)
		{
			glUniformMatrix4fv(GetUniform(uniformKey), 1, GL_FALSE, glm::value_ptr(value));
		}
		void OpenGLShader::ApplyProperty(const char* uniformKey, MathLib::Vector4 value)
		{
			glUniform4fv(GetUniform(uniformKey), 1, glm::value_ptr(value));
		}
		void OpenGLShader::ApplyProperty(const char* uniformKey, MathLib::Vector3 value)
		{
			glUniform3fv(GetUniform(uniformKey), 1, glm::value_ptr(value));
		}
		void OpenGLShader::ApplyProperty(const char* uniformKey, MathLib::Vector2 value)
		{
			glUniform2fv(GetUniform(uniformKey), 1, glm::value_ptr(value));
		}
		void OpenGLShader::Log()
		{
			Debug::Log("thisShaderProgram:",std::to_string(thisShaderProgram));
			for (const auto& pair : uniformLocations) {
				Debug::Log(pair.first.c_str(), std::to_string(pair.second));
			}
		}
	}
}