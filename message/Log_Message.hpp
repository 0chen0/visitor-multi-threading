#ifndef RCCV_message_Log_Message_HPP
#define RCCV_message_Log_Message_HPP

#include "message/Message.h"
#include "message/Visitor.h"
#include <iostream>

namespace rccv
{

class Log_Message : public Message
{
std::string log_;
public:
	Log_Message(std::string log):log_(log){}
	virtual ~Log_Message(){std::cout << "~Log_Message: " << log_ << std::endl;}
	virtual void Accept(Visitor* v) override
	{
		v->Visit(this);
	}

	std::string getLog()
	{
		return log_;
	}
	void printSelf()
	{
		std::cout << "@# Log_Message printSelf: " << log_ << std::endl;
	}
};

} //namespace rccv
#endif //RCCV_message_Log_Message_HPP