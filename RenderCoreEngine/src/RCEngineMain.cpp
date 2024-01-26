

#include "RCEngineMain.h"
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

std::mutex logMutex;

std::atomic<bool> running(true);

void ThreadFunction()
{
	while (running)
	{
		std::lock_guard<std::mutex> guard(logMutex);
		Debug::Log("threadFunction called!");
	}

}
void signalHandler(int signum) 
{
	Debug::Log("signalHandler:",signum);
	if (signum == SIGINT) 
	{
		running = false;
	}
}


int main()
{
	std::signal(SIGINT, signalHandler);

	std::thread threadObj(ThreadFunction);


	Debug::Log("main");
	RenderCoreEngine* engine = new RenderCoreEngine();
	engine->InitilizeEngine();
	signalHandler(SIGINT);
	threadObj.join();


	return 0;
}
