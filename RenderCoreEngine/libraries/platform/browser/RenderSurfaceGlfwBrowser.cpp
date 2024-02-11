#include "RenderSurfaceGlfwBrowser.h"
#include "rcEmscripten/RcEmscripten.h"


namespace RCEngine
{
	namespace Platform
	{
		using namespace RCEngine::Debugger;
		using namespace RCEngine::Platform::Browser;

		RenderSurfaceGlfwBrowser::RenderSurfaceGlfwBrowser(Rect screenRect)
			:IRenderSurface(screenRect)
		{
			glfwCanvas = CreateGlfwWindow("RCEngine", screenRect.width, screenRect.height);

			glfwGetFramebufferSize(glfwCanvas, &screenRect.width, &screenRect.height);


			MakeContextCurrent();

			UI = new TestUI(glfwCanvas);

		}

		void RenderSurfaceGlfwBrowser::MakeContextCurrent()
		{
			glfwMakeContextCurrent(glfwCanvas);
		}

		bool RenderSurfaceGlfwBrowser::IsValid() const
		{
			return glfwCanvas != nullptr;
		}


		bool RenderSurfaceGlfwBrowser::ShouldClose()
		{
			return shouldClose;
		}

		void RenderSurfaceGlfwBrowser::SwapBuffers()
		{
			glfwSwapBuffers(glfwCanvas);
		}

		void RenderSurfaceGlfwBrowser::DestroySurface()
		{
			if (glfwCanvas)
			{
				glfwDestroyWindow(glfwCanvas);
				
			}
			if (UI)
			{
				UI->ShutDown();
			}
		}

		RenderSurfaceGlfwBrowser::~RenderSurfaceGlfwBrowser()
		{
			DestroySurface();
		}

		void RenderSurfaceGlfwBrowser::Run(std::function<void()>renderFunction, std::function<void()>updateFunction)
		{
			RcEmscriptenRenderFunctionPtr = renderFunction;
			RcEmscriptenUpdateFunctionPtr = updateFunction;
			RcEmscriptenPollEventFunctionPtr = std::bind(&RenderSurfaceGlfwBrowser::PollEvents, this);
			RcEmscriptenUIFunctionPtr = std::bind(&RenderSurfaceGlfwBrowser::UIRender, this);
			Debug::Log("Run loop set");
			emscripten_set_main_loop(RcEmscriptenRenderFunction, 0, 1);
		}

		void RenderSurfaceGlfwBrowser::PollEvents()
		{
			glfwPollEvents();
			UI->StartUI();
			UI->RenderText("Testdearimgui");
		}

		void RenderSurfaceGlfwBrowser::UIRender()
		{
			UI->AfterRender();
		}


		
	}
}