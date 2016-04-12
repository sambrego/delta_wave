//intrface.cpp
#include "stdafx.h"

ACTION CInterface::LastAction;
bool CInterface::bIsInitMouseMode;
float CInterface::xsens,CInterface::ysens;
int CInterface::x,CInterface::y;
bool CInterface::bWasLeftClick;
bool CInterface::bWasRightClick;

bool CInterface::bWasKeyPressed;
char CInterface::key;

bool CInterface::InitMouseMode()
{
	if(!bIsInitMouseMode)
	{
		bIsInitMouseMode = true;
		ShowCursor(false);
		SetCursorPos(GetSystemMetrics(SM_CXSCREEN)/2,GetSystemMetrics(SM_CYSCREEN)/2);
		x=GetSystemMetrics(SM_CXSCREEN)/2;
		y=GetSystemMetrics(SM_CYSCREEN)/2;
	}
	return true;
}
bool CInterface::DeInitMouseMode()
{
	if(bIsInitMouseMode)
	{
		bIsInitMouseMode = false;
		ShowCursor(true);
	}
	else return false;

	return true;
}
bool CInterface::IsInitMouseMode()
{
	return bIsInitMouseMode;
}
bool CInterface::SetMouseSensivity(float xsens_new,float ysens_new)
{
	xsens = xsens_new;
	ysens = ysens_new;
	return true;
}
ACTION CInterface::GetLastAction()
{
	if(bIsInitMouseMode)
		return LastAction;
	else return ACTION_NO;
}
bool CInterface::RefreshActions()
{
	POINT mousecoord;
	int newx,newy;

	if(!bIsInitMouseMode)
		return false;

	GetCursorPos(&mousecoord);
	newx=mousecoord.x;
	newy=mousecoord.y;

	LastAction=ACTION_NO;

	if( ((x-newx)*xsens)> 1)
		{
		LastAction=ACTION_LEFT;
		SetCursorPos(GetSystemMetrics(SM_CXSCREEN)/2,y);
		}
	else if( ((x-newx)*xsens)< -1)
		{
		LastAction=ACTION_RIGHT;
		SetCursorPos(GetSystemMetrics(SM_CXSCREEN)/2,y);
		}
	else if( ((y-newy)*ysens)> 1)
		{
		LastAction=ACTION_UP;
		SetCursorPos(x,GetSystemMetrics(SM_CYSCREEN)/2);
		}
	else if( ((y-newy)*ysens)< -1)
		{
		LastAction=ACTION_DOWN;
		SetCursorPos(x,GetSystemMetrics(SM_CYSCREEN)/2);
		}

	if(bWasLeftClick)  LastAction=ACTION_OK;
	if(bWasRightClick) LastAction=ACTION_CANCEL;
	if(bWasKeyPressed)
		switch(key)
			{
				case 27:      
					LastAction=ACTION_CANCEL;
					break;
				case 13:
					LastAction=ACTION_OK;
					break;
				case 'A':
				case 'a':
				case 37:
					LastAction=ACTION_LEFT;
					break;
				case 'S':
				case 's':
				case 40:									
					LastAction=ACTION_DOWN;
					break;
				case 'W':
				case 'w':
				case 38:
					LastAction=ACTION_UP;
					break;
				case 'D':
				case 'd':
				case 39:
					LastAction=ACTION_RIGHT;
					break;
			}
	bWasLeftClick = false;
	bWasRightClick = false;
	bWasKeyPressed = false;

	return true;
}

bool CInterface::WasLeftClick()
{
	if(!bIsInitMouseMode)
		return false;
	bWasLeftClick = true;
	return true;
}
bool CInterface::WasRightClick()
{
	if(!bIsInitMouseMode)
		return false;
	bWasRightClick = true;
	return true;
}
bool CInterface::WasKeyPressed(char KeyPressed)
{
	if(!bIsInitMouseMode)
		return false;
	bWasKeyPressed = true;
	key = KeyPressed;
	return true;
}


