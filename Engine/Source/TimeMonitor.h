#ifndef TimeMonitor_hpp
#define TimeMonitor_hpp

#include "header.h"

using namespace std::chrono;

class TimeMonitor{
public:
	TimeMonitor();
	~TimeMonitor();
	
	float Tick();
private:
	high_resolution_clock::time_point time;
};

#endif /* TimeMonitor_h */
