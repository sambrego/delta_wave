//aniview.cpp
#include "stdafx.h"

COORDS CAniView::TranslateCoords;
COORDS CAniView::TranslateCoordsDelta;
long CAniView::TranslateTimer;
long CAniView::TranslateLimit;
bool CAniView::bTranslateAniActive;

COORDS CAniView::RotateVector;
COORDS CAniView::RotateVectorDelta;
DEGREES CAniView::degrees;
DEGREES CAniView::degreesDelta;
long CAniView::RotateTimer;
long CAniView::RotateLimit;
bool CAniView::bRotateAniActive;

CAniView::CAniView()
{
//	TranslateCoords.x=0;TranslateCoords.y=0;TranslateCoords.z=0;
//	bTranslateAniActive = false;

//	RotateVector.x=0;RotateVector.y=0;RotateVector.z=0;
//	degrees = 0;
//	bRotateAniActive = false;
}

bool CAniView::SetViewTranslateByStruct(COORDS TranslateCoords_new)
{
	TranslateCoords = TranslateCoords_new;
	return true;
}
bool CAniView::SetViewTranslateByCoords(float x,float y,float z)
{
	TranslateCoords.x=x;
	TranslateCoords.y=y;
	TranslateCoords.z=z;
	bTranslateAniActive = false;
	return true;
}
bool CAniView::SetViewTranslateAdditive(float x,float y,float z)
{
	TranslateCoords.x+=x;
	TranslateCoords.y+=y;
	TranslateCoords.z+=z;
	bTranslateAniActive = false;
	return true;
}

bool CAniView::SetViewRotateByStruct(COORDS RotateVector_new,DEGREES degrees_new)
{
	RotateVector = RotateVector_new;
	degrees = degrees_new;
	bRotateAniActive = false;
	bTranslateAniActive = false;
	return true;
}
bool CAniView::SetViewRotateByCoords(float x,float y,float z,DEGREES degrees_new)
{
	RotateVector.x = x;
	RotateVector.y = y;
	RotateVector.z = z;
	degrees = degrees_new;
	bRotateAniActive = false;
	return true;
}

bool CAniView::SetAniTranslateToByStruct(COORDS TranslateCoords_new,int timer,int limit)
{
	return SetAniTranslateToByCoords(TranslateCoords_new.x,TranslateCoords_new.y,TranslateCoords_new.z,timer,limit);
}
bool CAniView::SetAniTranslateToByCoords(float x,float y,float z,int timer,int limit)
{
	if((x==TranslateCoords.x)&&(y==TranslateCoords.y)&&(z==TranslateCoords.z))return false;
	if((limit<=0)||(timer>0))return false;
	TranslateCoordsDelta.x = (x - TranslateCoords.x)/limit;
	TranslateCoordsDelta.y = (y - TranslateCoords.y)/limit;
	TranslateCoordsDelta.z = (z - TranslateCoords.z)/limit;
	TranslateTimer = timer;
	TranslateLimit = limit;
	bTranslateAniActive = true;
	return true;
}

bool CAniView::SetAniRotateToByStruct(COORDS RotateVector_new,DEGREES degrees_new,int timer_new,int limit_new)
{
	return SetAniRotateToByCoords(RotateVector_new.x,RotateVector_new.y,RotateVector_new.z,degrees_new,timer_new,limit_new);
}
bool CAniView::SetAniRotateToByCoords(float x,float y,float z,DEGREES degrees_new,int timer_new,int limit_new)
{
	if((x==RotateVector.x)&&(y==RotateVector.y)&&(z==RotateVector.z)&&(degrees==degrees_new))return false;
	if((limit_new<=0)||(timer_new>0))return false;
	RotateVectorDelta.x = (x - RotateVector.x)/limit_new;
	RotateVectorDelta.y = (y - RotateVector.y)/limit_new;
	RotateVectorDelta.z = (z - RotateVector.z)/limit_new;
	degreesDelta = (degrees_new - degrees)/limit_new;
	RotateTimer = timer_new;
	RotateLimit = limit_new;
	bRotateAniActive = true;
	return true;
}

bool CAniView::IsActiveTranslateAni()
{
	return bTranslateAniActive;
}
bool CAniView::IsActiveRotateAni()
{
	return bRotateAniActive;
}
bool CAniView::ProcessView()
{
	long ticks;
	if(bTranslateAniActive)
	{		
		ticks=globaltimer.TicksTillPrevRefresh();
		TranslateTimer=TranslateTimer+ticks;
		if(TranslateTimer>=TranslateLimit)ticks=ticks-(TranslateTimer-TranslateLimit);
		if(TranslateTimer>=0){
			TranslateCoords.x = TranslateCoords.x + (TranslateCoordsDelta.x)*ticks;
			TranslateCoords.y = TranslateCoords.y + (TranslateCoordsDelta.y)*ticks;
			TranslateCoords.z = TranslateCoords.z + (TranslateCoordsDelta.z)*ticks;
		}
		if(TranslateTimer>=TranslateLimit)bTranslateAniActive = false;
	}
	if(bRotateAniActive)
	{
		ticks=globaltimer.TicksTillPrevRefresh();
		RotateTimer=RotateTimer+ticks;
		if(RotateTimer>=RotateLimit)ticks=ticks-(RotateTimer-RotateLimit);
		if(RotateTimer>=0){
			RotateVector.x = RotateVector.x + (RotateVectorDelta.x)*ticks;
			RotateVector.y = RotateVector.y + (RotateVectorDelta.y)*ticks;
			RotateVector.z = RotateVector.z + (RotateVectorDelta.z)*ticks;
			degrees=degrees+(degreesDelta)*ticks;
		}
		if(RotateTimer>=RotateLimit)bRotateAniActive = false;
	}
	//glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glTranslated(0,0,-1);
	//glTranslated(TranslateCoords.x,-TranslateCoords.y,TranslateCoords.z);
	glRotated(degrees,RotateVector.x,RotateVector.y,RotateVector.z);
	glTranslated(-TranslateCoords.x,-TranslateCoords.y,TranslateCoords.z);

	//glMatrixMode(GL_MODELVIEW);
	return true;
}