#pragma once
#include "IRenderSurface.h"
#include "Transform.h"
#include "UserInterfaceEngine.h"
namespace RCEngine
{
	namespace RenderCore
	{
		class IInputHandler
		{
		protected:
			Platform::IRenderSurface* surfaceDevice;
			UI::UserInterfaceEngine* ui;
		public:
			IInputHandler(Platform::IRenderSurface* surface, UI::UserInterfaceEngine *UiEngine) {surfaceDevice = surface; ui = UiEngine;	};
			virtual void HandleTransformByInput(Transform* transform) = 0;
		};
	}
}