// RenderCoreEngine.cpp : Defines the entry point for the application.

#ifdef PLATFORM_WINDOWS
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "Context.hpp"
#endif

#ifdef PLATFORM_WEBASSEMBLY
#include<emscripten.h>
#endif

#include "RCEngine.hpp"


#include<glm/glm.hpp>
#include "Math.hpp"
#include "Transform.hpp"



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

	double length = (b - a).length();

	cout << "length :" << length << endl;


	return 0;
}
