#include "OpenGLMaterial.h"

namespace RCEngine
{
	namespace RenderCore
	{
		OpenGLMaterial::OpenGLMaterial(IShader *shader):IMaterial(shader)
		{
		}
		void OpenGLMaterial::ApplyDefaultColor()
		{
			shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR, CONST::DEFAULTVALUE::defaultColor);
		}
		void OpenGLMaterial::ApplyColor(Color color)
		{
			shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR,color );
		}
	}
}