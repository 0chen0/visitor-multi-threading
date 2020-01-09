#ifndef RCCV_loop_ImageHandle_EventLoop_H
#define RCCV_loop_ImageHandle_EventLoop_H

#include "loop/EventLoop.h"
#include <iostream>


namespace rccv
{

class ImageHandle_EventLoop : public EventLoop
{
public:
	ImageHandle_EventLoop(){}
	virtual ~ImageHandle_EventLoop(){}

	void loop() override;

	void Visit(Log_Message* msg) override;
	void Visit(Flag_Message* msg) override;

};


} // namespace rccv
#endif //RCCV_loop_ImageHandle_EventLoop_H
