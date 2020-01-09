
# 多线程框架说明

## 加消息体, 如 Test_Message
1. 在"message/Visitor.h"中添加接口
``` cpp
class Test_Message; //此处使用前向声明, 不include消息体头文件
virtual void Visit(Test_Message* msg){}	//消息访问接口, 需要处理此消息的loop重写此接口
```
2. 在message目录下新建Test_Message类, 需要继承**Message**类并重写基类的**Accept**函数
``` cpp
class Test_Message : public Message {
	virtual void Accept(Visitor* v) override
	{
		v->Visit(this);
	}
```
3. 在CMakeLists.txt文件中添加该文件
4. 在处理该消息的loop中重写Visitor中的接口即可
``` cpp
class Test_EventLoop : public EventLoop {
	void Visit(Test_Message* msg) override;
```


## 加线程, 如 Test_EventLoop
1. 在loop目录下新建Test_EventLoop类, 需要继承**EventLoop**类并实现基类的**loop**函数
``` cpp
class Test_EventLoop : public EventLoop {
	void loop() override 	//实现loop函数, 将作为线程的启动函数, 应该写成死循环
	{						//如果不是死循环, 线程执行完操作便会销毁
		while (true)
		{
			processMsg();	//此函数会将线程收到的消息分发到线程对应处理该消息的Visit函数中,
							//要处理消息则重写Visitor类中对应消息的Visit函数(参照上文),
							//如果该线程不处理外部消息则可以不调用.
			/* do something ... */ //该线程的处理逻辑
		}
	}
```
2. 在CMakeLists.txt文件中添加该文件
3. 将Test_EventLoop作为Engine类的私有成员并提供get访问函数
``` cpp
#include "loop/Test_EventLoop.h"
Test_EventLoop loop_test_;
Test_EventLoop* getEventLoop_Test()	{ return &loop_test_; }
```
4. 在**Engine::run**函数中添加线程并执行
``` cpp
std::thread thread_Test(&Test_EventLoop::loop, getEventLoop_Test());
thread_Test.join();
```

## 线程间通信
线程间通信用消息队列方式
``` cpp
std::unique_ptr<Message> msg (new Test_Message())); //unique_ptr智能指针管理内存
/* do something ... */ // 设置消息内容
getEngine()->getEventLoop_Test()->submit(msg); //向Test_EventLoop线程发送Test_Message类型的消息
```