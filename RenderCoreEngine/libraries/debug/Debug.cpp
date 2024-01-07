#include "Debug.hpp"

void RCEngine::Debugger::Debug::Log(string str)
{
#ifdef DEBUG
	cout << str << endl;
#endif
}

void RCEngine::Debugger::Debug::LogError(string str)
{
#ifdef DEBUG
	cerr << str << endl;
#endif
}
