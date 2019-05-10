#include "pch.h"

#include "TimerTestFixture.h"

TEST(IsActiveTest, isActive_SHOULD_ReturnTrue_WHEN_TheTimerIsActive)
{
	Timer testTimer = Timer();

	auto expectedState = true;
	auto activeState = testTimer.isActive();

	EXPECT_EQ(expectedState, activeState);
}

TEST(IsActiveTest, isActive_SHOULD_ReturnFalse_WHEN_TheTimerStopped)
{
	Timer testTimer = Timer();
	testTimer.stop();

	auto expectedState = false;
	auto activeState = testTimer.isActive();

	EXPECT_EQ(expectedState, activeState);
}

TEST_F(TimerTestFixture, isActive_SHOULD_ReturnTrue_WHEN_TheTimerIsActive)
{
	auto expectedState = true;
	auto activeState = m_timer.isActive();

	EXPECT_EQ(expectedState, activeState);
}

TEST_F(TimerTestFixture, setTimeout_SHOULD_StartTimer_WhithTheCallback1)
{
	m_timer.setTimeout([](std::string_view str = "Cookoo!") -> bool {
		std::cout << "Tick Tock .. After 1s I'll print: " << str
			<< " & return false value & stop\n";
		return false;
	}, 1s);

	auto expectedTimerState = true;
	auto timerState = m_timer.isActive();

	EXPECT_EQ(expectedTimerState, timerState);
}

TEST_F(TimerTestFixture, setTimeout_SHOULD_StartTimer_WhithTheCallback2)
{
	m_timer.setTimeout([]() -> bool {
		std::cout << "Tick Tock .. After 1s I'll just return true value & stop\n";
		return true;
	}, 1s);

	auto expectedTimerState = true;
	auto timerState = m_timer.isActive();

	EXPECT_EQ(expectedTimerState, timerState);
}

TEST_F(TimerTestFixture, setTimeout_SHOULD_StartTimer_WhithTheCallback3)
{
	m_timer.setTimeout([]() {
		std::cout << "Tick Tock .. After 1s I'll do something & stop\n";
	}, 1s);

	auto expectedTimerState = true;
	auto timerState = m_timer.isActive();

	EXPECT_EQ(expectedTimerState, timerState);
}

TEST_F(TimerTestFixture, setInterval_SHOULD_NotStopTimer_WHEN_ItsLaunched)
{
	m_timer.setInterval([]() {
		std::cout << "Tick Tock .. After each 1s ...\n";
	}, 1s);

	// wait for 5 sec and than stop the timer
	std::this_thread::sleep_for(5s);

	auto expectedTimerState = true;
	auto timerState = m_timer.isActive();

	m_timer.stop();

	EXPECT_EQ(expectedTimerState, timerState);
}