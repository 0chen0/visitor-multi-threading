#ifndef RCCV_VISITOR_A_THREAD_HPP
#define RCCV_VISITOR_A_THREAD_HPP
#include <list>
#include <iostream>
#include <memory>
#include "visitor-util.h"

namespace rccv
{

class A_Thread : public Visitor
{
public:
	virtual ~A_Thread(){}
	void loop()
	{
		while (!msglist_.empty())
		{
			// 每条消息处理完即时释放
			Message* it = msglist_.front().get();
			it->Accept(this);
			msglist_.pop_front();
		}
		
	}
	void Visit(Log_Message* msg) override
	{
		std::cout << "A_Thread handling Log_Message: " << msg->getLog() << std::endl;
		// msg->printSelf();
	}

	void Visit(Flag_Message* msg) override
	{
		std::cout << "A_Thread handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};

} // namespace rccv
#endif //RCCV_VISITOR_A_THREAD_HPP
