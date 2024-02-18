#include "OpenGLComponentFactory.h"
#include "OpenGLMaterial.h"
#include "MeshFilter.h"
namespace RCEngine
{
	namespace OpenGLEngine
	{
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateMeshRendererComp(Mesh& mesh, IShader& shader)
		{
			RCEngine::RenderCore::MeshFilter* filter = new RCEngine::RenderCore::MeshFilter(&mesh);
			RCEngine::RenderCore::IMaterial* material = new OpenGLMaterial(&shader);
			return new RCEngine::RenderCore::OpenGLMeshRenderer(filter,material);
		}
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateLineRendererComp(Line& line, IShader& shader)
		{
			RCEngine::RenderCore::IMaterial* material = new OpenGLMaterial(&shader);
			return new RCEngine::RenderCore::OpenGLLineRenderer(&line, material);
		}
	}
}