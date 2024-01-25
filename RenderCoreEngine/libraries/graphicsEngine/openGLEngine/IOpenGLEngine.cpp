#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void IOpenGLEngine::Update(double delta)
		{
			Debug::Log("deltaTime: " + std::to_string(delta));

			testVariable += 0.005 * testVariable1;

			if (testVariable > 1 || testVariable < 0) {
				testVariable1 = testVariable1 * -1.0f;
			}
		}
	}
}

