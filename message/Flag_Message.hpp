/*
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
//*/

#ifndef RCCV_message_Flag_Message_HPP
#define RCCV_message_Flag_Message_HPP

#include "message/Message.hpp"
#include <iostream>

namespace rccv
{

class Flag_Message : public Message
{
int flag_;
public:
	Flag_Message(int flag):flag_(flag){}
	virtual ~Flag_Message(){std::cout << "~Flag_Message did" << std::endl;}
	virtual void Accept(Visitor* v) override
	{
		v->Visit(this);
	}
	int get_10_times_flag()
	{
		return flag_ * 10;
	}
};

} // namespace rccv


#endif //RCCV_message_Flag_Message_HPP