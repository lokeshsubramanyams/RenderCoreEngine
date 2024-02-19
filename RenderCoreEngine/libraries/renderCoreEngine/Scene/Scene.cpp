#include "Scene.h"
#include <Camera.h>
#include <ILineRenderer.h>

namespace RCEngine
{
	namespace RenderCore
	{
	
		Scene::Scene(IGraphicsEngine* graphicsEngine, string name)
		{
			this->name = name;

			this->graphicsEngine = graphicsEngine;

			AddDefaultSceneObjects();

		}

		void Scene::AddGraphicsObject(string objName)
		{

		}
		void Scene::AddShape(string objName, GeometryShapes shape)
		{
			CreateGraphicsObject(objName, MeshUtil::GeometricalShapes(shape));
		}

		void Scene::AddTriangle(string objName)
		{
			CreateGraphicsObject(objName, MeshUtil::Triangle());
		}

		void Scene::AddQuad(string objName)
		{
			CreateGraphicsObject(objName, MeshUtil::Quad());
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
		}

		GraphicsObject* Scene::GetGraphicsObject(string name)
		{
			if (sceneObjects.count(name) > 0)
			{
				return sceneObjects[name];
			}
			return nullptr;
		}

		void Scene::AddDefaultSceneObjects()
		{
			AddCamera("MainCamera");
			AddLines("GridLines");
			AddLight("DirectionLight");
		}

		void Scene::AddCamera(string camName)
		{
			GraphicsObject* cameraObject = new GraphicsObject(camName);

			Camera* camera = new Camera({ {0.142f,0.216f,0.149f,1.0f}, CameraType::Perspective,45.0f,0.1f,1000.0f });
			cameraObject->AttachComponent(camera);
			cameraObject->transform->position = Vector3(0.0f, 5.0f, -10.0f);
			cameraObject->transform->rotation = Quaternion(Vector3(glm::radians(-22.5f), 0.0f, 0.0f));
			
			cameras.push_back(camera);

			AddToScene(camName, cameraObject,nullptr);
		}

    void Scene::AddLines(string objName)
    {
			GraphicsObject* lineObj = new GraphicsObject(objName);
			lineObj->tag = "editor";
			IShader* defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);
			//defaultShader->Log();
			Line* lines = MeshUtil::GetGridLines();
			IComponent* component = graphicsEngine->GetFactory()->CreateLineRendererComp(*lines, *defaultShader);
			lineObj->AttachComponent(component);
			static_cast<ILineRenderer*>(component)->color = Color(0.0f, 0.0f, 0.0f, 1.0f);
			IRenderer* renderer = static_cast<IRenderer*>(component);
			
			AddToScene(objName, lineObj, renderer);
    }

		void Scene::AddLight(string objName)
		{
			GraphicsObject* lightObj = new GraphicsObject(objName);
			DirectionalLight* light = new DirectionalLight();
			lightObj->AttachComponent(light);
			lightObj->transform->rotation = Quaternion(Vector3(glm::radians(-60.0f), 0.0f, 0.0f));
			lights.push_back(light);
			AddToScene(objName, lightObj, nullptr);
		}

		void Scene::CreateGraphicsObject(string name, Mesh* mesh)
		{
			GraphicsObject* shapeObj = new GraphicsObject(name);
			IShader* defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01);
			//defaultShader->Log();
			IComponent* component2 = graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh, *defaultShader);
			shapeObj->AttachComponent(component2);
			IRenderer* renderer = static_cast<IRenderer*>(component2);

			AddToScene(name, shapeObj, renderer);
		}

		void RenderCore::Scene::AddToScene(string key, GraphicsObject* obj,IRenderer* renderer=nullptr)
		{
			sceneObjects.insert({ key,obj });
			if (obj->tag != "editor")
			{
				sceneObjectKeys.push_back(key);
			}
			if (renderer)
			{
				renderers.push_back(renderer);
				Load(renderer);
			}
		}
	}
}