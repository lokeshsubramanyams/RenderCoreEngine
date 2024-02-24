#pragma once
#include "IInputHandler.h"
namespace RCEngine
{
	namespace RenderCore
	{
		struct MouseButton
		{
			int buttonIndex;//0->left,1->right
			int action;
			bool IsLeftDown() { return buttonIndex == 0 && action == 1; }
		};
		class DesktopInputHandler:public IInputHandler
		{
		public:
			DesktopInputHandler(Platform::IRenderSurface* surface, UI::UserInterfaceEngine* UiEngine);
			void HandleTransformByInput(Transform* transform)override;
		protected:
			void OnMouseClickUpdate(int button, int action, int mods);
			void OnMousePositionUpdate(double x, double y);
			void OnMouseScrollUpdate(double x, double y);

			///mouse controllers
			MouseButton currentMouseEvent;
			Vector2Int currentMousePosition;
		private:
			Transform* currentTransformHandlingInput;
		};
	}
}