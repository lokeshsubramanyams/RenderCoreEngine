#pragma once 
#include "IShader.h"
#include "Debug.h"
#include <GL/glew.h>
#include<unordered_map>
namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace Debugger;
		using namespace RenderCore;
		using namespace MathLib;
		class OpenGLShader : public IShader
		{
		public:
			OpenGLShader(GLuint shaderProgram, std::vector<const char*> uniformKeys);
			void UseProgram()override;
			void ApplyProperty(const char* uniformKey, MathLib::Matrix44 value)override;
			void ApplyProperty(const char* uniformKey, MathLib::Vector4 value)override;
			void ApplyProperty(const char* uniformKey, MathLib::Vector3 value)override;
			void ApplyProperty(const char* uniformKey, MathLib::Vector2 value)override;
			void Log()override;
		private:
			const GLuint thisShaderProgram;
			std::unordered_map<std::string, GLuint>uniformLocations;
			GLuint GetUniform(const char* uniformKey);
			void AddUniform(const char* uniformKey);
			
		};


	}
}