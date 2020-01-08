#ifndef RCCV_message_Open_Message_HPP
#define RCCV_message_Open_Message_HPP

#include "message/Message.hpp"
#include <iostream>

namespace rccv
{

class Open_Message : public Message
{
bool isOpen_;
public:
	Open_Message(bool isOpen):isOpen_(isOpen){}
	virtual ~Open_Message(){std::cout << "~Open_Message: " << isOpen_ << std::endl;}
	virtual void Accept(Visitor* v) override
	{
		v->Visit(this);
	}
	bool isItOpen()
	{
		return isOpen_;
	}
};

} // namespace rccv


#endif //RCCV_message_Open_Message_HPP