#ifndef RCCV_Engine_HPP
#define RCCV_Engine_HPP

#include "visitor/ImageHandle_EventLoop.h"
#include "visitor/WriteLog_EventLoop.h"
#include "visitor/ImageRead_EventLoop.h"

namespace rccv
{

class Engine
{
ImageHandle_EventLoop loop_imagehandle_;
WriteLog_EventLoop loop_writelog_;
ImageRead_EventLoop loop_imageread_;

public:
	ImageHandle_EventLoop* getEventLoop_ImageHandle(){ return &loop_imagehandle_; }
	WriteLog_EventLoop* getEventLoop_WriteLog(){ return &loop_writelog_; }
	ImageRead_EventLoop* getEventLoop_ImageRead(){ return &loop_imageread_; }

	Engine();
	~Engine(){}
	void run();
};

extern Engine* getEngine();


} // namespace rccv


#endif //RCCV_Engine_HPP