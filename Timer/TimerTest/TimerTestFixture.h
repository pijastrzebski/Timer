#pragma once

#include "Timer.h"
#include "gtest/gtest.h"

struct TimerTestFixture : public ::testing::Test
{
	TimerTestFixture() :
		m_timer(Timer())
	{}

	Timer& m_timer;

	virtual void SetUp() override
	{
	}

	virtual void TearDown() override
	{
	}

	virtual void TestBody() override
	{
	}
};
