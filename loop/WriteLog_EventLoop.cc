#include "loop/WriteLog_EventLoop.h"
#include "message/Log_Message.hpp"
#include "message/Open_Message.hpp"

using namespace rccv;

void WriteLog_EventLoop::loop()
{
	while (true)
	{
		processMsg();
	}
	
}

void WriteLog_EventLoop::Visit(Log_Message* msg)
{
	std::cout << "Log_EventLoop ==> handling Log_Message: " << msg->getLog() << std::endl;
	// msg->printSelf();
}

void WriteLog_EventLoop::Visit(Open_Message* msg)
{
	if (msg->isItOpen())
		std::cout << "Log_EventLoop ==> handling Open_Message: " << "Open" << std::endl;
	else
		std::cout << "Log_EventLoop ==> handling Open_Message: " << "Not Open" << std::endl;
}