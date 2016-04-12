//solve.cpp
#include "stdafx.h"


CSolve::CSolve(int width,int height,int xcenter,int ycenter)
{
	int i;
	FieldWidth = width;
	FieldHeight = height;
	FieldCenterX = xcenter;
	FieldCenterY = ycenter;

	field = new TDigit*[width];
	for(i=0;i<width;i++)
		field[i] = new TDigit[height];

	isTermsInit = false;
}
CSolve::~CSolve()
{
	int i;
	for(i=0;i<FieldWidth;i++)
		delete [] field[i];
	delete [] field;
}
bool CSolve::InitTerms(TDigit start, TDigit finish)
{
	if((start<0)&&(finish<0))return false;

	isTermsInit = true;

	start_digit = start;
	finish_digit = finish;

	ijumpcount=0;

	field[FieldCenterX][FieldCenterY]=start;
	JumpTo(JUMP_NOT);
	
	dy = GetJByDigit(finish)-GetJByDigit(start);
	dx = (finish - GetRowCenterByJ(GetJByDigit(finish))) - (start - GetRowCenterByJ(GetJByDigit(start)));

	return true;
}
JUMP_DIR CSolve::Jump()
{	
	if(!isTermsInit)return JUMP_NOT;
	JUMP_DIR resjump;
	resjump = NextJump();
	JumpTo(resjump);

	return resjump;
}
bool CSolve::IsFinish(){
	if(!isTermsInit)return false;

	if(field[FieldCenterX][FieldCenterY]==finish_digit)return true;
	else return false;
}
JUMP_DIR CSolve::PrevJump()
{
	if(!isTermsInit)return JUMP_NOT;
	return LastJump;
}
JUMP_DIR CSolve::NextJump()
{
		JUMP_DIR jumpx=JUMP_NOT;
	JUMP_DIR jumpy=JUMP_NOT;
	JUMP_DIR resjump=JUMP_NOT;
	TDigit temp;

	if(!isTermsInit)return JUMP_NOT;

	temp = GetCell(FieldCenterX,FieldCenterY);

	if(dx<0) jumpx=JUMP_LEFT;
		else if(dx>0)jumpx=JUMP_RIGHT;
			else if(dy!=0)jumpx=JUMP_RIGHT;
	if(dy<0) jumpy=JUMP_UP;
		else if(dy>0)jumpy=JUMP_DOWN;
	
	resjump=jumpx;

	if(dy!=0)
		if(((jumpy==JUMP_UP)&&(IsEven(temp)!=IsEven(GetJByDigit(temp))))
			||((jumpy==JUMP_DOWN)&&(IsEven(temp)==IsEven(GetJByDigit(temp)))))
				resjump=jumpy;

	return resjump;
}

JUMP_DIR CSolve::NextNextJump()
{
	JUMP_DIR jumpx=JUMP_NOT;
	JUMP_DIR jumpy=JUMP_NOT;
	JUMP_DIR resjump=JUMP_NOT;
	TDigit temp;

	if(!isTermsInit)return JUMP_NOT;

	switch(NextJump())
	{
	case JUMP_UP:
		temp = GetCell(FieldCenterX,FieldCenterY-1);
		break;
	case JUMP_DOWN:
		temp = GetCell(FieldCenterX,FieldCenterY+1);
		break;
	case JUMP_LEFT:
		temp = GetCell(FieldCenterX-1,FieldCenterY);
		break;
	case JUMP_RIGHT:
		temp = GetCell(FieldCenterX+1,FieldCenterY);
		break;
	case JUMP_NOT:
		return JUMP_NOT;
	}

		if(dx<0) jumpx=JUMP_LEFT;
		else if(dx>0)jumpx=JUMP_RIGHT;
			else if(dy!=0)jumpx=JUMP_RIGHT;
	if(dy<0) jumpy=JUMP_UP;
		else if(dy>0)jumpy=JUMP_DOWN;
	
	resjump=jumpx;

	if(dy!=0)
		if(((jumpy==JUMP_UP)&&(IsEven(temp)!=IsEven(GetJByDigit(temp))))
			||((jumpy==JUMP_DOWN)&&(IsEven(temp)==IsEven(GetJByDigit(temp)))))
				resjump=jumpy;

	return resjump;
}

TDigit CSolve::GetStartTerm()
{
	if(!isTermsInit)return 0;
	return start_digit;
}
TDigit CSolve::GetFinishTerm()
{
	if(!isTermsInit)return 0;
	return finish_digit;
}
TDigit CSolve::GetCell(int x, int y)
{
	
	if(!isTermsInit)return -1;

	if((x>=FieldWidth)||(y>=FieldHeight)||(x<0)||(y<0))return -1;
	return field[x][y];
}
int CSolve::JumpCount(){
	return ijumpcount;
}
bool CSolve::JumpTo(JUMP_DIR dir)
{
TDigit temp;
int i,j;

if(!isTermsInit)return false;

temp = field[FieldCenterX][FieldCenterY];
switch(dir){
case JUMP_UP:
	if(IsEven(temp)==IsEven(GetJByDigit(temp)))return false;
	if(temp==3)temp=1;
	else temp=temp-GetRowNByJ(GetJByDigit(temp))+1;
	LastJump = JUMP_UP;
	dy++;
	break;
case JUMP_DOWN:
	if(IsEven(temp)!=IsEven(GetJByDigit(temp)))return false;
	temp=temp+GetRowNByJ(GetJByDigit(temp))+1;
	LastJump = JUMP_DOWN;
	dy--;
	break;
case JUMP_LEFT:
	if(GetJByDigit(temp-1)!=GetJByDigit(temp))return false;
	temp--;
	LastJump = JUMP_LEFT;
	dx++;
	break;
case JUMP_RIGHT:
	if(GetJByDigit(temp+1)!=GetJByDigit(temp))return false;
	temp++;
	LastJump = JUMP_RIGHT;
	dx--;
	break;
case JUMP_NOT:
	break;
default:
	return false;
}

	for(i=0;i<FieldWidth;i++)
		for(j=0;j<FieldHeight;j++)
		{
			field[i][j]=(int)(temp+pow(j-FieldCenterY,2)+(GetJByDigit(temp)*2-1)*(j-FieldCenterY)+(i-FieldCenterX));
			if((GetJByDigit(field[i][j])-GetJByDigit(temp))!=(j-FieldCenterY))field[i][j]=0;
		}	
	if(dir!=JUMP_NOT)ijumpcount++;
	return true;
}
int CSolve::GetRowNByJ(int j)
{
	if(!isTermsInit)return -1;
	return (2*j)-1;
}
int CSolve::GetJByDigit(TDigit dig)
{
	int q;
	
	if(!isTermsInit)return -1;

	if(dig<=0)return -30000;
	q = (int)sqrt(dig-1);
	q=q+1;
	return q;
}
int CSolve::GetRowCenterByJ(int j)
{
	int q;

	if(!isTermsInit)return -1;
	q = j*(j-1)+1;
	return q;
}
bool CSolve::IsEven(TDigit dig)
{
	if(!isTermsInit)return -1;
	if((dig%2)==1)return false;
	else return true;
}