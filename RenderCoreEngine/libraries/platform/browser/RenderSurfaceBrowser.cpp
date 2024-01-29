#include "RenderSurfaceBrowser.h"
#include "rcEmscripten/RcEmscripten.h"


namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::Debugger;
		using namespace RCEngine::Platform::Browser;

		RenderSurfaceBrowser::RenderSurfaceBrowser(Rect screenRect)
			:IRenderSurface(screenRect)
		{
			EmscriptenWebGLContextAttributes attrs;
			emscripten_webgl_init_context_attributes(&attrs);

			attrs.alpha = true;
			attrs.depth = true;
			attrs.stencil = true;
			attrs.antialias = true;
			attrs.majorVersion = 2; // Use WebGL 2.0
			attrs.minorVersion = 0;
			
			canvas = emscripten_webgl_create_context("#canvas", &attrs);
			if (!canvas)
			{
				Debug::LogError("canvas not created!");
			}
			else
			{
				Debug::Log("canvas created successfully");

				EMSCRIPTEN_RESULT result = emscripten_set_canvas_element_size("#canvas", screenRect.width, screenRect.height);
				if (result != EMSCRIPTEN_RESULT_SUCCESS) {
					Debug::LogError("error on setting the canvas size");
				}
				
			}
			MakeContextCurrent();
			
		}

		

		void RenderSurfaceBrowser::MakeContextCurrent()
		{
			EMSCRIPTEN_RESULT res = emscripten_webgl_make_context_current(canvas);
			if (res != EMSCRIPTEN_RESULT_SUCCESS)
			{
				Debug::LogError("emscripten not able to make context current:");
			}
			else
			{
				Debug::Log("emscripten_webgl_make_context_current successfully");
			}
		}

		bool RenderSurfaceBrowser::IsValid() const
		{
			return canvas!= 0;
		}


		bool RenderSurfaceBrowser::ShouldClose()
		{
			return shouldClose;
		}

		void RenderSurfaceBrowser::SwapBuffers()
		{
			
		}

		void RenderSurfaceBrowser::DestroySurface()
		{
			emscripten_webgl_destroy_context(canvas);
		}

		RenderSurfaceBrowser::~RenderSurfaceBrowser()
		{

		}

		void RenderSurfaceBrowser::Run(std::function<void()>renderFunction, std::function<void()>updateFunction)
		{
			RcEmscriptenRenderFunctionPtr = renderFunction;
			RcEmscriptenUpdateFunctionPtr = updateFunction;
			
			Debug::Log("Run loop set");
			emscripten_set_main_loop(RcEmscriptenRenderFunction, 0, 1);
		}
	
	}
}