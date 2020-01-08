// #include "visitor/ImageHandle_EventLoop.h"
// #include "visitor/WriteLog_EventLoop.h"

// #include "message/Log_Message.hpp"
// #include "message/Flag_Message.hpp"
// #include "message/Open_Message.hpp"

// #include <thread>
// #include <unistd.h>	//sleep

#include "Engine.h"
using namespace rccv;

// A_Thread* g_pThread_A = NULL;
// B_Thread* g_pThread_B = NULL;

/*
void appendMessage()
{

}
//*/

int main()
{

	std::cout << "======================================================" << std::endl;
	Engine engine;
	engine.run();
	return 0;
}
