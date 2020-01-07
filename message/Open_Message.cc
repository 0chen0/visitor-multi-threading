#include "visitor-util.h"

using namespace rccv;

void Open_Message::Accept(Visitor* v)
{
	v->Visit(this);
}

bool Open_Message::isItOpen()
{
	return isOpen_;
}
