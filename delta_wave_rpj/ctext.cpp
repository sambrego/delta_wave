//ctext.cpp
#include "stdafx.h"

//CText
CText::CText()
{
	rdegree=0;
	isinit=false;
};
bool CText::InitText(char* srcstr,COORDS crds,float scale,bool isautoscale,COLOR col,HORIZ_ALIGN align,VERT_ALIGN valign)
{
	if(strlen(srcstr)>=MAX_TEXT_LENGHT)return false;
	strcpy_s(str,srcstr);
	lenght = strlen(srcstr);
	coords = crds;
	textscale = scale;
	autoscale = isautoscale;
	if((autoscale)&&(lenght!=0))textscale=textscale/lenght;
	textalign=align;
	verttextalign=valign;
	vertcorrect=1;
	if(verttextalign==VA_CENTER)vertcorrect=3;
	else if(verttextalign==VA_BOTTOM)vertcorrect=5;
	color.SetColor(col);
	isinit = true;
	return true;
}
bool CText::SetText(char* srcstr)
{	
	if(strlen(srcstr)>=MAX_TEXT_LENGHT)return false;
	strcpy_s(str,srcstr);

	if((autoscale)&&(lenght!=0))textscale=textscale*lenght;
	lenght = strlen(srcstr);
	if((autoscale)&&(lenght!=0))textscale=textscale/lenght;

	return true;
}

bool CText::SetLongIntAsText(long srclong)
{	
	char srcstr[MAX_TEXT_LENGHT];
	_ltoa_s(srclong,srcstr,10);
	if(strlen(srcstr)>=MAX_TEXT_LENGHT)return false;
	strcpy_s(str,srcstr);

	if((autoscale)&&(lenght!=0))textscale=textscale*lenght;
	lenght = strlen(srcstr);
	if((autoscale)&&(lenght!=0))textscale=textscale/lenght;

	return true;
}

