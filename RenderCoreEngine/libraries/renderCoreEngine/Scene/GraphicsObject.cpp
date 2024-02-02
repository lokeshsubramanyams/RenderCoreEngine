#include "GraphicsObject.h"
#include<typeinfo>
#include<IRenderer.h>
namespace RCEngine
{
	namespace RenderCore
	{
		GraphicsObject::GraphicsObject()
		{
			transform = new Transform(Vector3(0, 0, 0), Quaternion(), Vector3(1, 1, 1));
		}
		GraphicsObject::GraphicsObject(std::string name)
		{
			this->name = name;
			this->transform = new Transform(Vector3(0, 0, 0), Quaternion(), Vector3(1, 1, 1));
		}
		void GraphicsObject::AttachComponent(IComponent& component)
		{
			Debug::Log("Trying to attach:", std::to_string(component.type));
			if (components.count(component.type) > 0)
			{
				Debug::Log("already component type attached:", std::to_string(component.type));
				return;
			}
			components.insert({ component.type, &component });
			
			if (component.type == ComponentType::MeshRendererComp)// typeid(&component) == typeid(IRenderer))
			{
				Debug::Log("Linking Transform with renderer");
				component.LinkTransform(transform);
			}
		
		}
	}
}