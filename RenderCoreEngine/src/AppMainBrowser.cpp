#include "RenderCore.h"
#include "RenderCoreEngine.h"

#include "Debug.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include<csignal>

using namespace RCEngine;
using namespace RCEngine::Debugger;
using namespace RCEngine::RenderCore;

extern "C"
{
	EMSCRIPTEN_KEEPALIVE
	void igniteEngine(const char* canvas)
	{
		Debug::Log("igniteEngine->", canvas);
		RenderCoreEngine* engine = new RenderCoreEngine();
		engine->InitilizeEngine();
		engine->Run();
	}
	EMSCRIPTEN_KEEPALIVE
		void runEngine()
	{

	}
}