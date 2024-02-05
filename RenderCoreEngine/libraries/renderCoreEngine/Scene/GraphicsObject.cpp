#include "GraphicsObject.h"
#include "Camera.h"


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

		void GraphicsObject::AttachComponent(IComponent *component)
		{
			components.insert({ component->type, component });
			
			this->BindComponents(component);
		}

		void GraphicsObject::Update(float deltaTime)
		{
			if (behaviour != nullptr)
			{
				behaviour->Update(deltaTime);
			}
		}

		void GraphicsObject::BindComponents(IComponent* component)
		{
			if (component->type == ComponentType::BehaviourComp)
			{
				behaviour = GetComponent<IBehaviour*>(ComponentType::BehaviourComp);
				behaviour->RequiredComponent(transform);
			}
			else if (component->type == ComponentType::MeshRendererComp)
			{
				GetComponent<IBehaviour*>(ComponentType::MeshRendererComp)->RequiredComponent(transform);
			}
			else if (component->type == ComponentType::CameraComp)
			{
				GetComponent<Camera*>(ComponentType::CameraComp)->RequiredComponent(transform);
			}
		}


		template<typename CompType>
		inline CompType GraphicsObject::GetComponent(ComponentType type)
		{
			return static_cast<CompType>(components[type]);
		}
		template<typename CompType>
		inline CompType* GraphicsObject::GetComponent(IComponent *pointer)
		{
			return dynamic_cast<CompType*>(pointer);
		}
	}
}