#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void IOpenGLEngine::Update(double delta)
		{
			Debug::Log("deltaTime: ",delta);

			testVariable += 0.01*testVariable1 * delta;

			if (testVariable > 1 || testVariable < 0) {
				testVariable1 = testVariable1 * -1.0f;
			}
		}
	}
}

