#ifndef RCCV_visitor_util_H
#define RCCV_visitor_util_H
#include <string>
#include <iostream>

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
public:
	virtual ~Visitor(){}
	virtual void Visit(Log_Message* msg){}
	virtual void Visit(Flag_Message* msg){}
	virtual void Visit(Open_Message* msg){}
};

} // namespace rccv
#endif //RCCV_visitor_util_H
