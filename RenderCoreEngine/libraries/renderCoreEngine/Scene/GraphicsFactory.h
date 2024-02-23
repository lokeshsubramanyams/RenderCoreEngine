#pragma once
#include <string>
#include<tuple>
#include <RenderCore.h>
#include <IGraphicsEngine.h>
#include <GraphicsObject.h>
#include <IMeshRenderer.h>
#include <ILineRenderer.h>

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace std;
		using namespace GraphicsEngine;
		class GraphicsFactory
		{
		public:
			GraphicsFactory(IGraphicsEngine* graphicsEngine);
			void AddGraphicsObject(string objName);
			void AddShape(string objName, GeometryShapes shape);
			void AddTriangle(string objName);
			void AddQuad(string objName);
			void AddCamera(string objName);
			void AddLight(string objName);

			std::tuple<string, GraphicsObject*, IMeshRenderer*> AddRenderingObject(string objName,GraphicsTag tag, Mesh* mesh);
			std::tuple<string,GraphicsObject*, ILineRenderer*> AddRenderingObject(string objName, GraphicsTag tag, Line* line);
			std::tuple<string,GraphicsObject*, ICamera*> AddCameraObject(string objName, GraphicsTag tag, CameraSetting cSetting);

			
			
		private:
			IGraphicsEngine* graphicsEngine;
			
		};
	}
}