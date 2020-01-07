#ifndef RCCV_VISITOR_B_THREAD_HPP
#define RCCV_VISITOR_B_THREAD_HPP
#include <list>
#include <iostream>
#include "visitor-util.h"

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
#endif //RCCV_VISITOR_B_THREAD_HPP
