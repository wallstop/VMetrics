#ifndef VMETRICS_API
#define VMETRICS_API __declspec(dllexport)
#else
#define VMETRICS_API __declspec(dllimport)
#endif

#include <windows.h>

class VTimer
{
public:

	VMETRICS_API VTimer();

	VMETRICS_API ~VTimer(){};

	// Resets the timer's reference point to "now"
	void VMETRICS_API setStartTick();

	// Returns time in us since last tick
	double VMETRICS_API tick();

	// Time in microseconds 
	double VMETRICS_API time_u();

	// Time in milliseconds
	double VMETRICS_API time_ms();

	// Time in seconds
	double VMETRICS_API time_s();

	// Time in minutes
	double VMETRICS_API time_m();

	// Time in hours
	double VMETRICS_API time_h();

private:
	LARGE_INTEGER m_baseTime;
	LARGE_INTEGER m_currentTime;
	LARGE_INTEGER m_clockFrequency;

	LARGE_INTEGER m_tickTime;
};