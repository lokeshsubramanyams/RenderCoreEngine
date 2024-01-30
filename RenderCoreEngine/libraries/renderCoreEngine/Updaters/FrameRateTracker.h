#pragma once 
#include <iostream>
#include <chrono>
#include <string>

namespace RCEngine
{
	using namespace std::chrono;
	class FrameRateTracker
	{
	private:
		int frameCount = 0;
		steady_clock::time_point startTime = high_resolution_clock::now();
		steady_clock::time_point currentTime = startTime;
		steady_clock::time_point lastTime = startTime;
		double fps = 0.0;
		double deltaTime = 0.0;
		duration<double> frameDelta;
	public:
		FrameRateTracker();
		void CalculateFPS();
		double Fps();
		double DeltaTime();
	};
}