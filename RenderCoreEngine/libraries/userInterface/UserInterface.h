#pragma once 
#include "Transform.h"
namespace RCEngine
{
	namespace UI
	{
		struct UIElement
		{

		};
		struct UIWindow
		{
			const char* title;
		};

		struct UIText :UIWindow
		{
			const char* text;
		};
		struct UITransformation :UIWindow
		{
			RenderCore::Transform* transform;
		};

		namespace WIDGET_NAMES
		{
			constexpr char INSPECTOR[] = "Inspector";
			constexpr char TRANSFORMATION[] = "Transform";
			constexpr char CAMERA[] = "Camera";
			constexpr char CAMERATYPE[] = "CameraType";
			constexpr char VIEWPORT[] = "ViewPort";
		}
		namespace UIWidget
		{
			inline const char* CameraTypeStrings[] = { "Perspective","Orthographic" };
		}
	}
}
