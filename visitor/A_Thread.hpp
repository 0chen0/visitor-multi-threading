#ifndef RCCV_VISITOR_A_THREAD_HPP
#define RCCV_VISITOR_A_THREAD_HPP
#include <list>
#include <iostream>
#include "visitor-util.h"

namespace rccv
{

class A_Thread : public Visitor
{
std::list<Message*> msglist_;
public:
	virtual ~A_Thread(){}
	void submit(Message* msg)
	{
		msglist_.push_back(msg);
	}
	void loop()
	{
		for(auto it=msglist_.begin(); it!=msglist_.end(); ++it)
		{
			(*it)->Accept(this);
		}
	}
	virtual void Visit(Log_Message* msg)
	{
		std::cout << "A_Thread handling Log_Message: " << msg->getLog() << std::endl;
		// msg->printSelf();
	}

	virtual void Visit(Flag_Message* msg)
	{
		std::cout << "A_Thread handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_VISITOR_A_THREAD_HPP
