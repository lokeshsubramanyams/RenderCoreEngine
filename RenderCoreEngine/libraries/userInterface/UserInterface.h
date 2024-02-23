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
			constexpr char HIERARCHY[] = "Hierarchy";
			constexpr char TRANSFORMATION[] = "Transform";
			constexpr char CAMERA[] = "Camera";
			constexpr char CAMERATYPE[] = "CameraType";
			constexpr char VIEWPORT[] = "ViewPort";
			constexpr char MESHRENDERER[] = "Mesh Renderer";
			constexpr char MATERIAL[] = "Material";
			constexpr char PERFORMANCE_STATS[] = "PerformanceStats";

			constexpr char DIRECTIONAL_LIGHT[] = "Directional Light";
		}

		inline Rect WidgetRect(const char* widget)
		{
			int top_gap = 100;
			Rect basic = { 0,0,1920,1080};
			Rect surface = EngineSetting::GetWindowSurfaceRect();

			if (widget == WIDGET_NAMES::INSPECTOR)
			{
				int width = static_cast<int>(std::round(surface.width * 0.2f));
				int height = static_cast<int>(std::round(surface.height * 0.45f));
				return { surface.width - width,100,width,height };
			}
			else if (widget == WIDGET_NAMES::HIERARCHY)
			{
				int width = static_cast<int>(std::round(surface.width * 0.2f));
				int height = static_cast<int>(std::round(surface.height * 0.45f));
				return { 0,100,width,height };
			}
			else if (widget == WIDGET_NAMES::PERFORMANCE_STATS)
			{
				int width = static_cast<int>(std::round(surface.width * 0.1f));
				int height = static_cast<int>(std::round(surface.height * 0.1f));
				return { surface.width - width,surface.height - height,width,height };
			}

			
			return { 0,0,100,100 };
		}

		namespace UIWidget
		{
			inline const char* CameraTypeStrings[] = { "Perspective","Orthographic" };
		}
	}
}
