#ifndef RCCV_base_Mutex_HPP
#define RCCV_base_Mutex_HPP

#include "noncopyable.hpp"
#include <pthread.h>
#include <assert.h>

namespace rccv
{

class MutexLock : noncopyable
{
// friend class MutexLockGuard;
private:
	// pid_t holder_;
	pthread_mutex_t mutex_;

public:
	MutexLock()
	{ 
		pthread_mutex_init(&mutex_, NULL); 
	}

	~MutexLock() 
	{
		pthread_mutex_destroy(&mutex_);
	}

// private:
	void lock()
	{
		pthread_mutex_lock(&mutex_);
	}

	void unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}

};

class MutexLockGuard : noncopyable
{
private:
	MutexLock& mutex_;

public:
	explicit MutexLockGuard(MutexLock& mutex): mutex_(mutex)
	{
		mutex_.lock();
	}

	~MutexLockGuard()
	{
		mutex_.unlock();
	}

};

#define MutexLockGuard(x) static_assert(false, "missing mutex guard var name")
// 该宏防止 MutexLockGuard lock(mutex); 错写成 MutexLockGuard(mutex); 
// 错误在于: 遗漏变量名, 产生一个临时对象又马上销毁了, 结果没能锁住临界区

} //namespace rccv

#endif //RCCV_base_Mutex_HPP