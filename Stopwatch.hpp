#pragma once

#include <chrono>
#include <string>

using namespace std::chrono;

class Stopwatch
{
public:
	enum Scale
	{
		sec,
		millisec,
		microsec,
		nanosec
	};

	/* Stopwatch class constructor */
	Stopwatch(Scale s)
	{
		m_result = duration<double>(0.0);
		m_scale = s;
	}

	/* Start or reStart the Stopwatch */
	void start() 
	{
		m_init = high_resolution_clock::now();
	}

	/* Restart the StopWatch */
	void restart()
	{
		start();
	}

	/* Stop the Stopwatch */
	void stop()
	{
		m_result = high_resolution_clock::now() - m_init;
	}

	/* Get the elapsed time as String format (with scale) */
	std::string getElapsedTimeAsStr() const
	{
		return std::to_string(getElapsedTime()) + getScaleAsStr();
	}

	/* Get the elapsed time from Stopwatch */
	long long getElapsedTime() const
	{
		switch (m_scale)
		{
			case Scale::sec:
				return duration_cast<seconds>(m_result).count();
			case Scale::millisec:
				return duration_cast<milliseconds>(m_result).count();
			case Scale::microsec:
				return duration_cast<microseconds>(m_result).count();
			case Scale::nanosec:
				return duration_cast<nanoseconds>(m_result).count();
			default:
				return duration_cast<seconds>(m_result).count();
		}
	}

	/* Get the Scale set to Stopwatch */
	std::string getScaleAsStr() const
	{
		switch (m_scale)
		{
			case Scale::sec:
				return "s";
			case Scale::millisec:
				return "ms";
			case Scale::microsec:
				return "us";
			case Scale::nanosec:
				return "ns";
			default:
				return "s";
		}
	}
private:
	time_point<high_resolution_clock> m_init;
	duration<double> m_result;
	Scale m_scale;
};
