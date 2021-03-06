#include "loop/EventLoop.h"

using namespace rccv;

void EventLoop::processMsg()
{
	std::list<std::unique_ptr<Message>> msglist;
	{
		MutexLockGuard lock(mutex_);
		msglist.splice(msglist.end(), msglist_, msglist_.begin(), msglist_.end());
	}
	while (!msglist.empty())
	{
		// 每条消息处理完即时释放
		Message* it = msglist.front().get();
		it->Accept(this);
		msglist.pop_front();
	}
}

void EventLoop::submit(std::unique_ptr<Message> &msg_ptr)
{
	{
		MutexLockGuard lock(mutex_);
		msglist_.push_back(std::move(msg_ptr));
	}
}