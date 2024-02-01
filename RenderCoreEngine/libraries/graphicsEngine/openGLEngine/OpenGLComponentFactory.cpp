#include "OpenGLComponentFactory.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateMeshRendererComp(Mesh& mesh, IShader& shader)
		{
			return new RCEngine::RenderCore::OpenGLMeshRenderer(mesh, shader);
		}
	}
}