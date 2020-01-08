#ifndef RCCV_VISITOR_A_THREAD_HPP
#define RCCV_VISITOR_A_THREAD_HPP

#include "visitor/Visitor.h"
#include "message/Log_Message.hpp"
#include "message/Flag_Message.hpp"
#include <iostream>


namespace rccv
{

class A_Thread : public Visitor
{
public:
	virtual ~A_Thread(){}

	void Visit(Log_Message* msg)
	{
		std::cout << "A_Thread handling Log_Message: " << msg->getLog() << std::endl;
		// msg->printSelf();
	}

	void Visit(Flag_Message* msg)
	{
		std::cout << "A_Thread handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_VISITOR_A_THREAD_HPP
