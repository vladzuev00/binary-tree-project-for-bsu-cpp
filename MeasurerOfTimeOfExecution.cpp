#include "stdafx.h"
#include "MeasurerOfTimeOfExecution.h"
#include <ctime>
#include <chrono>

//*****************************************************************************
MeasurerOfTimeOfExecution::MeasurerOfTimeOfExecution()
{

}
//*****************************************************************************
double MeasurerOfTimeOfExecution::mesuareExecutionBySeconds(
	const std::function<void()> &executedFunction) const
{
	std::chrono::steady_clock::time_point startOfExecution = std::chrono::high_resolution_clock::now();
	executedFunction();
	std::chrono::steady_clock::time_point endOfExecution = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> durationOfExecution = endOfExecution - startOfExecution;
	return durationOfExecution.count();
}
//*****************************************************************************
MeasurerOfTimeOfExecution::~MeasurerOfTimeOfExecution()
{

}
//*****************************************************************************