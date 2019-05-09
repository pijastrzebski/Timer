#include "Timer.h"

#include <thread>

Timer::Timer() :
	m_isActive(true)
{
}

Timer::Timer(const Timer&)
{
}

Timer::~Timer()
{
	stop();
}

void Timer::stop()
{
	m_isActive = false;
}

void Timer::setInterval(EventCallback callback, std::chrono::seconds interval)
{
	std::thread intervalThread([=]() {
		while (m_isActive)
		{
			std::this_thread::sleep_for(interval);
			callback();
		}
		});
	intervalThread.detach();
}

void Timer::setTimeout(EventCallback callback, std::chrono::seconds timeout)
{
	std::this_thread::sleep_for(timeout);
	callback();
}