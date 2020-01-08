#ifndef RCCV_visitor_ImageHandle_EventLoop_H
#define RCCV_visitor_ImageHandle_EventLoop_H

#include "visitor/Visitor.h"
#include "message/Log_Message.hpp"
#include "message/Flag_Message.hpp"
#include <iostream>


namespace rccv
{

class ImageHandle_EventLoop : public Visitor
{
public:
	ImageHandle_EventLoop(){}
	virtual ~ImageHandle_EventLoop(){}

	void Visit(Log_Message* msg)
	{
		std::cout << "ImageHandle_EventLoop ==> handling Log_Message: " << msg->getLog() << std::endl;
		// msg->printSelf();
	}

	void Visit(Flag_Message* msg)
	{
		std::cout << "ImageHandle_EventLoop ==> handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
	}

};


} // namespace rccv
#endif //RCCV_visitor_ImageHandle_EventLoop_H
