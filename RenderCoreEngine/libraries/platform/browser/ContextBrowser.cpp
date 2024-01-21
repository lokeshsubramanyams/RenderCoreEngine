#include "ContextBrowser.h"
#include "Debug.h"
namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::Debugger;

		ContextBrowser::ContextBrowser(Rect _viewport)
			:IContext(_viewport)
		{
			EmscriptenWebGLContextAttributes attrs;
			attrs.alpha = EM_TRUE;
			attrs.depth = EM_TRUE;
			attrs.stencil = EM_FALSE;
			attrs.antialias = EM_TRUE;
			attrs.preserveDrawingBuffer = EM_FALSE;
			attrs.powerPreference = EM_WEBGL_POWER_PREFERENCE_HIGH_PERFORMANCE;
			attrs.enableExtensionsByDefault = EM_TRUE;
			attrs.failIfMajorPerformanceCaveat = EM_FALSE;
			attrs.majorVersion = 2; // Use WebGL 2.0
			attrs.minorVersion = 0;
			emscripten_webgl_init_context_attributes(&attrs);
			canvas = emscripten_webgl_create_context("#canvas", &attrs);
			if (!canvas)
			{
				Debug::LogError("canvas not created!");
			}
		}



		void ContextBrowser::makeContextCurrent()
		{
			EMSCRIPTEN_RESULT res = emscripten_webgl_make_context_current(canvas);
			if (res != EMSCRIPTEN_RESULT_SUCCESS)
			{
				Debug::LogError("emscripten not able to make context current:");
			}
		}

		bool ContextBrowser::IsValidContext()
		{
			return canvas!= 0;
		}

		bool ContextBrowser::shouldClose()
		{
			return false;
		}

		void ContextBrowser::swapBuffers()
		{
			
		}

		void ContextBrowser::DestroyContext()
		{
			emscripten_webgl_destroy_context(canvas);
		}

		ContextBrowser::~ContextBrowser()
		{

		}
	}
}