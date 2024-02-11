#include "Behaviour.h"
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
  namespace RenderCore
  {
		Behaviour::Behaviour(float _speed)
		{
			speed = _speed;
		}

		void Behaviour::Update(float deltaTime)
    {
			testVariable += deltaTime * direction * speed;

			if (testVariable > 1.0f || testVariable < -1.0f)direction *= -1.0;
			
			//transform->scale = Vector3(testVariable, testVariable, testVariable);

			transform->rotation = Quaternion(Vector3(0, testVariable*3,0));
			
			transform->position = Vector3(0, testVariable, 1);
    }

  }
}