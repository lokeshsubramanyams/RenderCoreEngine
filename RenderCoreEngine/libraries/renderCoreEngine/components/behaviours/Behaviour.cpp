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

			if (testVariable > 1.0 || testVariable < -1.0)direction *= -1.0;
			
			//transform->scale = Vector3(testVariable, testVariable, testVariable);

			transform->rotation = Quaternion(Vector3(0,0,testVariable*10));
			
			transform->position = Vector3(testVariable, 0, 0);
    }

  }
}