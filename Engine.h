#ifndef RCCV_Engine_H
#define RCCV_Engine_H

#include "loop/ImageHandle_EventLoop.h"
#include "loop/WriteLog_EventLoop.h"
#include "loop/ImageRead_EventLoop.h"

namespace rccv
{

class Engine : noncopyable
{
private:
	ImageHandle_EventLoop loop_imagehandle_;
	WriteLog_EventLoop loop_writelog_;
	ImageRead_EventLoop loop_imageread_;

public:
	Engine();
	~Engine();
	void init();
	void run();

	ImageHandle_EventLoop* 	getEventLoop_ImageHandle()	{ return &loop_imagehandle_; }
	WriteLog_EventLoop* 	getEventLoop_WriteLog()		{ return &loop_writelog_; }
	ImageRead_EventLoop* 	getEventLoop_ImageRead()	{ return &loop_imageread_; }
};

extern Engine* global_Engine;
inline Engine* getEngine()
{
	return global_Engine;
}


} // namespace rccv


#endif //RCCV_Engine_H