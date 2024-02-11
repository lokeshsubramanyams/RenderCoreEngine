#include "Test.h"
#include "imgui_glfw/imgui_impl_glfw.h"
#include "imgui_glfw/imgui_impl_opengl3.h"


TestUI::TestUI(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 150"); // Use GLSL version 130

}

void TestUI::StartUI()
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void TestUI::RenderText(const char* str)
{

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
