#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "MathLib.h"
#include "Transform.h"
#include "IComponent.h"
#include "IBehaviour.h"
#include "Debug.h"


namespace RCEngine
{
  namespace RenderCore
  {
    using namespace MathLib;
    using namespace Debugger;
    class GraphicsObject
    {
		public:
			std::string name;
			GraphicsObject();
			GraphicsObject(std::string name);
			void AttachComponent(IComponent *component);
			void Update(float deltaTime);
			RCEngine::RenderCore::Transform* transform;
    private:
      //default and required
      std::unordered_map<ComponentType, IComponent*> components;
			
			
			template<typename CompType>
			CompType GetComponent(ComponentType type);

			void BindComponents(IComponent* component);

			IBehaviour* behaviour;
      
    };
		
	}
}