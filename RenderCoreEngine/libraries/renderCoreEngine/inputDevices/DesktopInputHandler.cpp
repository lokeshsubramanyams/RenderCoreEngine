#include "DesktopInputHandler.h"
#include "DesktopInputHandler.h"
#include "Debug.h"
#include "MathLib.h"
namespace RCEngine
{
  using namespace Debugger;
  using namespace MathLib;

  namespace RenderCore
  {
    DesktopInputHandler::DesktopInputHandler(Platform::IRenderSurface* surface, UI::UserInterfaceEngine* UiEngine) :IInputHandler(surface, UiEngine)
    {
      surface->AddMousePositionListener(std::bind(&DesktopInputHandler::OnMousePositionUpdate, this, std::placeholders::_1, std::placeholders::_2));
      surface->AddMouseClickListener(std::bind(&DesktopInputHandler::OnMouseClickUpdate, this, std::placeholders::_1, std::placeholders::_2,std::placeholders::_3));
			surface->AddMouseScrollListener(std::bind(&DesktopInputHandler::OnMouseScrollUpdate, this, std::placeholders::_1, std::placeholders::_2));
    }
    void DesktopInputHandler::HandleTransformByInput(Transform* transform)
    {
      currentTransformHandlingInput = transform;
    }
    void DesktopInputHandler::OnMouseClickUpdate(int button, int action, int mods)
    {
	    currentMouseEvent = { button,action };
    }
    void DesktopInputHandler::OnMousePositionUpdate(double x, double y)
    {
			if (ui->IsMouseOnUI())return;

		  if (currentMouseEvent.IsLeftDown() && currentTransformHandlingInput)
      {
        
        float xoffset = x - currentMousePosition.x;
        float yoffset = y - currentMousePosition.y;
       

        const float sensitivity = 0.05f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;
       
				Quaternion yawQuat = glm::angleAxis(float(glm::radians(xoffset)), glm::vec3(0.0f, 1.0f, 0.0f));
				Quaternion pitchQuat = glm::angleAxis(float(glm::radians(yoffset)), glm::vec3(1.0f, 0.0f, 0.0f));

				Quaternion cameraOrientation = currentTransformHandlingInput->rotation;
				cameraOrientation = cameraOrientation * yawQuat * pitchQuat;

				cameraOrientation = glm::normalize(cameraOrientation);

				currentTransformHandlingInput->Rotation(cameraOrientation);

				currentMousePosition = { x,y };
      }
      else
      {
        currentMousePosition = Vector2Int(x, y);
				//Debug::Log("x:y:", currentMousePosition);
      }
    }
		void RenderCore::DesktopInputHandler::OnMouseScrollUpdate(double x, double y)
		{
			if (ui->IsMouseOnUI())return;

			if (currentTransformHandlingInput)
			{
				const float sensitivity = 0.5f;
				
				currentTransformHandlingInput->position += currentTransformHandlingInput->forward() * float(y) * sensitivity;
				
			}
		}
  }
}