#include "VTimer.h"

#if defined _WIN32 || defined _WIN64 || defined OS_WINDOWS || defined WIN32
	#include <windows.h>

inline VTimer::VTimer()
{
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER *>(&m_clockFrequency));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&m_baseTime));
}

inline void VTimer::setStartTick()
{
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&m_baseTime));
}

inline const double VTimer::tick()
{
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&m_currentTime));
	return m_currentTime;
}


#elif defined OS_LINUX || defined unix || defined __unix__ || defined __unix || defined __linux__
//TODO: Add Linux headers, linux methods...
#endif


inline const double VTimer::time_u() 
{
	return (tick() - m_baseTime) * 1000000 / m_clockFrequency;
}

inline const double VTimer::time_ms()
{
	return (tick() - m_baseTime) * 1000 / m_clockFrequency;
}

inline const double VTimer::time_s()
{
	return (tick() - m_baseTime) / m_clockFrequency;
}

inline const double VTimer::time_m()
{
	return ((tick() - m_baseTime) / m_clockFrequency) / 60;
}

inline const double VTimer::time_h()
{
	return ((tick() - m_baseTime) / m_clockFrequency) / 360;
}