#ifndef RCCV_message_Message_H
#define RCCV_message_Message_H

#include <iostream>

namespace rccv
{

class Visitor;

class Message
{
public:
	virtual ~Message()
	{
		std::cout << "~Message did" << std::endl << std::endl;
	}
	virtual void Accept(Visitor* v)=0;
};


} // namespace rccv
#endif //RCCV_message_Message_H
