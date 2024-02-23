#pragma once 
#include<string>
#include<vector>
#include<unordered_map>
#include "GraphicsObject.h"
#include "ICamera.h"
#include <IGraphicsEngine.h>
#include <MeshUtil.h>
#include <Mesh.h>
#include "DirectionalLight.h"


namespace RCEngine
{
	namespace RenderCore
	{
		using namespace MathLib;
		using namespace Debugger;
		using namespace GraphicsEngine;
		class Scene
		{
		public:
			string name;
			Scene(IGraphicsEngine* graphicsEngine, string name);

			void AddGraphicsObject(string objName);
			void AddShape(string objName, GeometryShapes shape);
			void AddTriangle(string objName);
			void AddQuad(string objName);
			void AddCamera(string objName);
			void AddLight(string objName);

			void LoadAll();
			void Load(IRenderer* renderer);
			void Render();
			void Update(float deltaTime);

			void AttachComponent(string objectName, IComponent* component);

			GraphicsObject* GetGraphicsObject(string name);

			std::vector<string>sceneObjectKeys;
			std::string sceneHierarchySelectedKey;
		protected:
			std::unordered_map<string, GraphicsObject*>sceneObjects;
			std::vector<ICamera*>cameras;
			std::vector<ILight*>lights;
			std::vector<IRenderer*>renderers;
			std::vector<IBehaviour*>behaviours;
			IGraphicsEngine* graphicsEngine;

			

			void AddGridLines(string objName);
			

		private:
			void AddDefaultSceneObjects();
			void CreateGraphicsObject(string name, Mesh* mesh);
			void AddToScene(string keu, GraphicsObject* obj, IRenderer* renderer);
			
		};

	}
}
