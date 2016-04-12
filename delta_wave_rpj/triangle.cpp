//triangle.cpp
#include "stdafx.h"

CTriangle::CTriangle()
{
	SetColor(COLOR_BLACK,COLOR_BLACK,COLOR_BLACK);
}
CTriangle::~CTriangle()
{
}
bool CTriangle::SetColor(COLOR vertexcolor1,COLOR vertexcolor2,COLOR vertexcolor3)
{
	v1.SetColor(vertexcolor1);
	v2.SetColor(vertexcolor2);
	v3.SetColor(vertexcolor3);
	return true;
}
bool CTriangle::SetAniColor(COLOR vertexcolor1,COLOR vertexcolor2,COLOR vertexcolor3,long newtimer,long newlimit)
{
	v1.SetAniTo(vertexcolor1,newtimer,newlimit);
	v2.SetAniTo(vertexcolor2,newtimer,newlimit);
	v3.SetAniTo(vertexcolor3,newtimer,newlimit);
	return true;
}
bool CTriangle::SetParams(COORDS center,bool rotated,float newscale)
{
	centercoords = center;
	isrotated = rotated;
	scale = newscale;
	return true;
}
bool CTriangle::Draw()
{
	v1.Process();
	v2.Process();
	v3.Process();
	if(!CGraphObjMix::bIsVisible)return false;
	glPushMatrix();
	glTranslatef(centercoords.x,centercoords.y,centercoords.z);
	if(isrotated)
	{
		glRotated(180,-1,0,0);
	}
	glScaled(scale,scale,scale);
	glBegin(GL_TRIANGLES);
		glColor3f(v1.r(),v1.g(),v1.b());
		glVertex3f((float)-0.866,(float)-0.75,0);
		glColor3f(v2.r(),v2.g(),v2.b());
		glVertex3f(0,(float)0.75,0);
		glColor3f(v3.r(),v3.g(),v3.b());
		glVertex3f((float)0.866,(float)-0.75,0);
	glEnd();
	glPopMatrix();
	return true;
}

COORDS CTriangle::Vertex1()//warning: don't correct with true isrotated param
{
	COORDS v;
	v.x=centercoords.x+(float)(-0.866)*scale;
	v.y=centercoords.y+(float)(-0.75)*scale;
	v.z=centercoords.z+(float)(0)*scale;
	if(isrotated)
	{v.y+=(float)1.5*scale;
	}
	return v;
}
COORDS CTriangle::Vertex2()
{
	COORDS v;
	v.x=centercoords.x+(float)(0)*scale;
	v.y=centercoords.y+(float)(0.75)*scale;
	v.z=centercoords.z+(float)(0)*scale;
	if(isrotated)
	{v.y-=(float)1.5*scale;
	}
	return v;
}
COORDS CTriangle::Vertex3()
{
	COORDS v;
	v.x=centercoords.x+(float)(0.866)*scale;
	v.y=centercoords.y+(float)(-0.75)*scale;
	v.z=centercoords.z+(float)(0)*scale;
	if(isrotated)
	{v.y+=(float)1.5*scale;
	}
	return v;
}
bool CTriangle::SetRotated(bool rotated)
{
	isrotated=rotated;
	return true;
}
bool CTriangle::InvertRotate()
{
	isrotated^=true;
	return true;
}
bool CTriangle::IsRotated()
{
	return isrotated;
}

COORDS CTriangle::GetTrueCenter()
{
	COORDS v;
	v.x=centercoords.x;
	v.y=centercoords.y-(float)(0.25)*scale;
	v.z=centercoords.z;
	if(isrotated)
	{v.y+=(float)0.5*scale;
	}
	return v;
}

COORDS CTriangle::GetCenter()
{
	return centercoords;
}