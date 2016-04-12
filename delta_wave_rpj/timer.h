//timer.h
#if !defined(TIMER_H_INCLUDED)
#define TIMER_H_INCLUDED

class CTimer{
public:
	CTimer();
	bool RefreshTime();
	long TicksTillPrevRefresh();
private:
	static _SYSTEMTIME prevtime;
	static long ticks;

};
bool iTimer_RefreshTime();
long iTimer_TicksTillPrevRefresh();
#endif