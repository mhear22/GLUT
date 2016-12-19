#include "TimeMonitor.h"

TimeMonitor::TimeMonitor()
{
	time = high_resolution_clock::now();
}

float TimeMonitor::Tick()
{
	high_resolution_clock::time_point currentTime = high_resolution_clock::now();
	auto result = duration_cast<seconds>(currentTime-time).count();
	time = currentTime;
	return result;
}
