#include "GraphicsObject.h"

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
			components.push_back(&component);
		}
	}
}