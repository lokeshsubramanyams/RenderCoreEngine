#pragma once
#include<emscripten.h>
#include<emscripten/bind.h>
#include<emscripten/console.h>
#include<emscripten/fetch.h>


namespace RCEngine
{
	namespace Platform
	{
		namespace Browser
		{
			extern "C"
			{
				std::function<void()> RcEmscriptenRenderFunctionPtr1;
				std::function<void()> RcEmscriptenRenderFunctionPtr2;
				
				bool shouldClose = false;

			
				void InitializeRcEmscripten()
				{
					//emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr, 1, key_callback);
				}
				void RcEmscriptenRenderFunction() 
				{
					if (RcEmscriptenRenderFunctionPtr1)
					{
						RcEmscriptenRenderFunctionPtr1();
					}
					if (RcEmscriptenRenderFunctionPtr2)
					{
						RcEmscriptenRenderFunctionPtr2();
					}
				}

				EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent * e, void* userData) 
				{
					if (eventType == EMSCRIPTEN_EVENT_KEYDOWN) {
						if (strcmp(e->code, "Escape") == 0) {
							shouldClose = true;
						}
					}
					return 0;
				}
				
			}
		}
	}
}