#include <iostream>
#include "visitor-util.h"

using namespace rccv;

void Log_Message::Accept(Visitor* v)
{
	v->Visit(this);
}

std::string Log_Message::getLog()
{
	return log_;
}

void Log_Message::printSelf()
{
	std::cout << "@# Log_Message printSelf: " << log_ << std::endl;
}
