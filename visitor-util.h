#ifndef RCCV_visitor_util_H
#define RCCV_visitor_util_H
#include <string>
#include <iostream>
#include <list>
#include <memory>

namespace rccv
{

class Visitor;

class Message
{
public:
	virtual ~Message()
	{
		std::cout << "~Message did" << std::endl;
	}
	virtual void Accept(Visitor* v)=0;
};

class Log_Message : public Message
{
std::string log_;
public:
	Log_Message(std::string log):log_(log){}
	virtual ~Log_Message(){std::cout << "~Log_Message did" << std::endl;}
	virtual void Accept(Visitor* v) override;

	std::string getLog();
	void printSelf();
};

class Flag_Message : public Message
{
int flag_;
public:
	Flag_Message(int flag):flag_(flag){}
	virtual ~Flag_Message(){std::cout << "~Flag_Message did" << std::endl;}
	virtual void Accept(Visitor* v) override;
	int get_10_times_flag();
};

class Open_Message : public Message
{
bool isOpen_;
public:
	Open_Message(bool isOpen):isOpen_(isOpen){}
	virtual ~Open_Message(){std::cout << "~Open_Message did" << std::endl;}
	virtual void Accept(Visitor* v) override;
	bool isItOpen();
};

class Visitor
{
protected:
	std::list<std::unique_ptr<Message>> msglist_;
public:
	void loop()
	{
		// for(auto it=msglist_.begin(); it!=msglist_.end(); ++it)
		// {
		// 	(*it)->Accept(this);
		// }
		while (!msglist_.empty())
		{
			// 每条消息处理完即时释放
			Message* it = msglist_.front().get();
			it->Accept(this);
			msglist_.pop_front();
		}
	}
	void submit(std::unique_ptr<Message> &msg_ptr)
	{
		msglist_.push_back(std::move(msg_ptr));
	}
	virtual ~Visitor(){}
	virtual void Visit(Log_Message* msg){}
	virtual void Visit(Flag_Message* msg){}
	virtual void Visit(Open_Message* msg){}
};

} // namespace rccv
#endif //RCCV_visitor_util_H
