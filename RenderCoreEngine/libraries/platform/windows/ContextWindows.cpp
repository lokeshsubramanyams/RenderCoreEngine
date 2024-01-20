#include "ContextWindows.h"
#include "Debug.h"
namespace RCEngine
{
	using namespace RCEngine::Debugger;
	namespace Platform
	{

		ContextWindows::ContextWindows(MathLib::Rect _viewport)
			:IContext(_viewport)
		{
			if (!glfwInit())
			{
				Debug::LogError("glfw init failed with return code -1");
				return;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			GLFWwindow* window = glfwCreateWindow(_viewport.width, _viewport.height, "RCEngine", NULL, NULL);

			

			if (!window) {
				// Window or OpenGL context creation failed
				glfwTerminate();
				Debug::LogError("glfw Window or OpenGL context creation failed with return code -1");
				return;
			}

		}

		ContextWindows::~ContextWindows()
		{

		}

	}
}