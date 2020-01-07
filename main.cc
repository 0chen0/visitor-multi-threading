#include "visitor-util.h"
#include "visitor/A_Thread.hpp"
#include "visitor/B_Thread.hpp"

using namespace rccv;
int main()
{
	A_Thread a_loop;
	B_Thread b_loop;

	Log_Message* log1 = new Log_Message(std::string("Hello"));
	Log_Message* log2 = new Log_Message(std::string("World"));
	Flag_Message* flag1 = new Flag_Message(11);
	Flag_Message* flag2 = new Flag_Message(22);
	Open_Message* isopen1 = new Open_Message(true);
	Open_Message* isopen2 = new Open_Message(false);

	a_loop.submit(log1);
	a_loop.submit(flag1);
	a_loop.submit(log2);
	a_loop.submit(flag2);
	a_loop.submit(isopen1);
	a_loop.submit(isopen2);
	a_loop.loop();

	b_loop.submit(log1);
	b_loop.submit(flag1);
	b_loop.submit(log2);
	b_loop.submit(flag2);
	b_loop.submit(isopen1);
	b_loop.submit(isopen2);
	b_loop.loop();

	return 0;
}