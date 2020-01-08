#ifndef RCCV_visitor_ImageRead_EventLoop_H
#define RCCV_visitor_ImageRead_EventLoop_H

#include "visitor/Visitor.h"

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