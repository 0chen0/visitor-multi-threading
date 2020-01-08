// #include "visitor-util.h"
// #include "visitor/Visitor.h"
// #include "message/Message.hpp"
#include "message/Log_Message.hpp"
#include "message/Flag_Message.hpp"
#include "message/Open_Message.hpp"
#include "visitor/A_Thread.hpp"
#include "visitor/B_Thread.hpp"
// #include "visitor/B_Thread.hpp"


using namespace rccv;
int main()
{
	std::cout << "======================================================" << std::endl;

	A_Thread a_loop;

	std::unique_ptr<Message> a_log1 (new Log_Message(std::string("AA_ Hello")));
	std::unique_ptr<Message> a_log2 (new Log_Message(std::string("World _AA")));
	a_loop.submit(a_log1);
	a_loop.submit(a_log2);
	
	//*
	std::unique_ptr<Message> a_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> a_flag2 (new Flag_Message(22));
	a_loop.submit(a_flag1);
	a_loop.submit(a_flag2);
	//*/

	//*
	std::unique_ptr<Message> a_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> a_isopen2 (new Open_Message(false));
	a_loop.submit(a_isopen1);
	a_loop.submit(a_isopen2);
	//*/

	a_loop.loop();

	std::cout << "-------------------------------------------------" << std::endl;

	//*
	B_Thread b_loop;

	std::unique_ptr<Message> b_log1 (new Log_Message(std::string("BB_ Hello")));
	std::unique_ptr<Message> b_log2 (new Log_Message(std::string("World _BB")));
	b_loop.submit(b_log1);
	b_loop.submit(b_log2);

	std::unique_ptr<Message> b_flag1 (new Flag_Message(11));
	std::unique_ptr<Message> b_flag2 (new Flag_Message(22));
	b_loop.submit(b_flag1);
	b_loop.submit(b_flag2);


	std::unique_ptr<Message> b_isopen1 (new Open_Message(true));
	std::unique_ptr<Message> b_isopen2 (new Open_Message(false));
	b_loop.submit(b_isopen1);
	b_loop.submit(b_isopen2);

	b_loop.loop();
	//*/

	return 0;
}