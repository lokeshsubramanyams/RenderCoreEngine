
#include "RCEngineMain.hpp"

#include "IContext.hpp"
#include "MathLib.hpp"
#include "Debug.hpp"
#include "Mesh.hpp"
#include "RenderCore.hpp"


using namespace RCEngine;
using namespace RCEngine::Platform;
using namespace RCEngine::Debugger;
using namespace RCEngine::MathLib;
using namespace RCEngine::RenderCore::VertexEngine;


int main()
{
	PlatformType pType = PlatformType::WINDOWS;
	GraphicsEngine ge3  = GraphicsEngine::OPENGL_3x_ENGINE;//for browser
	GraphicsEngine ge4 = GraphicsEngine::OPENGL_4x_ENGINE;//for windows

	//Context* context = Context::CreateContext({0,0,600,400});// new RCEngine::Platform::Context();

	//Rect viewport = context->GetViewport();
	
	//Debug::Log(string("viewport:{" + to_string(viewport.width) + "," + to_string(viewport.height) + "}"));

	Vector3 vert[3];
	vert[0] = { 0,0,0 };
	vert[1] = { 1,0,0 };
	vert[2] = { 0.5,1,0 };
	int indices[3] = { 0,1,2 };

	Mesh* mesh = new Mesh(vert,indices);

	delete mesh;
	//delete context;

	return 0;
}
