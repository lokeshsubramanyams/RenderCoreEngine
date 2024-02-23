#include "GraphicsFactory.h"
namespace RCEngine
{
	namespace RenderCore
	{
			GraphicsFactory::GraphicsFactory(IGraphicsEngine* graphicsEngine)
			{
				this->graphicsEngine = graphicsEngine;
			}
			void GraphicsFactory::AddGraphicsObject(string objName)
			{

			}

			void GraphicsFactory::AddShape(string objName, GeometryShapes shape) 
			{

			}

			void GraphicsFactory::AddTriangle(string objName) 
			{

			}

			void GraphicsFactory::AddQuad(string objName) 
			{

			}
			void GraphicsFactory::AddCamera(string objName) 
			{

			}

			void GraphicsFactory::AddLight(string objName) 
			{

			}

			std::tuple<string, GraphicsObject*, IMeshRenderer*> GraphicsFactory::AddRenderingObject(string objName, GraphicsTag tag, Mesh* mesh)
			{
				return std::tuple<string, GraphicsObject*, IMeshRenderer*>();
			}

			std::tuple<string, GraphicsObject*, ILineRenderer*> GraphicsFactory::AddRenderingObject(string objName, GraphicsTag tag, Line* line)
			{
				return std::tuple<string, GraphicsObject*, ILineRenderer*>();
			}

			std::tuple<string, GraphicsObject*, ICamera*> GraphicsFactory::AddCameraObject(string objName, GraphicsTag tag, CameraSetting cSetting)
			{
				return std::tuple<string, GraphicsObject*, ICamera*>();
			}
			
		
	}
}