//graphobj.cpp
#include "stdafx.h"
CGraphObjMix::CGraphObjMix()
{
	bIsVisible = true;
}
bool CGraphObjMix::SetVisible(bool state)
{
	bIsVisible = state;
	return true;
}
bool CGraphObjMix::IsVisible()
{
	return bIsVisible;
}
/*bool CGraphObjMix::Draw()
{
return false;
}*/