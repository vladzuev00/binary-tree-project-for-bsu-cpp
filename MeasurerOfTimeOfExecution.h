#ifndef MEASUREROFTIMEOFEXECUTION_H
#define MEASUREROFTIMEOFEXECUTION_H

#include  <functional>

//*****************************************************************************
class MeasurerOfTimeOfExecution
{
public:
	MeasurerOfTimeOfExecution();
public:
	double mesuareExecutionBySeconds(const std::function<void()> &executedFunction) const;
public:
	~MeasurerOfTimeOfExecution();
};
//*****************************************************************************

#endif MEASUREROFTIMEOFEXECUTION_H