#include "Engine.h"
#include <thread>

namespace rccv
{

Engine* global_Engine = NULL;
Engine* getEngine()
{
	return global_Engine;
}

Engine::Engine()
{
	global_Engine = this;
}

void Engine::run()
{

	std::unique_ptr<Message> a_log1 (new Log_Message(std::string("AA_ Hello")));
	std::unique_ptr<Message> a_log2 (new Log_Message(std::string("World _AA")));
	getEventLoop_ImageHandle()->submit(a_log1);
	getEventLoop_ImageHandle()->submit(a_log2);
	
	//*
	std::unique_ptr<Message> a_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> a_flag2 (new Flag_Message(22));
	getEventLoop_ImageHandle()->submit(a_flag1);
	getEventLoop_ImageHandle()->submit(a_flag2);
	//*/

	//*
	std::unique_ptr<Message> a_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> a_isopen2 (new Open_Message(false));
	getEventLoop_ImageHandle()->submit(a_isopen1);
	getEventLoop_ImageHandle()->submit(a_isopen2);
	//*/

	std::cout << "-------------------------------------------------" << std::endl;

	std::unique_ptr<Message> b_log1 (new Log_Message(std::string("BB_ Hello")));
	std::unique_ptr<Message> b_log2 (new Log_Message(std::string("World _BB")));
	getEventLoop_WriteLog()->submit(b_log1);
	getEventLoop_WriteLog()->submit(b_log2);

	std::unique_ptr<Message> b_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> b_flag2 (new Flag_Message(22));
	getEventLoop_WriteLog()->submit(b_flag1);
	getEventLoop_WriteLog()->submit(b_flag2);


	std::unique_ptr<Message> b_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> b_isopen2 (new Open_Message(false));
	getEventLoop_WriteLog()->submit(b_isopen1);
	getEventLoop_WriteLog()->submit(b_isopen2);

	std::thread a_thread(&ImageHandle_EventLoop::run, getEventLoop_ImageHandle());
	std::thread b_thread(&WriteLog_EventLoop::run, getEventLoop_WriteLog());
	std::thread c_thread(&ImageRead_EventLoop::run, getEventLoop_ImageRead());


	a_thread.join();
	b_thread.join();
	c_thread.join();
	// std::thread c_thread(appendMessage, std::ref(a_loop), std::ref(b_loop));

}

} // namespace rccv
