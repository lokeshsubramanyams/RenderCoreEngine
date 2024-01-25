#pragma once
#include<string>
#include<iostream>
#include <sstream>
namespace RCEngine
{
	
	namespace Debugger
	{
		using namespace std;

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
			
		};
	}
}