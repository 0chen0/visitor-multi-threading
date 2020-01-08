#include "visitor/Visitor.h"
#include "message/Message.hpp"

using namespace rccv;

void Visitor::loop()
{
	// for(auto it=msglist_.begin(); it!=msglist_.end(); ++it)
	// {
	// 	(*it)->Accept(this);
	// }
	while (!msglist_.empty())
	{
		// 每条消息处理完即时释放
		Message* it = msglist_.front().get();
		it->Accept(this);
		msglist_.pop_front();
	}
}

void Visitor::submit(std::unique_ptr<Message> &msg_ptr)
{
	msglist_.push_back(std::move(msg_ptr));
}