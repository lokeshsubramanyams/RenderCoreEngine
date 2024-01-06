
#include "Context.hpp"
#include "MathLib.hpp"
#include "Debug.hpp"
#include "RCEngineMain.hpp"

using namespace RCEngine::Platform;
using namespace RCEngine::Debug;
using namespace RCEngine::MathLib;
int main()
{

	Context* context = Context::CreateContext({0,0,600,400});// new RCEngine::Platform::Context();

	Rect viewport = context->GetViewport();
	Debug::Log(string("viewport:{" + to_string(viewport.width) + "," + to_string(viewport.height) + "}"));

	delete context;

	return 0;
}
