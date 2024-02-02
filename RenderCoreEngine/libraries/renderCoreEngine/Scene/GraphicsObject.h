#pragma once
#include "MathLib.h"
#include "Transform.h"
#include "IComponent.h"
#include <string>
#include <unordered_map>
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
			void AttachComponent(IComponent &component);
    private:
      //default and required
      RCEngine::RenderCore::Transform* transform;
      std::unordered_map<ComponentType, IComponent*> components;
			
      
    };
  }
}