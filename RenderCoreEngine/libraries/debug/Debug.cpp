#include "Debug.h"

void RCEngine::Debugger::Debug::LogError(string str)
{
#ifdef DEBUG
	cerr << str << endl;
#endif
}

template<typename T>
void RCEngine::Debugger::Debug::Log(const T& message) {
#ifdef DEBUG
	std::ostringstream oss;
	oss << message;
	std::cout << oss.str() << std::endl;
#endif
}

template void RCEngine::Debugger::Debug::Log<int>(const int& message);
template void RCEngine::Debugger::Debug::Log<double>(const double& message);
template void RCEngine::Debugger::Debug::Log<std::string>(const std::string& message);

void RCEngine::Debugger::Debug::Log(const char* message) {
#ifdef DEBUG
	std::cout << message << std::endl;
#endif
}

template<typename T>
void RCEngine::Debugger::Debug::Log(const char* msg, const T& message) {
#ifdef DEBUG
	std::ostringstream oss;
	oss << message;
	std::cout << msg <<" --> " << oss.str() << std::endl;
#endif
}

template void RCEngine::Debugger::Debug::Log<int>(const char* msg, const int& message);
template void RCEngine::Debugger::Debug::Log<double>(const char* msg, const double& message);
template void RCEngine::Debugger::Debug::Log<std::string>(const char* msg, const std::string& message);

void RCEngine::Debugger::Debug::Log(const char* msg,const char* message) {
#ifdef DEBUG
	std::cout << msg << message << std::endl;
#endif
}