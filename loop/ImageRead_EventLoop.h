#ifndef RCCV_loop_ImageRead_EventLoop_H
#define RCCV_loop_ImageRead_EventLoop_H

#include "loop/EventLoop.h"

namespace rccv
{

class ImageRead_EventLoop : public EventLoop
{
public:
	ImageRead_EventLoop(){}
	~ImageRead_EventLoop(){}

	void run();

};

} // namespace rccv

#endif //RCCV_loop_ImageRead_EventLoop_H