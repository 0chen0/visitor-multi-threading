#ifndef RCCV_VISITOR_B_THREAD_HPP
#define RCCV_VISITOR_B_THREAD_HPP
#include <list>
#include <iostream>
#include "visitor-util.h"

namespace rccv
{

class B_Thread : public Visitor
{
std::list<Message*> msglist_;
public:
	virtual ~B_Thread(){}
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
	virtual void Visit(Open_Message* msg)
	{
		if (msg->isItOpen())
			std::cout << "B_Thread handling Open_Message: " << "Open" << std::endl;
		else
			std::cout << "B_Thread handling Open_Message: " << "Not Open" << std::endl;
	}

	virtual void Visit(Flag_Message* msg)
	{
		std::cout << "B_Thread handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_VISITOR_B_THREAD_HPP
