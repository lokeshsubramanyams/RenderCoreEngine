#pragma once
#include <string>
#include<tuple>
#include <RenderCore.h>
#include <IGraphicsEngine.h>
#include <GraphicsObject.h>
#include <IMeshRenderer.h>
#include <ILineRenderer.h>
#include <MeshUtil.h>
#include <DirectionalLight.h>

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace std;
		using namespace GraphicsEngine;

		using tupleGraphicsObject = std::tuple<string, GraphicsObject*, IRenderer*>;
		using tupleCameraObject = std::tuple<string, GraphicsObject*, ICamera*>;
		using tupleLightObject = std::tuple<string, GraphicsObject*, ILight*>;

		class GraphicsFactory
		{
		public:
			GraphicsFactory(IGraphicsEngine* graphicsEngine);
				
			tupleGraphicsObject AddRenderingObject(string objName, GraphicsTag tag, GeometryShapes shape);
			tupleGraphicsObject AddRenderingObject(string objName,GraphicsTag tag, Mesh* mesh);
			tupleGraphicsObject AddRenderingObject(string objName, GraphicsTag tag, Line* line);
			tupleCameraObject AddCameraObject(string objName, GraphicsTag tag, CameraSetting cSetting);
			tupleLightObject  AddLightObject(string objName, GraphicsTag tag,LightType lightType);
			
		private:
			IGraphicsEngine* graphicsEngine;
			
			tupleGraphicsObject CreateGraphicsObject(string objName, GraphicsTag tag, Mesh* mesh);
			
		};
	}
}