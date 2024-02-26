#include "ImguiLibraryOpenGL3.h"

#include <filesystem>

namespace fs = std::filesystem;

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

		void ImguiLibraryOpenGL3::UI(const char* title, const char* str)
		{
			Rect rect = WidgetRect(WIDGET_NAMES::PERFORMANCE_STATS);
			ImGui::SetNextWindowSize(ImVec2(rect.width, rect.height));
			ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));

			ImGui::Begin(title);
			ImGui::Text(str);
			ImGui::End();
		}

		void ImguiLibraryOpenGL3::UI(RenderCore::GraphicsObject *gObject)
		{
			Rect rect = WidgetRect(WIDGET_NAMES::INSPECTOR);
			ImGui::SetNextWindowSize(ImVec2(rect.width, rect.height));
			ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
			ImGui::Begin(WIDGET_NAMES::INSPECTOR);
			if (gObject)
			{
				ComponentRender(gObject);
			}
			ImGui::End();
		}

    void ImguiLibraryOpenGL3::UI(RenderCore::Scene* scene)
    {
			Rect rect = WidgetRect(WIDGET_NAMES::HIERARCHY);
			ImGui::SetNextWindowSize(ImVec2(rect.width, rect.height));
			ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
			ImGui::Begin(WIDGET_NAMES::HIERARCHY);
			ImGui::Text(scene->name.c_str());

			ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_Framed;
		
			for (int i = 0; i < scene->sceneObjectKeys.size(); i++)
			{
				bool node_open = ImGui::TreeNodeEx(scene->sceneObjectKeys[i].c_str(), node_flags);
				if (ImGui::IsItemClicked())
				{
					scene->sceneHierarchySelectedKey = scene->sceneObjectKeys[i];
				}
				if (node_open)
				{
					ImGui::TreePop();
				}
			}
		
			
			ImGui::End();
    }

		void ImguiLibraryOpenGL3::UI()
		{
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

	
		void ImguiLibraryOpenGL3::ComponentRender(RenderCore::GraphicsObject *graphicsObject)
		{
			ImGui::SetNextWindowSize(ImVec2(1000, 400));

			ImGui::Text(graphicsObject->name.c_str());

			UIRender(graphicsObject->transform);

			for (std::unordered_map<ComponentType, IComponent*>::iterator it = graphicsObject->components.begin(); it != graphicsObject->components.end(); ++it) 
			{
				
				switch (it->first)
				{
				case ComponentType::CameraComp:
				{
					//graphicsObject getcomponent having issue on emscripten build so conversion in place 
					UIRender(static_cast<Camera*>(graphicsObject->components[it->first]));
				}
				break;
				case ComponentType::LightComp:
				{
					UIRender(static_cast<DirectionalLight*>(graphicsObject->components[it->first]));
				}break;
				case ComponentType::MeshRendererComp:
				{
					UIRender(static_cast<IMeshRenderer*>(graphicsObject->components[it->first]));
				}
				break;
			  default:
					//Debug::LogError("Component UI not implemented type:" + std::to_string(it->first));
					break;
				}
			}
		}
		
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::Camera* camera)
		{
			static int currentCameraType = (RCEngine::CameraType)currentCameraType;

			ImGui::Text(WIDGET_NAMES::CAMERA);

			ImGui::ColorEdit4(":Background", (float*)&camera->setting.backgroundColor);

			if (ImGui::Combo(WIDGET_NAMES::CAMERATYPE, &currentCameraType,UIWidget::CameraTypeStrings, IM_ARRAYSIZE(UIWidget::CameraTypeStrings)))
			{
				camera->setting.cameraType = (RCEngine::CameraType)currentCameraType;
			}
			if (camera->setting.cameraType == RCEngine::CameraType::Perspective)
			{
				ImGui::DragFloat(":FieldOfView", &camera->setting.fieldOfView, 1.0f, 0.0f, 360.0f, "%.3f");
			}
			else if (camera->setting.cameraType == RCEngine::CameraType::Orthographic)
			{
				ImGui::InputFloat(":orthographicScaleFactor", &camera->orthographicScaleFactor);
			}
			
			ImGui::InputFloat(":NearPlane", &camera->setting.nearZ);

			ImGui::InputFloat(":FarPlane", &camera->setting.farZ);

			MathLib::Rectf viewport = camera->viewport->GetViewportRectf();
			int change = 0;
			
			change+= ImGui::InputFloat(":x", &viewport.x)?1:0;
			change+= ImGui::InputFloat(":y", &viewport.y)?1:0;
			change+= ImGui::InputFloat(":width", &viewport.width)?1:0;
			change+= ImGui::InputFloat(":height", &viewport.height)?1:0;

			if (change > 0)
				camera->viewport->SetViewPortRectf(viewport);
		
		}
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::DirectionalLight* directionLight)
		{
			ImGui::Text(WIDGET_NAMES::DIRECTIONAL_LIGHT);
			ImGui::ColorEdit3(":LightColor", (float*)&directionLight->lightColor);
			ImGui::DragFloat(":LightIntensity", &directionLight->lightIntensity, 1.0f, 0.0f, 100.0f, "%.3f");
		}
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::IMeshRenderer* meshRenderer)
		{
			ImGui::Text(WIDGET_NAMES::MESHRENDERER);
			ImGui::Text(WIDGET_NAMES::MATERIAL);

			for (std::unordered_map<std::string, UniformVariable>::iterator it = meshRenderer->GetMaterial()->uniforms.begin(); it != meshRenderer->GetMaterial()->uniforms.end(); ++it)
			{
				if (!it->second.materialCanEdit)continue;

					switch (it->second.vType)
					{
						case RCEngine::float1:	
						{
							float tempFloat = it->second.GetFloat();
							if (ImGui::DragFloat(it->first.c_str(), &tempFloat))
							{
								meshRenderer->GetMaterial()->Apply(it->first, tempFloat);
							}
							break;
						}
						case RCEngine::int1:		
						{
							int tempInt = it->second.GetInt();
							if (ImGui::DragInt(it->first.c_str(), &tempInt))
							{
								meshRenderer->GetMaterial()->Apply(it->first, tempInt);
							}
							break;
						}
						case RCEngine::vector2:
						{
							Vector2 tempV2 = it->second.GetVec2();
							if (ImGui::DragFloat2(it->first.c_str(), &tempV2[0]))
							{
								meshRenderer->GetMaterial()->Apply(it->first, tempV2);
							}
							break;
						}
						case RCEngine::vector3: 
						{
							Vector3 tempV3 = it->second.GetVec3();
							if (ImGui::DragFloat3(it->first.c_str(), &tempV3[0]))
							{
								meshRenderer->GetMaterial()->Apply(it->first, tempV3);
							}break;
						}
						case RCEngine::vector4: 
						{
							Vector4 tempV4 = it->second.GetVec4();
							if (ImGui::DragFloat4(it->first.c_str(), &tempV4[0]))
							{
								meshRenderer->GetMaterial()->Apply(it->first, tempV4);
							}break;
						}
						case RCEngine::color3:	 
						{
							auto& color = std::get<Color3>(it->second.variable);
							if (ImGui::ColorEdit4(it->first.c_str(), reinterpret_cast<float*>(&color)))
							{
								meshRenderer->GetMaterial()->Apply(it->first, color);
							}break;
						}
						case RCEngine::color4:	
						{
							auto& color = std::get<Color4>(it->second.variable);
							if (ImGui::ColorEdit4(it->first.c_str(), reinterpret_cast<float*>(&color)))
							{
								meshRenderer->GetMaterial()->Apply(it->first,color);
							}break;
						 
						}
					}

			}
			

		}
		void ImguiLibraryOpenGL3::UIRender(RCEngine::RenderCore::Transform* transform)
		{
			ImGui::Text(WIDGET_NAMES::TRANSFORMATION);
			ImGui::DragFloat3(":Position", &transform->position[0]);
			if (ImGui::DragFloat3(":Rotation", &transform->eularAnglesInDegrees[0]))
			{
				transform->ApplyEularAnglesInDegree();
			}
			
			ImGui::DragFloat3(":Scale", &transform->scale[0]);
		}

		void ImguiLibraryOpenGL3::ShutDown()
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
		}

		void ImguiLibraryOpenGL3::Begin()
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
		}

		void ImguiLibraryOpenGL3::End()
		{
			UI();
		}
    bool ImguiLibraryOpenGL3::IsMouseOnUI()
    {
			return ImGui::IsAnyItemActive() || ImGui::IsAnyItemFocused();
    }
    void ImguiLibraryOpenGL3::UIMenuBar(RenderCore::Scene* scene)
    {
			if (ImGui::BeginMainMenuBar())
			{
				if (ImGui::BeginMenu("File")) 
				{
					if (ImGui::MenuItem("Open", "Ctrl+O")) 
					{
						// Open file logic
					}
					if (ImGui::MenuItem("Save", "Ctrl+S")) 
					{
						// Save file logic
					}
					if (ImGui::MenuItem("Save As...")) 
					{
						// Save As logic
					}

					ImGui::EndMenu();
				}

				if (ImGui::BeginMenu("Create"))
				{
					if (ImGui::MenuItem("Primitive->Cube"))
					{
						scene->AddShape("Cube100", GeometryShapes::Cube);
						//scene->GetGraphicsObject("Cube100")->transform->position = Vector3(0, 0, 0);
					}
					if (ImGui::MenuItem("Primitive->Sphere"))
					{
						scene->AddShape("Sphere100", GeometryShapes::Sphere);
						//scene->GetGraphicsObject("Sphere100")->transform->position = Vector3(0, 0, 0);
					}

					ImGui::EndMenu();
				}

				ImGui::EndMainMenuBar();
			}

	
    }
	}
}

