#include "Scene.h"
#include "Scene.h"
#include "Scene.h"
#include <Camera.h>

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
					renderers[ren]->Render(cameras[cam]->GetViewProjectionMatrix());
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
			return sceneObjects[name];
		}

		void Scene::AddDefaultSceneObjects()
		{
			AddCamera("MainCamera");
		}

		void Scene::AddCamera(string camName)
		{
			GraphicsObject* cameraObject = new GraphicsObject(camName);

			Camera* camera = new Camera({ {0.0f,0.0f,0.0f,1.0f}, CameraType::Perspective,45.0f,0.1f,1000.0f });
			cameraObject->AttachComponent(camera);
			cameraObject->transform->position = Vector3(0.0f, 0.0f, -1.0f);

			sceneObjects.insert({ camName,cameraObject });
			cameras.push_back(camera);
		}

    void Scene::AddLines(string objName)
    {
			GraphicsObject* lineObj = new GraphicsObject(objName);

			IShader* defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);
			defaultShader->Log();

			Vector3* vertices = new Vector3[6];
			vertices[0] = Vector3(0.0, -100.0, 0.0);
			vertices[1] = Vector3(0.0, 100.0, 0.0);
			vertices[2] = Vector3(-100.0, 0.0, 0.0);
			vertices[3] = Vector3(100.0, 0.0, 0.0);
			vertices[4] = Vector3(0.0, 0.0, -100.0);
			vertices[5] = Vector3(0.0, 0.0, 100.0);
			
			Line* lines = MeshUtil::GetGridLines();// new Line(vertices, 6);
			IComponent* component2 = graphicsEngine->GetFactory()->CreateLineRendererComp(*lines, *defaultShader);
			lineObj->AttachComponent(component2);
			sceneObjects.insert({ name,lineObj });
			IRenderer* renderer = static_cast<IRenderer*>(component2);
			renderers.push_back(renderer);
			Load(renderer);
    }

		void Scene::CreateGraphicsObject(string name, Mesh* mesh)
		{
			GraphicsObject* shapeObj = new GraphicsObject(name);
			IShader* defaultShader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);
			defaultShader->Log();
			IComponent* component2 = graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh, *defaultShader);
			shapeObj->AttachComponent(component2);
			sceneObjects.insert({ name,shapeObj });
			IRenderer* renderer = static_cast<IRenderer*>(component2);
			renderers.push_back(renderer);
			Load(renderer);
		}
	}
}