#pragma once

#include "TimerAPI.h"

#include <functional>
#include <chrono>
#include <future> // async
#include <future>

template struct TIMER_API std::atomic_bool;
template class TIMER_API std::chrono::duration<__int64, std::ratio<1, 1>>;

using namespace std::chrono_literals;

class TIMER_API Timer
{
	using EventCallback = std::function<void()>;
public:

	Timer();
	Timer(const Timer&);
	virtual ~Timer();

	void stop();
	bool isActive() const { return m_isActive; }
	void setInterval(EventCallback callback, std::chrono::seconds interval);
	void setTimeout(EventCallback callback, std::chrono::seconds timeout);

private:
	std::atomic_bool m_isActive;
};

