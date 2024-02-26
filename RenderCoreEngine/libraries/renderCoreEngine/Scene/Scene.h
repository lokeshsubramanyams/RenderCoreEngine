#pragma once 
#include<string>
#include<vector>
#include<unordered_map>
#include <IGraphicsEngine.h>
#include <GraphicsObject.h>
#include <ICamera.h>
#include <MeshUtil.h>
#include <Mesh.h>
#include <ILight.h>
#include <GraphicsFactory.h>

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

			void AddShape(string objName, GeometryShapes shape);
			void AddTriangle(string objName);
			void AddQuad(string objName);
			template<typename T>
			T AddCamera(string objName);
			template<typename T>
			T AddLight(string objName);

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

			void AddGridEditorLines(string objName);
			
			GraphicsFactory* gFactory;


		private:
			int sceneObjectCount = 0;
			string GetSceneUniqueName(string name);
			void AddDefaultSceneObjects();
			void AddToScene(string keu, GraphicsObject* obj, IRenderer* renderer);
			template<typename T>
			T AddToScene(tupleGraphicsObject obj);
			template<typename T>
			T AddToScene(tupleCameraObject obj);
			template<typename T>
			T AddToScene(tupleLightObject obj);
			
		};

	}
}
