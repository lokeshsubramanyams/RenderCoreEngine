#include "FrameRateTracker.h"

namespace RCEngine
{

	FrameRateTracker::FrameRateTracker()
	{

	}
	void FrameRateTracker::CalculateFPS()
	{
		frameCount++;
		currentTime = high_resolution_clock::now();
		frameDelta = duration_cast<duration<double>>(currentTime - lastTime);

		if (frameDelta.count() >= 1.0) {
			fps = frameCount / frameDelta.count();
			frameCount = 0;
			lastTime = currentTime;
			//std::cout << "FPS: " << fps << std::endl;
		}
	}

	double FrameRateTracker::Fps()
	{
		return fps;
	}
	double FrameRateTracker::DeltaTime()
	{
		return frameDelta.count();
	}
}