// RenderCoreEngine.cpp : Defines the entry point for the application.

#ifdef PLATFORM_WINDOWS
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#endif

#ifdef PLATFORM_WEBASSEMBLY
#include<emscripten.h>
#endif

#ifdef OPENGL
#include "Context.hpp"
#endif
#ifdef WEBGL
#include "Context.hpp"
#endif
#ifdef VULKAN
#include "Context.hpp"
#endif
#ifdef WEBGPU
#include "Context.hpp"
#endif


#include "Math.hpp"
#include "Transform.hpp"

#include "RCEngine.hpp"

using namespace std;
using namespace RCEngine::MathLib;
int main()
{
	cout << "Hello CMake." << endl;

	Vector3 a = { 0.2,0.1,0.3 };
	Vector3 b = { 0.3,0.1,0.3 };
	Vector3 ab = b - a;
	Transform transform = {};
	transform.position = a;
	transform.rotation = { 0.0 ,0.0,0.0,1.0};
	transform.Scale = { 1.0,1.0,1.0 };

	auto length = (b - a).length();

	cout << "length :" << length << endl;


	return 0;
}
