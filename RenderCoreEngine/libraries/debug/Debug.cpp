#include "Debug.hpp"

void RCEngine::Debug::Debug::Log(string str)
{
#ifdef DEBUG
	cout << str << endl;
#endif
}

void RCEngine::Debug::Debug::LogError(string str)
{
#ifdef DEBUG
	cerr << str << endl;
#endif
}
