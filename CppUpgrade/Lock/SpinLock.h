#pragma once
#include <atomic>
class SpinLock
{
private:
	std::atomic_flag flag;
public:
	SpinLock() :flag() {}
	void lock()
	{
		while (flag.test_and_set(std::memory_order_acquire));
	}
	void unlock()
	{
		flag.clear(std::memory_order_release);
	}
};

