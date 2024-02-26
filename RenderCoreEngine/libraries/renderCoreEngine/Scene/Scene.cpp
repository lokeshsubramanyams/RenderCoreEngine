#include "Scene.h"

namespace RCEngine
{
	namespace RenderCore
	{
	
		Scene::Scene(IGraphicsEngine* graphicsEngine, string name)
		{
			this->name = name;

			this->graphicsEngine = graphicsEngine;

			gFactory = new GraphicsFactory(graphicsEngine);

			AddDefaultSceneObjects();

		}

		void Scene::LoadAll()
		{
			for (int i = 0; i < renderers.size(); i++)
			{
				renderers[i]->Load();
			}
		}

		void Scene::Load(IRenderer* renderer)
		{
			renderer->Load();
		}
		
		void Scene::Render()
		{
			graphicsEngine->PreRender();
		
			for (int cam = 0; cam < cameras.size(); cam++)
			{
				graphicsEngine->PreRender(cameras[cam]);

				for (int ren = 0; ren < renderers.size(); ren++)
				{
					renderers[ren]->Render(cameras[cam],lights[0]);// ->GetViewProjectionMatrix());
				}
				graphicsEngine->PostRender(cameras[cam]);
			}
			graphicsEngine->PostRender();
		}

		void Scene::Update(float deltaTime)
		{
			for (int i = 0; i < behaviours.size(); i++)
			{
				behaviours[i]->Update(deltaTime);
			}
		}

		void Scene::AttachComponent(string objectName, IComponent* component)
		{
			sceneObjects[objectName]->AttachComponent(component);

			if (component->type == ComponentType::BehaviourComp)
			{
				behaviours.push_back(static_cast<IBehaviour*>(component));
			}
			else if (component->type == ComponentType::LineRendererComp)
			{
				IRenderer* renderer = static_cast<IRenderer*>(component);
				renderers.push_back(renderer);
				renderer->Load();
			}
		}

		GraphicsObject* Scene::GetGraphicsObject(string name)
		{
			if (sceneObjects.count(name) > 0)
			{
				return sceneObjects[name];
			}
			return nullptr;
		}

		string Scene::GetSceneUniqueName(string name)
		{
			return string(name+"-"+std::to_string(++sceneObjectCount));
		}

		void Scene::AddShape(string objName, GeometryShapes shape)
		{
			AddToScene<IMeshRenderer*>(gFactory->AddRenderingObject(objName, GraphicsTag::Scene, shape));
		}

		void Scene::AddTriangle(string objName)
		{
			AddToScene<IMeshRenderer*>(gFactory->AddRenderingObject(objName, GraphicsTag::Scene, MeshUtil::Triangle()));
		}

		void Scene::AddQuad(string objName)
		{
			AddToScene<IMeshRenderer*>(gFactory->AddRenderingObject(objName, GraphicsTag::Scene, MeshUtil::Quad()));
		}
	
		template<typename T>
		T Scene::AddCamera(string camName)
		{
			return AddToScene<T>(gFactory->AddCameraObject(camName, GraphicsTag::Scene, { {0.142f,0.216f,0.149f,1.0f}, CameraType::Perspective,45.0f,0.1f,1000.0f }));
		}
		template<typename T>
		T Scene::AddLight(string objName)
		{
			return AddToScene<T>(gFactory->AddLightObject(objName, GraphicsTag::Scene, LightType::Directional));
		}
		template<typename T>
		T RenderCore::Scene::AddToScene(tupleGraphicsObject obj)
		{
			AddToScene(std::get<0>(obj), std::get<1>(obj), std::get<2>(obj));
			return static_cast<T>(std::get<2>(obj));
		}
		template<typename T>
		T RenderCore::Scene::AddToScene(tupleCameraObject obj)
		{
			cameras.push_back(std::get<2>(obj));
			AddToScene(std::get<0>(obj), std::get<1>(obj));
			return static_cast<T>(std::get<2>(obj));
		}
		template<typename T>
		T RenderCore::Scene::AddToScene(tupleLightObject obj)
		{
			lights.push_back(std::get<2>(obj));
			AddToScene(std::get<0>(obj), std::get<1>(obj));
			return static_cast<T>(std::get<2>(obj));
		}

		void RenderCore::Scene::AddToScene(string key, GraphicsObject* obj, IRenderer* renderer = nullptr)
		{
			sceneObjects.insert({ key,obj });
			if (obj->tag != GraphicsTag::Editor)
			{
				sceneObjectKeys.push_back(key);
			}
			if (renderer)
			{
				renderers.push_back(renderer);
				Load(renderer);
			}
		}

	////////////Editor related set up in scene/////////////////////////////////	

		void Scene::AddDefaultSceneObjects()
		{
			AddCamera<ICamera*>("MainCamera");
			GraphicsObject* cameraObject = GetGraphicsObject("MainCamera");
			cameraObject->transform->position = Vector3(0.0f, 5.0f, -10.0f);
			cameraObject->transform->rotation = Quaternion(Vector3(glm::radians(-22.5f), 0.0f, 0.0f));
			AddLight<ILight*>("DirectionLight");

			AddGridEditorLines("GridLines");
		}

		void Scene::AddGridEditorLines(string objName)
		{
			ILineRenderer* lineRenderer = AddToScene<ILineRenderer*>(gFactory->AddRenderingObject(objName, GraphicsTag::Editor, MeshUtil::GetGridLines()));
			lineRenderer->color = Color4(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
}