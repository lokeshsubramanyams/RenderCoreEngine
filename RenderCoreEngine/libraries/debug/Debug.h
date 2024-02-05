#pragma once
#include<string>
#include<iostream>
#include <sstream>
#include "MathLib.h"

namespace RCEngine
{
	
	namespace Debugger
	{
		using namespace std;
		using namespace RCEngine::MathLib;
		class Debug
		{
		public:
			template<typename T>
			static void Log(const T& message);
			template<typename T>
			static void Log(const char* logMsg, const T& message);
			static void Log(const char* msg, const char* message);
			static void Log(const char* message);
			static void LogError(string str);
			static void Log(const char* log,Vector3 vector);
			static void Log(const char* log, Rect rect);
			static void Log(const char* log, Quaternion quaternion);
			
		};
	}
}