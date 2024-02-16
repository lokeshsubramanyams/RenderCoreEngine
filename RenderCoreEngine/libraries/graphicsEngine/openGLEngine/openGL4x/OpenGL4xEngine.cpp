#include "OpenGL4xEngine.h"
#include "OpenGL4xShadersMeta.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void OpenGL4xEngine::InitilizeEngine(Rect viewport)
		{
			IOpenGLEngine::InitilizeEngine(viewport);
		}

		void OpenGL4xEngine::RenderLoop()
		{
			

			Rect full = EngineSetting::GetWindowSurfaceRect();

			glScissor(full.x, full.y, full.width, full.height);

			glEnable(GL_SCISSOR_TEST);

			glViewport(full.x, full.y, full.width, full.height);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			glClear(GL_COLOR_BUFFER_BIT);

			{
				Rect viewport = camera->viewport->GetViewport();

				glScissor(viewport.x, viewport.y, viewport.width, viewport.height);

				glEnable(GL_SCISSOR_TEST);

				glViewport(viewport.x, viewport.y, viewport.width, viewport.height);

				Vector4 color = camera->setting.backgroundColor;

				glClearColor(color.r, color.g, color.b, color.a);

				glClear(GL_COLOR_BUFFER_BIT);

				for (int i = 0; i < renderers.size(); i++)
				{
					renderers[i]->Render(GetProjectionViewMatrix());
				}
				
			}
			glDisable(GL_SCISSOR_TEST);
		}

		std::unordered_map<std::string, ShaderMetaData> OpenGL4xEngine::GetShaderMetaData()
		{
			std::unordered_map<std::string, ShaderMetaData> data;
			data.insert({ defaultVertShader.shaderKey,defaultVertShader });
			data.insert({ defaultFragShader.shaderKey,defaultFragShader });
			return data;
		}
	}
}
