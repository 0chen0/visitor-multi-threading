#ifndef RCCV_visitor_ImageRead_EventLoop_H
#define RCCV_visitor_ImageRead_EventLoop_H

#include "visitor/Visitor.h"
#include "message/Log_Message.hpp"
#include "message/Open_Message.hpp"

namespace rccv
{

class ImageRead_EventLoop : public Visitor
{
public:
	ImageRead_EventLoop(){}
	~ImageRead_EventLoop(){}

	void run();

};

} // namespace rccv

#endif //RCCV_visitor_ImageRead_EventLoop_H