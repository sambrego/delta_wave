//timer.cpp
#include "stdafx.h"

_SYSTEMTIME CTimer::prevtime;
long CTimer::ticks;

bool CTimer::RefreshTime()
{
	long t;
	_SYSTEMTIME newtime;
	GetSystemTime(&newtime);
	t = newtime.wMilliseconds-prevtime.wMilliseconds;
	t = t + (newtime.wSecond - prevtime.wSecond)*1000;
	t = t + (newtime.wMinute-prevtime.wMinute)*60*1000;
	t = t + (newtime.wHour-prevtime.wHour)*60*60*1000;
	ticks = t;
	prevtime = newtime;
	return true;
}
long CTimer::TicksTillPrevRefresh()
{
	return ticks;
}
CTimer::CTimer()
{
//	ticks=0;
}
