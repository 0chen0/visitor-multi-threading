#include "Engine.h"
#include "message/Log_Message.hpp"
#include "message/Flag_Message.hpp"
#include "message/Open_Message.hpp"
#include <thread>

namespace rccv
{

Engine* global_Engine = NULL;

Engine::Engine()
{
	global_Engine = this;
}

Engine::~Engine()
{
	global_Engine = NULL;
}

void Engine::init()
{
	void addTestMsg();
	addTestMsg();
}

void Engine::run()
{
	init();

	std::thread thread_ImageHandle(&ImageHandle_EventLoop::loop, getEventLoop_ImageHandle());
	std::thread thread_WriteLog(&WriteLog_EventLoop::loop, getEventLoop_WriteLog());
	std::thread thread_ImageRead(&ImageRead_EventLoop::loop, getEventLoop_ImageRead());

	thread_ImageHandle.join();
	thread_WriteLog.join();
	thread_ImageRead.join();

}


void addTestMsg()
{
	std::unique_ptr<Message> a_log1 (new Log_Message(std::string("AA_ Hello")));
	std::unique_ptr<Message> a_log2 (new Log_Message(std::string("World _AA")));
	getEngine()->getEventLoop_ImageHandle()->submit(a_log1);
	getEngine()->getEventLoop_ImageHandle()->submit(a_log2);
	
	//*
	std::unique_ptr<Message> a_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> a_flag2 (new Flag_Message(22));
	getEngine()->getEventLoop_ImageHandle()->submit(a_flag1);
	getEngine()->getEventLoop_ImageHandle()->submit(a_flag2);
	//*/

	//*
	std::unique_ptr<Message> a_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> a_isopen2 (new Open_Message(false));
	getEngine()->getEventLoop_ImageHandle()->submit(a_isopen1);
	getEngine()->getEventLoop_ImageHandle()->submit(a_isopen2);
	//*/

	std::cout << "-------------------------------------------------" << std::endl;

	std::unique_ptr<Message> b_log1 (new Log_Message(std::string("BB_ Hello")));
	std::unique_ptr<Message> b_log2 (new Log_Message(std::string("World _BB")));
	getEngine()->getEventLoop_WriteLog()->submit(b_log1);
	getEngine()->getEventLoop_WriteLog()->submit(b_log2);

	std::unique_ptr<Message> b_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> b_flag2 (new Flag_Message(22));
	getEngine()->getEventLoop_WriteLog()->submit(b_flag1);
	getEngine()->getEventLoop_WriteLog()->submit(b_flag2);


	std::unique_ptr<Message> b_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> b_isopen2 (new Open_Message(false));
	getEngine()->getEventLoop_WriteLog()->submit(b_isopen1);
	getEngine()->getEventLoop_WriteLog()->submit(b_isopen2);
}

} // namespace rccv
