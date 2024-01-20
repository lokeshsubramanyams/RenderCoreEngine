#pragma once
#include<string>
#include<iostream>
namespace RCEngine
{
	
	namespace Debugger
	{
		using namespace std;

		class Debug
		{
		public:
			static void Log(string str);
			static void LogError(string str);

		};
	}
}