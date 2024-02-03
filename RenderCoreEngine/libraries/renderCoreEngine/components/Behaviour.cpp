#include "Behaviour.h"
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
  namespace RenderCore
  {
		float testVariable = 1.0f;
		float direction = 1.0f;
		
    void Behaviour::Update(float deltaTime)
    {
			Debug::Log("Behaviour::Update:", deltaTime);

			testVariable += deltaTime * direction * 0.1;
			if (testVariable > 1.0 || testVariable < -1.0)direction *= -1.0;
			
			transform->scale = Vector3(testVariable, testVariable, testVariable);

			transform->rotation = Quaternion(Vector3(0,0,testVariable*10));
			
			transform->position = Vector3(testVariable, 0, 0);
    }

  }
}