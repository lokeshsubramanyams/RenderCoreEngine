

#include "RCEngineMain.h"
#include "RenderCore.h"
#include "RenderCoreEngine.h"

#include "Debug.h"

using namespace RCEngine;
using namespace RCEngine::Debugger;
using namespace RCEngine::RenderCore;

int main()
{
	/*PlatformType pType = PlatformType::WINDOWS;
	GraphicsEngine ge3  = GraphicsEngine::OPENGL_3x_ENGINE;//for browser
	GraphicsEngine ge4 = GraphicsEngine::OPENGL_4x_ENGINE;//for windows

	Vector3 vert[3];
	vert[0] = { 0,0,0 };
	vert[1] = { 1,0,0 };
	vert[2] = { 0.5,1,0 };
	int indices[3] = { 0,1,2 };

	Mesh* mesh = new Mesh(vert, indices);

	delete mesh;
	*/
	int x;
	Debug::Log("main");
	RenderCoreEngine* engine = new RenderCoreEngine();
	engine->InitilizeEngine();

	return 0;
}
