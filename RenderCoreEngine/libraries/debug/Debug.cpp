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
template void RCEngine::Debugger::Debug::Log<float>(const float& message);
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
template void RCEngine::Debugger::Debug::Log<float>(const char* msg, const float& message);
template void RCEngine::Debugger::Debug::Log<std::string>(const char* msg, const std::string& message);

void RCEngine::Debugger::Debug::Log(const char* msg,const char* message) {
#ifdef DEBUG
	std::cout << msg << message << std::endl;
#endif
}

void RCEngine::Debugger::Debug::Log(const char* log, Vector3 vector)
{
#ifdef DEBUG
	string vecStr = string("{" + std::to_string(vector.x) +" , " + std::to_string(vector.y) + " , " + std::to_string(vector.z) + " , " + std::to_string(vector.t) + "}");
	std::cout<<log <<" : " << vecStr << std::endl;
#endif
}
void RCEngine::Debugger::Debug::Log(const char* log, Vector4 vector)
{
#ifdef DEBUG
	string vecStr = string("{" + std::to_string(vector.x) + " , " + std::to_string(vector.y) + " , " + std::to_string(vector.z) + "}");
	std::cout << log << " : " << vecStr << std::endl;
#endif
}

void RCEngine::Debugger::Debug::Log(const char* log, Quaternion quaternion)
{
#ifdef DEBUG
	string vecStr = string("{" + std::to_string(quaternion.x) + " , " + std::to_string(quaternion.y) + " , " + std::to_string(quaternion.z) + " , " + std::to_string(quaternion.w) + "}");
	std::cout << log << " : " << vecStr << std::endl;
#endif
}

void RCEngine::Debugger::Debug::Log(const char* log, Rect rect)
{
#ifdef DEBUG
	string vecStr = string("{" + std::to_string(rect.x) + " , " + std::to_string(rect.y) + " , " + std::to_string(rect.width) + " , " + std::to_string(rect.height) + "}");
	std::cout << log << " : " << vecStr << std::endl;
#endif
}
