#pragma once
#include<GLFW/glfw3.h>
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
	namespace Platform
	{

			static void glfw_error_callback(int error, const char* description)
			{
				fprintf(stderr, "GLFW Error %d: %s\n", error, description);
			}

			inline GLFWwindow* CreateGlfwWindow(const char* title, int width, int height)
			{
				glfwSetErrorCallback(glfw_error_callback);

				if (!glfwInit())
				{
					Debug::LogError("glfw init failed with return code -1");
					return nullptr;
				}
				else
					Debug::Log("glfw init");

				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

				GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);


				if (!window) {
					// Window or OpenGL context creation failed
					glfwTerminate();
					Debug::LogError("glfw Window or OpenGL context creation failed with return code -1");
					return nullptr;
				}
				else
					Debug::Log("glfw Window or OpenGL context created");


				return window;
			}
		
	}
}