#ifndef VMETRICS_API
#define VMETRICS_API __declspec(dllexport)
#else
#define VMETRICS_API __declspec(dllimport)
#endif

#include <windows.h>

VMETRICS_API class VTimer
{
public:

	VTimer();

	~VTimer(){};

	// Resets the timer's reference point to "now"
	void setStartTick();

	// Returns time in us since last tick
	double tick();

	// Time in microseconds 
	double time_u();

	// Time in milliseconds
	double time_ms();

	// Time in seconds
	double time_s();

	// Time in minutes
	double time_m();

	// Time in hours
	double time_h();

private:
	LARGE_INTEGER m_baseTime;
	LARGE_INTEGER m_currentTime;
	LARGE_INTEGER m_clockFrequency;

	LARGE_INTEGER m_tickTime;
};