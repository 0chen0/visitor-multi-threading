#include "visitor-util.h"

using namespace rccv;

void Flag_Message::Accept(Visitor* v)
{
	v->Visit(this);
}

int Flag_Message::get_10_times_flag()
{
	return flag_ * 10;
}
