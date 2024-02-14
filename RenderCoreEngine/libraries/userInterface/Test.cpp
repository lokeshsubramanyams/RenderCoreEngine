#include "Test.h"

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
	

}

void TestUI::RenderText(const char* str)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Performance");
	ImGui::Text(str);
	ImGui::End();

	ImGui::Render();
	
}

void TestUI::AfterRender()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void TestUI::ShutDown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
}
