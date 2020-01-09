#ifndef RCCV_loop_EventLoop_H
#define RCCV_loop_EventLoop_H

#include "message/Visitor.hpp"
#include "message/Message.hpp"
#include "base/Mutex.hpp"
#include <list>
#include <memory>

namespace rccv
{

class EventLoop : public noncopyable, public Visitor
{
protected:
	MutexLock mutex_;
	std::list<std::unique_ptr<Message>> msglist_;
public:
	virtual ~EventLoop(){}
	virtual void run()=0;
	void loop();
	void submit(std::unique_ptr<Message> &msg_ptr);

};

} //namespace rccv
#endif //RCCV_loop_EventLoop_H