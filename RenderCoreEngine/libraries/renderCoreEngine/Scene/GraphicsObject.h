#pragma once
#include "MathLib.h"
#include "Transform.h"
#include "IComponent.h"
#include <string>
#include <vector>
namespace RCEngine
{
  namespace RenderCore
  {
    using namespace MathLib;
    class GraphicsObject
    {
		public:
			std::string name;
			GraphicsObject();
			GraphicsObject(std::string name);
			void AttachComponent(IComponent &component);
    private:
      Transform *transform;
      std::vector<IComponent*> components;

			
      
    };
  }
}