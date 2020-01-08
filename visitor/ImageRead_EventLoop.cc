#include "ImageRead_EventLoop.h"
#include "message/Log_Message.hpp"
#include "Engine.h"
#include <iostream>
#include <unistd.h>	//sleep

using namespace rccv;

void ImageRead_EventLoop::run()
{
	while(true)
	{
		std::cout << "******** Appending Message... ********" << std::endl;
		//*
		std::unique_ptr<Message> b_append1 (new Log_Message(std::string("BB_ Append")));
		std::unique_ptr<Message> b_append2 (new Log_Message(std::string("Message _BB")));
		getEngine()->getEventLoop_WriteLog()->submit(b_append1);
		getEngine()->getEventLoop_WriteLog()->submit(b_append2);
		//*/	
		//*
		std::unique_ptr<Message> a_append1 (new Log_Message(std::string("AA_ Append")));
		std::unique_ptr<Message> a_append2 (new Log_Message(std::string("Message _AA")));
		getEngine()->getEventLoop_ImageHandle()->submit(a_append1);
		getEngine()->getEventLoop_ImageHandle()->submit(a_append2);
		//*/	
		sleep(3);
	}	
}

