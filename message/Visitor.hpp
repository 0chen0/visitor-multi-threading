#ifndef RCCV_message_Visitor_HPP
#define RCCV_message_Visitor_HPP

namespace rccv
{

class Log_Message;
class Flag_Message;
class Open_Message;

class Visitor
{
public:

	virtual void Visit(Log_Message* msg){}
	virtual void Visit(Flag_Message* msg){}
	virtual void Visit(Open_Message* msg){}

};

} //namespace rccv
#endif //RCCV_message_Visitor_HPP