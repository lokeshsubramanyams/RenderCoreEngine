#include "OpenGL4x.hpp"

#include "default_vert.h"


namespace RCEngine
{
	namespace OpenGLEngine
	{
		void OpenGL4x::TestAPIs()
		{


			GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);

			
			const GLchar* shaderSource[] = { reinterpret_cast<const GLchar*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_vert) };
			GLint lengths[] = { static_cast<GLint>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_vert_len) };

			// Provide the shader source to OpenGL
			//glShaderSource(vertShader, 1, shaderSource, lengths);

			// Compile the shader
			//glCompileShader(vertShader);



			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// Draw the triangle
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
	}
}