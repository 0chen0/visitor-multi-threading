#ifndef RCCV_Engine_H
#define RCCV_Engine_H

#include "visitor/ImageHandle_EventLoop.h"
#include "visitor/WriteLog_EventLoop.h"
#include "visitor/ImageRead_EventLoop.h"

namespace rccv
{

class Engine
{
private:
	ImageHandle_EventLoop loop_imagehandle_;
	WriteLog_EventLoop loop_writelog_;
	ImageRead_EventLoop loop_imageread_;

public:
	Engine();
	~Engine(){}
	void run();
	void engineInit();

	ImageHandle_EventLoop* 	getEventLoop_ImageHandle()	{ return &loop_imagehandle_; }
	WriteLog_EventLoop* 	getEventLoop_WriteLog()		{ return &loop_writelog_; }
	ImageRead_EventLoop* 	getEventLoop_ImageRead()	{ return &loop_imageread_; }
};

extern Engine* getEngine();


} // namespace rccv


#endif //RCCV_Engine_H