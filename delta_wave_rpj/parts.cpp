//parts.cpp
#include "stdafx.h"

CParts::CParts(int arrwidth_new, int arrheight_new)
{
	int i;
	if((arrwidth_new<1)||(arrheight<1))
	{
		arrwidth=arrwidth_new;
		arrheight=arrheight_new;
	}else
	{
		arrwidth=1;
		arrheight=1;
	}
	
	trianglearr = new CTriangle*[arrwidth];
	for(i=0;i<arrwidth;i++)
		trianglearr[i] = new CTriangle[arrheight];
	textarr = new CText*[arrwidth];
	for(i=0;i<arrwidth;i++)
		textarr[i] = new CText[arrheight];
}
CParts::~CParts()
{
	int i;
	for(i=0;i<arrwidth;i++)
		delete [] trianglearr[i];
	delete[] trianglearr;

	for(i=0;i<arrwidth;i++)
		delete [] textarr[i];
	delete[] textarr;
}
CTriangle* CParts::Trngl(int i,int j)
{
	if((i<0)||(i>=arrwidth)||(j<0)||(j>=arrheight))return &trianglearr[0][0];
	else return &trianglearr[i][j];
}
CText* CParts::Text(int i,int j)
{
	if((i<0)||(i>=arrwidth)||(j<0)||(j>=arrheight))return &textarr[0][0];
	else return &textarr[i][j];
}
bool CParts::SetVisible(bool state,CGraphObjMix* obj,...)//at the and must be 0
{
CGraphObjMix** p=&obj;
//for(;(int)*p!=0;p=p+sizeof(CGraphObjMix))
for ( ; *p!=0;p++)// p=p+sizeof(CGraphObjMix*)) 
	(**p).SetVisible(state);
return true;
}
bool CParts::SetInvisibleAll()
{
	int i,j;
	MenuGame.SetVisible(false);
	MenuAbout.SetVisible(false);
	MenuExit.SetVisible(false);
	StartDigitLable.SetVisible(false);
	StartDigit.SetVisible(false);
	FinDigitLable.SetVisible(false);
	FinDigit.SetVisible(false);
	MenuGo.SetVisible(false);
	LogoDeltaWave.SetVisible(false);
	JumpCount.SetVisible(false);
	AboutBlahBlah.SetVisible(false);
	GMJumpCount.SetVisible(false);
	GMJumpCountLable.SetVisible(false);
	for(i=0;i<arrwidth;i++)
		for(j=0;j<arrheight;j++)
		{
			trianglearr[i][j].SetVisible(false);
			textarr[i][j].SetVisible(false);
		}
	return true;
}
bool CParts::SetFadeAll(long time)
{
	int i,j;
	time--;
	const COLOR FADE_COLOR=COLOR_BLACK;
	MenuGame.color.SetAniTo(FADE_COLOR,-1,time);
	MenuAbout.color.SetAniTo(FADE_COLOR,-1,time);
	MenuExit.color.SetAniTo(FADE_COLOR,-1,time);
	StartDigitLable.color.SetAniTo(FADE_COLOR,-1,time);
	StartDigit.color.SetAniTo(FADE_COLOR,-1,time);
	FinDigitLable.color.SetAniTo(FADE_COLOR,-1,time);
	FinDigit.color.SetAniTo(FADE_COLOR,-1,time);
	MenuGo.color.SetAniTo(FADE_COLOR,-1,time);
	LogoDeltaWave.color.SetAniTo(FADE_COLOR,-1,time);
	JumpCount.color.SetAniTo(FADE_COLOR,-1,time);
	AboutBlahBlah.color.SetAniTo(FADE_COLOR,-1,time);
	GMJumpCount.color.SetAniTo(FADE_COLOR,-1,time);
	GMJumpCountLable.color.SetAniTo(FADE_COLOR,-1,time);

	for(i=0;i<arrwidth;i++)
		for(j=0;j<arrheight;j++)
		{
			trianglearr[i][j].SetAniColor(FADE_COLOR,FADE_COLOR,FADE_COLOR,-1,time);
			textarr[i][j].color.SetAniTo(FADE_COLOR,-1,time);
		}
	return true;
}
bool CParts::InitStartState()
{
	int i,j;
	COORDS crds;
	bool swrotated=false;
	const float trianglescale=(float)0.9;
	SetInvisibleAll();
//	triangle.SetParams(crds,false,(float)0.25);
//	triangle.SetColor(COLOR_BLACK_BLUE,COLOR_BLACK_BLUE,COLOR_COBALT);
	for(i=0;i<arrwidth;i++)
	{
		if(arrheight%2!=1)swrotated=swrotated^true;
		for(j=0;j<arrheight;j++)
		{
			swrotated=swrotated^true;
			crds.x=(float)i*0.866;crds.y=(float)-j*1.5;crds.z=0;

			trianglearr[i][j].SetParams(crds,swrotated,trianglescale);
			trianglearr[i][j].SetVisible(true);
			//trianglearr[i][j].SetColor(COLOR_BLACK_BLUE,COLOR_BLACK_BLUE,COLOR_COBALT);

			textarr[i][j].InitText("",crds,(float)0.08,true,COLOR_BLACK,HA_CENTER,VA_TOP);
			textarr[i][j].SetLongIntAsText(i*j);
			//textarr[i][j].SetText("a");
			//textarr[i][j].SetVisible(true);
		}
	}
	SetInvisibleAll();
	//Trngl(9,0)->SetVisible(true);
	MenuGame.InitText(" game",Trngl(9,0)->Vertex2(),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	MenuGame.SetRotate(xyz(0,0,-1),90,false);
	//MenuGame.SetVisible(true);

	MenuGo.InitText("go",xyz(Trngl(9,0)->Vertex2().x-4.4,Trngl(9,0)->Vertex2().y-4.5,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	MenuGo.SetRotate(xyz(0,0,-1),90,false);
	//MenuGo.SetVisible(true);

	StartDigitLable.InitText(" start:",xyz(Trngl(9,0)->Vertex2().x-1.35,Trngl(9,0)->Vertex2().y,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	StartDigitLable.SetRotate(xyz(0,0,-1),90,false);
	//StartDigitLable.SetVisible(true);

	StartDigit.InitText("12345",xyz(Trngl(9,0)->Vertex2().x-1.75,Trngl(9,0)->Vertex2().y-1.19,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_CENTER,VA_CENTER);
	StartDigit.SetRotate(xyz(0,0,-1),90,false);
	//StartDigit.SetVisible(true);

	FinDigitLable.InitText(" finish:",xyz(Trngl(9,0)->Vertex2().x-2.45,Trngl(9,0)->Vertex2().y-2.75,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	FinDigitLable.SetRotate(xyz(0,0,-1),90,false);
	//FinDigitLable.SetVisible(true);

	FinDigit.InitText("12345",xyz(Trngl(9,0)->Vertex2().x-2.85,Trngl(9,0)->Vertex2().y-2.75-1.35,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_CENTER,VA_CENTER);
	FinDigit.SetRotate(xyz(0,0,-1),90,false);
	//FinDigit.SetVisible(true);
	
	GMJumpCountLable.InitText(" jumps:",xyz(Trngl(9,0)->Vertex2().x-2.45,Trngl(9,0)->Vertex2().y,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	GMJumpCountLable.SetRotate(xyz(0,0,-1),90,false);

	GMJumpCount.InitText("12345",xyz(Trngl(9,0)->Vertex2().x-2.85,Trngl(9,0)->Vertex2().y-1.19,Trngl(9,0)->Vertex2().z),0.07,false,COLOR_WHITE,HA_CENTER,VA_CENTER);
	GMJumpCount.SetRotate(xyz(0,0,-1),90,false);

	MenuAbout.InitText(" about",Trngl(9,0)->Vertex3(),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	MenuAbout.SetRotate(xyz(0,0,-1),-30,false);
	//MenuAbout.SetVisible(true);
	//SetVisible(true,&MenuAbout,0);

	AboutBlahBlah.InitText("this program was developed\nby matvey nekhamin\nas kursovoi project\nfor tppd subject.",xyz(9,0,0),0.04,false,COLOR_WHITE,HA_LEFT,VA_TOP);
	AboutBlahBlah.SetRotate(xyz(0,0,-1),-30,false);
	//AboutBlahBlah.SetVisible(true);

	MenuExit.InitText(" exit",Trngl(9,0)->Vertex1(),0.07,false,COLOR_WHITE,HA_LEFT,VA_CENTER);
	MenuExit.SetRotate(xyz(0,0,-1),-150,false);
	//MenuExit.SetVisible(true);

	LogoDeltaWave.InitText("  elta\n  wave",Trngl(9,0)->Vertex3(),0.07,false,COLOR_WHITE,HA_LEFT,VA_BOTTOM);
	LogoDeltaWave.SetRotate(xyz(0,0,-1),-150,false);
	//LogoDeltaWave.SetVisible(true);


	//globalview.SetViewTranslateByCoords(Trngl(9,0)->GetTrueCenter().x,Trngl(9,0)->GetTrueCenter().y,-1.4);//menu point of view
	//globalview.SetViewRotateByCoords(0,0,-1,150);
	//globalview.SetAniTranslateToByCoords(Trngl(9,0)->GetTrueCenter().x-2.2,Trngl(9,0)->GetTrueCenter().y-3.5,-1.4,-1,3000);//point for game menu
	//globalview.SetAniTranslateToByCoords(11.8,0,-1.4,-1,3000);//point for about menu

	//globalview.SetAniRotateToByCoords(0,0,-1,30,-1,1000);
	return true;
}

bool CParts::InvertTriangles()
{
	int i,j;
	for(i=0;i<arrwidth;i++)
		for(j=0;j<arrheight;j++)
			trianglearr[i][j].InvertRotate();
	return true;
}

bool CParts::DrawAll()
{
	int i,j;
//	COORDS crds;
	JumpCount.Draw();
	globalview.ProcessView();
	for(i=0;i<arrwidth;i++)
		for(j=0;j<arrheight;j++)
		{
			trianglearr[i][j].Draw();
			textarr[i][j].Draw();					
		}
	MenuGame.Draw();
	MenuAbout.Draw();
	MenuExit.Draw();
	StartDigitLable.Draw();
	StartDigit.Draw();
	FinDigitLable.Draw();
	FinDigit.Draw();
	MenuGo.Draw();
	LogoDeltaWave.Draw();
	AboutBlahBlah.Draw();
	GMJumpCount.Draw();
	GMJumpCountLable.Draw();
	return true;
}
