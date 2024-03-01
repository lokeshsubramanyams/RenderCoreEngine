#include "GraphicsFactory.h"
#include "GraphicsFactory.h"
namespace RCEngine
{
	namespace RenderCore
	{
			GraphicsFactory::GraphicsFactory(IGraphicsEngine* graphicsEngine)
			{
				this->graphicsEngine = graphicsEngine;
			}
		
			tupleGraphicsObject GraphicsFactory::AddRenderingObject(string objName, GraphicsTag tag, GeometryShapes shape)
			{
				return  CreateGraphicsObject(objName, tag, MeshUtil::GeometricalShapes(shape));
				
			}

      tupleGraphicsObject GraphicsFactory::IAddRenderingObject(string objName, GraphicsTag tag, GeometryShapes shape)
      {
				GraphicsObject* obj = new GraphicsObject(objName); obj->tag = tag;
				IShader* shader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01);

				 IMeshAbstract* imesh =  MeshUtil::IGeometricalShapes(shape);

				IComponent* component = graphicsEngine->GetFactory()->CreateMeshRendererComp(*imesh, *shader);
				obj->AttachComponent(component);
				return std::make_tuple(objName, obj, static_cast<IRenderer*>(component));
      }

			tupleGraphicsObject GraphicsFactory::AddRenderingObject(string objName, GraphicsTag tag, Mesh* mesh)
			{
				return CreateGraphicsObject(objName, tag, mesh);
			}

			tupleGraphicsObject GraphicsFactory::AddRenderingObject(string objName, GraphicsTag tag, Line* line)
			{
				GraphicsObject* lineObj = new GraphicsObject(objName); lineObj->tag = tag;
				IShader* shader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT);
				IComponent* component = graphicsEngine->GetFactory()->CreateLineRendererComp(*line, *shader);
				lineObj->AttachComponent(component);
				IRenderer* renderer = static_cast<IRenderer*>(component);
				return std::make_tuple(objName, lineObj, renderer);
			}

			tupleCameraObject GraphicsFactory::AddCameraObject(string objName, GraphicsTag tag, CameraSetting cSetting)
			{
				GraphicsObject* cameraObject = new GraphicsObject(objName); cameraObject->tag = tag;
				Camera* camera = new Camera(cSetting);
				cameraObject->AttachComponent(camera);
				return std::make_tuple(objName, cameraObject, camera);
			}

			tupleLightObject GraphicsFactory::AddLightObject(string objName, GraphicsTag tag, LightType lightType)
			{
				GraphicsObject* lightObj = new GraphicsObject(objName); lightObj->tag = tag;
				ILight* light = nullptr;
				switch (lightType)
				{
				case RCEngine::Directional:light = new DirectionalLight();
					break;
				case RCEngine::Point:light = new DirectionalLight();//need to implement this in shader and implement until then DirectionalLight
					break;
				case RCEngine::Area:light = new DirectionalLight();//need to implement this in shader and implement until then DirectionalLight
					break;
				}
				
				lightObj->AttachComponent(light);
				return std::make_tuple(objName, lightObj, light);
			}
			
			tupleGraphicsObject GraphicsFactory::CreateGraphicsObject(string objName, GraphicsTag tag, Mesh* mesh)
			{
				GraphicsObject* obj = new GraphicsObject(objName);obj->tag = tag;
				IShader* shader = graphicsEngine->GetLoadedShader(CONST::SHADERKEY::DEFAULT_VERTEX_FRAGMENT_V01);
				IComponent* component = graphicsEngine->GetFactory()->CreateMeshRendererComp(*mesh, *shader);
				obj->AttachComponent(component);
				return std::make_tuple(objName, obj, static_cast<IRenderer*>(component));
			}
			
		
	}
}