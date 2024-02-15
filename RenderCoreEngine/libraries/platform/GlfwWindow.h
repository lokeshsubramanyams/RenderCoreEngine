#pragma once
#include<GLFW/glfw3.h>
#include "Debug.h"
#include "MathLib.h"
#include <functional>
namespace RCEngine
{
	using namespace Debugger;
	namespace Platform
	{

			inline std::function<void(GLFWwindow*, MathLib::Rect)> resizeCallBack;

			static void glfwErrorCallback(int error, const char* description)
			{
				fprintf(stderr, "GLFW Error %d: %s\n", error, description);
			}
			inline void framebufferResizeCallback(GLFWwindow* window, int width,int height)
			{
				if (resizeCallBack)
				{
					Debug::Log("Resized");
					resizeCallBack(window, Rect{ 0,0, width,height });
				}
			}
			
			inline GLFWwindow* CreateGlfwWindow(const char* title, int width, int height)
			{
				glfwSetErrorCallback(glfwErrorCallback);

				if (!glfwInit())
				{
					Debug::LogError("glfw init failed with return code -1");
					return nullptr;
				}
				else
					Debug::Log("glfw init");

				
#if PLATFORM_WEBASSEMBLY
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
				glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
				
#else
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
				glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
				
				
				

				GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);


				if (!window) {
					// Window or OpenGL context creation failed
					glfwTerminate();
					Debug::LogError("glfw Window or OpenGL context creation failed with return code -1");
					return nullptr;
				}
				else
					Debug::Log("glfw Window or OpenGL context created");

				glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

				return window;
			}

			
		
	}
}