bool CText::SetRotate(COORDS vectorcoord,int degrees,bool bfrtranslate)
{
	if(!isinit)return false;
	vcoord=vectorcoord;
	rdegree = degrees;
	RotateBeforeTranslate = bfrtranslate;
	return true;
}
bool CText::Draw()
{
	int i;
	//int linecount=0;
	COORDS crds;

	if(!isinit)return false;
	color.Process();
	if(!CGraphObjMix::bIsVisible)return false;

	glPushMatrix();

	if(RotateBeforeTranslate)glRotatef(rdegree,vcoord.x,vcoord.y,vcoord.z);

	glTranslatef(coords.x,coords.y,coords.z);

	if(!RotateBeforeTranslate)glRotatef(rdegree,vcoord.x,vcoord.y,vcoord.z);

	glColor3f(color.r(),color.g(),color.b());



	glScalef(textscale,textscale,textscale);
	if(textalign==HA_CENTER)glTranslatef((float)-((float)lenght/2)*5+0.5,0,0);
	else if(textalign==HA_RIGHT)glTranslatef((float)-lenght*5,0,0);
	crds.x=0;crds.y=0;crds.z=0;
	for(i=0;i<lenght;i++)
	{
		if(str[i]!='\n')DrawLetter(str[i],crds);
		else
		{
			crds.y-=6;
			crds.x = 0;
		}
		crds.x = crds.x +5;
	}
	glPopMatrix();
	return true;
}
bool CText::DrawLetter(char c,COORDS lettercoords)
{
	glPushMatrix();
	glTranslatef(lettercoords.x,lettercoords.y,lettercoords.z);
	glBegin(GL_TRIANGLES);
	switch(c){
	case '0':
		DrawTriangle(1,3,     3,1,    3,2);
		DrawTriangle(1,3,     2,3,    3,5);
		DrawTriangle(3,4,     3,5,    5,3);
		DrawTriangle(4,3,     5,3,    3,1);
		break;
	case '1':
		DrawTriangle(1,3,     3,1,    3,2);
		DrawTriangle(3,1,     3,5,    4,2);
		break;
	case '2':
		DrawTriangle(1,3,     3,1,    3,2);
		DrawTriangle(3,1,     4,2,    1,5);
		DrawTriangle(1,5,     5,4,    5,5);
		break;
	case '3':
		DrawTriangle(1,3,     5,1,    5,2);
		DrawTriangle(1,4,     5,2,    5,3);
		DrawTriangle(1,5,     5,3,    5,4);
		break;
	case '4':
		DrawTriangle(1,3,     3,1,    3,3);
		DrawTriangle(3,1,     3,5,    4,1);
		break;
	case '5':
		DrawTriangle(1,1,     5,1,    1,2);
		DrawTriangle(1,2,     5,3,    5,4);
		DrawTriangle(1,5,     5,3,    5,4);
		break;
	case '6':
		DrawTriangle(5,1,     1,3,    1,4);
		DrawTriangle(1,3,     5,4,    1,5);
		break;
	case '7':
		DrawTriangle(1,1,     3,2,    5,1);
		DrawTriangle(4,1,     5,1,    3,5);
		break;
	case '8':
		DrawTriangle(3,1,     2,2,    4,2);
		DrawTriangle(3,3,     2,2,    4,2);
		DrawTriangle(3,3,     1,4,    5,4);
		DrawTriangle(3,5,     1,4,    5,4);
		break;
	case '9':
		DrawTriangle(4,1,     5,1,    3,5);
		DrawTriangle(1,2,     4,1,    4,3);
		break;
	case 'a':
		DrawTriangle(3,1,   1,5,   5,5);
		break;
	case 'b':
		DrawTriangle(1,1,     5,2,    1,3);
		DrawTriangle(1,3,     5,4,    1,5);
		break;
	case 'c':
		DrawTriangle(5,1,     1,2,    1,4);
		DrawTriangle(5,5,     1,2,    1,4);
		break;
	case 'd':
		DrawTriangle(1,1,     5,3,    1,5);
		break;
	case 'e':
		DrawTriangle(5,1,     1,2,    1,3);
		DrawTriangle(5,2,     1,3,    1,4);
		DrawTriangle(5,3,     1,4,    1,5);
		break;
	case 'f':
		DrawTriangle(1,1,     5,1,    1,2);
		DrawTriangle(1,2,     5,2,    1,3);
		DrawTriangle(1,1,     1,5,    2,1);
		break;
	case 'g':
		DrawTriangle(5,1,     1,1,    1,2);
		DrawTriangle(1,1,     1,5,    2,5);
		DrawTriangle(1,4,     1,5,    5,5);
		DrawTriangle(5,3,     5,5,    4,5);
		break;
	case 'h':
		DrawTriangle(1,1,     1,5,    2,5);
		DrawTriangle(5,1,     4,1,    5,5);
		DrawTriangle(1,3,     5,3,    5,2);
		break;
	case 'i':
		DrawTriangle(3,1,     4,1,    3,5);
		break;
	case 'j':
		DrawTriangle(3,1,     4,1,    3,5);
		DrawTriangle(1,3,     1,4,    3,5);
		break;
	case 'k':
		DrawTriangle(1,1,     2,1,    1,5);
		DrawTriangle(5,1,     1,3,    1,4);
		DrawTriangle(5,5,     1,3,    1,4);
		break;
	case 'l':
		DrawTriangle(1,1,     1,5,    2,5);
		DrawTriangle(1,5,     1,4,    5,5);
		break;
	case 'm':
		DrawTriangle(1,1,     1,5,    2,1);
		DrawTriangle(2,1,     4,1,    3,5);
		DrawTriangle(4,1,     4,5,    5,1);
		break;
	case 'n':
		DrawTriangle(1,1,     2,1,    1,5);
		DrawTriangle(5,1,     5,5,    4,5);
		DrawTriangle(1,1,     5,5,    4,5);
		break;
	case 'o':
		DrawTriangle(1,1,     2,1,    1,5);
		DrawTriangle(1,4,     1,5,    5,5);
		DrawTriangle(4,5,     5,5,    5,1);
		DrawTriangle(1,1,     5,1,    5,2);
		break;
	case 'p':
		DrawTriangle(1,1,     1,5,    2,1);
		DrawTriangle(1,1,     5,2,    1,3);
		break;
	case 'q':
		DrawTriangle(1,1,     2,1,    1,5);
		DrawTriangle(1,4,     1,5,    5,5);
		DrawTriangle(4,5,     5,5,    5,1);
		DrawTriangle(1,1,     5,1,    5,2);
		DrawTriangle(4,5,     5,5,    5,6);
		break;
	case 'r':
		DrawTriangle(1,1,     5,2,    1,3);
		DrawTriangle(1,1,     2,1,    1,5);
		DrawTriangle(1,3,     1,4,    5,5);
		break;
	case 's':
		DrawTriangle(1,1,     1,2,    5,1);
		DrawTriangle(1,1,     1,2,    5,5);
		DrawTriangle(1,5,     5,5,    5,4);
		break;
	case 't':
		DrawTriangle(1,1,     5,2,    5,1);
		DrawTriangle(3,1,     4,1,    3,5);
		break;
	case 'u':
		DrawTriangle(1,1,     1,5,    2,5);
		DrawTriangle(1,4,     1,5,    5,5);
		DrawTriangle(4,1,     4,5,    5,5);
		break;
	case 'v':
		DrawTriangle(1,1,     3,4,    3,5);
		DrawTriangle(5,1,     3,4,    3,5);
		break;
	case 'w':
		DrawTriangle(1,1,     2,5,    3,4);
		DrawTriangle(5,1,     4,5,    3,4);
		DrawTriangle(3,1,     2,5,    4,5);
		break;
	case 'x':
		DrawTriangle(1,1,     1,2,    5,5);
		DrawTriangle(4,1,     5,1,    1,5);
		break;
	case 'y':
		DrawTriangle(1,1,     1,2,    3,3);
		DrawTriangle(5,1,     5,2,    2,5);
		break;
	case 'z':
		DrawTriangle(1,1,     1,2,    5,1);
		DrawTriangle(4,1,     5,1,    1,5);
		DrawTriangle(1,4,     1,5,    5,5);
		break;
	case '.':
		DrawTriangle(1,4,     1,5,    2,5);
		DrawTriangle(1,4,     2,4,    2,5);
		break;
	case ',':
		DrawTriangle(1,4,     1,5,    2,4);
		DrawTriangle(2,4,     1,5,    2,6);
		break;
	case '-':
		DrawTriangle(1,3,     1,4,    5,3);
		DrawTriangle(1,4,     5,3,    5,4);
		break;
	case ' ':
		break;
	default:
		glEnd();
		glPopMatrix();
		return false;
	}
	glEnd();
	glPopMatrix();
	return true;
}
bool CText::DrawTriangle(int t1x,int t1y,int t2x,int t2y,int t3x,int t3y)
{
	
	glVertex3f((float)t1x-1,(float)-t1y+vertcorrect,0);
	glVertex3f((float)t2x-1,(float)-t2y+vertcorrect,0);
	glVertex3f((float)t3x-1,(float)-t3y+vertcorrect,0);
	return true;
}
//end of CText