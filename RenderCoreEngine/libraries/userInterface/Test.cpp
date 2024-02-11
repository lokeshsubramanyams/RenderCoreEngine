#include "Test.h"
#include "imgui_glfw/imgui_impl_glfw.h"
#include "imgui_glfw/imgui_impl_opengl3.h"
#include "Debug.h"

using namespace RCEngine::Debugger;
TestUI::TestUI(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImGui::StyleColorsDark();
	
	ImGui_ImplGlfw_InitForOpenGL(window, true);

#if PLATFORM_WEBASSEMBLY
	ImGui_ImplOpenGL3_Init("#version 300 es");
	ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
#else
	ImGui_ImplOpenGL3_Init("#version 330 core");
#endif
	

}

void TestUI::StartUI()
{
	// Start the Dear ImGui frame
	Debug::Log("StartUI");
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void TestUI::RenderText(const char* str)
{
	Debug::Log("RenderText");
	ImGui::Begin("Performance");
	ImGui::Text(str);
	ImGui::End();

	ImGui::Render();

}

void TestUI::AfterRender()
{
	Debug::Log("AfterRender");
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void TestUI::ShutDown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
}
