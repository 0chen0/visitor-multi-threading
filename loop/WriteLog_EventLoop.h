#ifndef RCCV_loop_WriteLog_EventLoop_H
#define RCCV_loop_WriteLog_EventLoop_H

#include "loop/EventLoop.h"

namespace rccv
{

class WriteLog_EventLoop : public EventLoop
{
public:
	WriteLog_EventLoop(){}
	~WriteLog_EventLoop(){}

	void run()
	{
		loop();
	}

	void Visit(Log_Message* msg) override;
	void Visit(Open_Message* msg) override;

};

} // namespace rccv

#endif //RCCV_loop_WriteLog_EventLoop_H