#pragma once
#include "RcMath.h"
#include "Transform.h"
#include "IComponent.h"
namespace RCEngine
{
  namespace RenderCore
  {
    using namespace MathLib;
    class GraphicsObject
    {
      
    private:
      Transform transform;

      IComponent components[];
      
    };
  }
}