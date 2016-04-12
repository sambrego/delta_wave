//anicolor.cpp
#include "stdafx.h"
//CAniColor
CAniColor::CAniColor()
{
	col.r = 0;col.g = 0; col.b = 0;
	timer = 0;
	limit = 0;
	isactive = false;
}
bool CAniColor::SetColor(COLOR newcolor)
{
	if((newcolor.r<0||newcolor.r>1)||(newcolor.g<0||newcolor.g>1)||(newcolor.b<0||newcolor.b>1))return false;
	col.r = newcolor.r;col.g = newcolor.g; col.b = newcolor.b;
	timer = 0;
	limit = 0;
	isactive = false;
	return true;
}
bool CAniColor::SetAniTo(COLOR fincolor, long newtimer, long newlimit)
{
	if((fincolor.r<0||fincolor.r>1)||(fincolor.g<0||fincolor.g>1)||(fincolor.b<0||fincolor.b>1))return false;
	if((fincolor.r==col.r)&&(fincolor.g==col.g)&&(fincolor.b==col.b))return false;
	if((newlimit<=0)||(newtimer>0))return false;
	dr = (fincolor.r - col.r)/newlimit;
	dg = (fincolor.g - col.g)/newlimit;
	db = (fincolor.b - col.b)/newlimit;
	timer = newtimer;
	limit = newlimit;
	isactive = true;
	return true;
}
bool CAniColor::Process()
{
	long ticks;
	if(!isactive)return false;
	ticks=globaltimer.TicksTillPrevRefresh();
	timer=timer+ticks;
	if(timer>=limit)ticks=ticks-(timer-limit);
	if(timer>=0){
	col.r = col.r + (dr)*ticks;
	col.g = col.g + (dg)*ticks;
	col.b = col.b + (db)*ticks;
	}
	if(timer>=limit)isactive = false;
	return true;
}

float CAniColor::r(){return col.r;}
float CAniColor::g(){return col.g;}
float CAniColor::b(){return col.b;}
//end of CAniColor
