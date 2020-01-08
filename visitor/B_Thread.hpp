#ifndef RCCV_visitor_B_Thread_HPP
#define RCCV_visitor_B_Thread_HPP

#include "visitor/Visitor.h"
#include "message/Open_Message.hpp"
#include "message/Log_Message.hpp"
#include <iostream>

namespace rccv
{

class B_Thread : public Visitor
{
public:
	virtual ~B_Thread(){}

	void Visit(Open_Message* msg) override
	{
		if (msg->isItOpen())
			std::cout << "B_Thread handling Open_Message: " << "Open" << std::endl;
		else
			std::cout << "B_Thread handling Open_Message: " << "Not Open" << std::endl;
	}

	void Visit(Log_Message* msg) override
	{
		std::cout << "B_Thread handling Log_Message: " << msg->getLog() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_visitor_B_Thread_HPP
