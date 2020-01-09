#include "loop/ImageHandle_EventLoop.h"
#include "message/Log_Message.hpp"
#include "message/Flag_Message.hpp"

using namespace rccv;

void ImageHandle_EventLoop::Visit(Log_Message* msg)
{
	std::cout << "ImageHandle_EventLoop ==> handling Log_Message: " << msg->getLog() << std::endl;
	// msg->printSelf();
}
void ImageHandle_EventLoop::Visit(Flag_Message* msg)
{
	std::cout << "ImageHandle_EventLoop ==> handling Flag_Message: " << msg->get_10_times_flag() << std::endl;
}