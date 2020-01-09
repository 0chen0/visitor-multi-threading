#ifndef RCCV_loop_EventLoop_H
#define RCCV_loop_EventLoop_H

#include "message/Visitor.h"
#include "message/Message.h"
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
	void processMsg();
public:
	virtual ~EventLoop(){}
	virtual void loop()=0;
	void submit(std::unique_ptr<Message> &msg_ptr);

};

} //namespace rccv
#endif //RCCV_loop_EventLoop_H