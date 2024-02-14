#include "ImguiLibraryOpenGL3.h"
#include <iostream>
#include "Debug.h"
namespace RCEngine
{
	using namespace Debugger;
	namespace UI
	{
		ImguiLibraryOpenGL3::ImguiLibraryOpenGL3(std::any context, const char* shaderVersion)
		{
			GLFWwindow* retrievedWindow = nullptr;
			try 
			{
				GLFWwindow* retrievedWindow = std::any_cast<GLFWwindow*>(context);
				std::cout << "Window pointer retrieved successfully." << retrievedWindow <<std::endl;
			}
			catch (const std::bad_any_cast& e) 
			{
				std::cerr << "Failed to cast: " << e.what() << std::endl;
				return;
			}
		
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;

			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
			
			Debug::Log("step1");

			ImGui::StyleColorsDark();

			ImGui_ImplGlfw_InitForOpenGL(retrievedWindow, true);

			Debug::Log("step2");

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

