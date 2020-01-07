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

	void loop()
	{
		// for(auto it=msglist_.begin(); it!=msglist_.end(); ++it)
		// {
		// 	(*it)->Accept(this);
		// }
		while (!msglist_.empty())
		{
			Message* it = msglist_.front().get();
			it->Accept(this);
			msglist_.pop_front();
		}
	}
	void Visit(Open_Message* msg) override
	{
		if (msg->isItOpen())
			std::cout << "B_Thread handling Open_Message: " << "Open" << std::endl;
		else
			std::cout << "B_Thread handling Open_Message: " << "Not Open" << std::endl;
	}

	void Visit(Flag_Message* msg) override
	{
		std::cout << "B_Thread handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_VISITOR_B_THREAD_HPP
