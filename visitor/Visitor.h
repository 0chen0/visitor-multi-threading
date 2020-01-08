#ifndef RCCV_visitor_Visitor_H
#define RCCV_visitor_Visitor_H
#include <list>
#include <memory>

namespace rccv
{

class Message;
class Log_Message;
class Flag_Message;
class Open_Message;

class Visitor
{
protected:
	std::list<std::unique_ptr<Message>> msglist_;
public:
	virtual ~Visitor(){}
	void loop();
	void submit(std::unique_ptr<Message> &msg_ptr);

	virtual void Visit(Message* msg){}
	virtual void Visit(Log_Message* msg){}
	virtual void Visit(Flag_Message* msg){}
	virtual void Visit(Open_Message* msg){}

};

} //namespace rccv
#endif //RCCV_visitor_Visitor_H