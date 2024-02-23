#include "OpenGLMaterial.h"
#include "Debug.h"
namespace RCEngine
{
	namespace RenderCore
	{
		OpenGLMaterial::OpenGLMaterial(IShader *shader):IMaterial(shader)
		{
			for (int i = 0; i < shader->uniformMeta.size(); i++)
			{
				UniformVariable variable(shader->uniformMeta[i].name, shader->uniformMeta[i].variableType);
				Debugger::Debug::Log(shader->uniformMeta[i].name, "");
				uniforms.insert({ shader->uniformMeta[i].name ,variable });
			}
		}

		void OpenGLMaterial::ApplyDefaultColor()
		{
			shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR, CONST::DEFAULTVALUE::defaultColor);
		}

		void OpenGLMaterial::ApplyColor(Color4 color)
		{
			shader->ApplyProperty(CONST::SHADERUNIFORM::DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR,color );
		}

		void OpenGLMaterial::UseProgram()
		{
			shader->UseProgram();
		}

	}
}