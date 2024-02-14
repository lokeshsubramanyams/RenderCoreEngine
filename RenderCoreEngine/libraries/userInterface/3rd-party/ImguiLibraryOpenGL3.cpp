#include "ImguiLibraryOpenGL3.h"

namespace RCEngine
{
	using namespace Debugger;
	using namespace RenderCore;
	namespace UI
	{
	

		ImguiLibraryOpenGL3::ImguiLibraryOpenGL3(unsigned int windowID,const char* shaderVersion)
		{

			IMGUI_CHECKVERSION();

			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;

			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
				
			ImGui::StyleColorsDark();

			ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);
			
			ImGui_ImplOpenGL3_Init(shaderVersion);

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

		void ImguiLibraryOpenGL3::UIRender(RenderCore::GraphicsObject *gObject)
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			ImGui::Begin(WIDGET_NAMES::INSPECTOR);

			ComponentRender(gObject);

			ImGui::End();
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

	
		void ImguiLibraryOpenGL3::ComponentRender(RenderCore::GraphicsObject *graphicsObject)
		{
			ImGui::Text(graphicsObject->name.c_str());

			UIRender(graphicsObject->transform);

			for (std::unordered_map<ComponentType, IComponent*>::iterator it = graphicsObject->components.begin(); it != graphicsObject->components.end(); ++it) {
				std::cout << it->first << ": " << it->second << std::endl;

				switch (it->first)
				{
				case ComponentType::CameraComp:
				{
					UIRender(graphicsObject->GetComponent<Camera*>(ComponentType::CameraComp));

				}
				break;
				case ComponentType::MeshRendererComp:
				{
					//IMeshRenderer* meshRenderer = graphicsObject->GetComponent<IMeshRenderer*>(ComponentType::MeshRendererComp);
				}
				//break;
			  default:
					Debug::LogError("Component UI not implemented type:" + std::to_string(it->first));
					break;
				}
			}
		}
		
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::Camera* camera)
		{
			static int currentCameraType = (RCEngine::CameraType)currentCameraType;

			ImGui::Text(WIDGET_NAMES::CAMERA);

			if (ImGui::Combo(WIDGET_NAMES::CAMERATYPE, &currentCameraType,UIWidget::CameraTypeStrings, IM_ARRAYSIZE(UIWidget::CameraTypeStrings)))
			{
				camera->setting.cameraSettings.cameraType = (RCEngine::CameraType)currentCameraType;
			}
			if (camera->setting.cameraSettings.cameraType == RCEngine::CameraType::Perspective)
			{
				ImGui::InputFloat(":FieldOfView", &camera->setting.cameraSettings.fieldOfView);
			}
			else if (camera->setting.cameraSettings.cameraType == RCEngine::CameraType::Orthographic)
			{
				ImGui::InputFloat(":orthographicScaleFactor", &camera->orthographicScaleFactor);
			}
			
			//ImGui::InputInt(":x", &camera->setting.screen.x);
			//ImGui::InputInt(":y", &camera->setting.screen.y);
			//ImGui::InputInt(":width", &camera->setting.screen.width);
			//ImGui::InputInt(":height", &camera->setting.screen.height);
		}
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::Transform* transform)
		{
			ImGui::Text(WIDGET_NAMES::TRANSFORMATION);
			ImGui::InputFloat3(":Position", &transform->position[0], "%.3f");
			ImGui::InputFloat4(":Rotation", &transform->rotation[0], "%.3f");
			ImGui::InputFloat3(":Scale", &transform->scale[0], "%.3f");
		}

		void ImguiLibraryOpenGL3::ShutDown()
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
		}
	}
}

