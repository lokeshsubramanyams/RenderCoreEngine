#include "ImguiLibraryOpenGL3.h"
#include <iostream>
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
	namespace UI
	{
		ImguiLibraryOpenGL3::ImguiLibraryOpenGL3(unsigned int windowID,const char* shaderVersion)
		{
			
			GLFWwindow* currentContext = glfwGetCurrentContext();

		
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;

			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
			
			

			ImGui::StyleColorsDark();

			ImGui_ImplGlfw_InitForOpenGL(currentContext, true);

			

			ImGui_ImplOpenGL3_Init(shaderVersion);

		}

		void ImguiLibraryOpenGL3::UIRender()
		{

		}
		void ImguiLibraryOpenGL3::UIRender(const char* title, const char* str)
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGui::Begin(title);
			ImGui::Text(str);
			ImGui::End();

			ImGui::Render();

			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

		void ImguiLibraryOpenGL3::ShutDown()
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
		}
	}
}

