#pragma once
#include<emscripten.h>
#include<emscripten/bind.h>
#include<emscripten/console.h>
#include<emscripten/fetch.h>

#include <iostream>
#include <stdexcept>

namespace RCEngine
{
	namespace Platform
	{
		namespace Browser
		{
			extern "C"
			{
				std::function<void()> RcEmscriptenPollEventFunctionPtr;
				std::function<void()> RcEmscriptenRenderFunctionPtr;
				std::function<void()> RcEmscriptenUpdateFunctionPtr;
				std::function<void()> RcEmscriptenUIFunctionPtr;
				
				bool shouldClose = false;

			
				void InitializeRcEmscripten()
				{
					//emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW,nullptr, 1, key_callback);
				}
				void RcEmscriptenRenderFunction() 
				{
					  if(RcEmscriptenPollEventFunctionPtr)
						{
							RcEmscriptenPollEventFunctionPtr();
						}
				
						if (RcEmscriptenUpdateFunctionPtr)
						{
							RcEmscriptenUpdateFunctionPtr();
						}

						if (shouldClose)
						{
							emscripten_cancel_main_loop();
						}

						if (RcEmscriptenRenderFunctionPtr)
						{
							RcEmscriptenRenderFunctionPtr();
						}
						if (RcEmscriptenUIFunctionPtr)
						{
							RcEmscriptenUIFunctionPtr();
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