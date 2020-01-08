#ifndef RCCV_visitor_WriteLog_EventLoop_H
#define RCCV_visitor_WriteLog_EventLoop_H

#include "visitor/Visitor.h"
#include "message/Log_Message.hpp"
#include "message/Open_Message.hpp"

namespace rccv
{

class WriteLog_EventLoop : public Visitor
{
public:
	WriteLog_EventLoop(){}
	~WriteLog_EventLoop(){}

	void Visit(Log_Message* msg)
	{
		std::cout << "Log_EventLoop ==> handling Log_Message: " << msg->getLog() << std::endl;
		// msg->printSelf();
	}
	void Visit(Open_Message* msg) override
	{
		if (msg->isItOpen())
			std::cout << "Log_EventLoop ==> handling Open_Message: " << "Open" << std::endl;
		else
			std::cout << "Log_EventLoop ==> handling Open_Message: " << "Not Open" << std::endl;
	}

};

} // namespace rccv

#endif //RCCV_visitor_WriteLog_EventLoop_H