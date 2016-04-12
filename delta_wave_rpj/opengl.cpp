//opengl.cpp
#include "stdafx.h"

int InitPixelFormat(HDC hdc);
void InitSettings();

HWND hWnd;
HDC   hDC;
HGLRC hRC;

CTriangle triangle;
CTriangle triangle2;
CText text1,text2,text3;
COORDS shift;
CParts parts(FIELD_WIDTH,FIELD_HEIGHT);
CSolve solve(FIELD_WIDTH,FIELD_HEIGHT,FIELD_WCENTER,FIELD_HCENTER);
CStateManager StateManager;


int InitOpenGL(HWND _hWnd)
{
  hWnd = _hWnd;
  hDC = GetDC(hWnd);
  if(!InitPixelFormat(hDC))
    return 0;

  hRC = wglCreateContext(hDC);
  wglMakeCurrent(hDC, hRC);
	
  InitSettings();
  return 1;
}

void InitSettings()
{
	CAniView globalview;
	CInterface globalinterface;
	CTimer globaltimer;
	globaltimer.RefreshTime();
	globaltimer.RefreshTime();
	
	//gluPerspective (60, (float)4/3,
      //               0, 1);
	glViewport(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)GetSystemMetrics(SM_CXSCREEN)/GetSystemMetrics(SM_CYSCREEN),
		0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	shift.x=0;shift.y=0;shift.z=-1.4;
	//globalview.SetViewTranslateByCoords(0,0,-1);

	//globalview.SetViewRotateByCoords(0,0,1,30);
	//globalview.SetAniTranslateToByCoords(-1,-1,-3,-1000,500);
	//globalview.SetAniRotateToByCoords(0,0,1,90,-1000,5000);

	COORDS crds;
	crds.x=0;crds.y = 0.25*0.25;crds.z=0;
	triangle.SetParams(crds,false,(float)0.25);
	triangle.SetColor(COLOR_BLACK_BLUE,COLOR_BLACK_BLUE,COLOR_COBALT);
	//globalview.SetAniTranslateToByCoords(-1.3,0,-1,-1,500);
	
	crds.x=0+((float)0.866/2);crds.y = 0;crds.z=0;
	triangle2.SetParams(crds,true,(float)0.45);
	//triangle2.SetAniColor(COLOR_BLACK,COLOR_BLACK_BLUE,COLOR_COBALT,-2000,2000);
	//text.SetRotate(vcrds,90,false);
	crds.x=0;crds.y = -0.2;crds.z=-1;
	text1.InitText("",crds,(float)0.02,false,COLOR_WHITE,HA_CENTER,VA_TOP);
	crds.x=0;crds.y= 0;crds.z=-1;
	text2.InitText("",crds,(float)0.02,false,COLOR_WHITE,HA_CENTER,VA_BOTTOM);
	text3.InitText("",crds,(float)0.02,false,COLOR_WHITE,HA_CENTER,VA_TOP);
	parts.InitStartState();
	StateManager.InitAll(&parts,&solve);
/*	crds.x=0;crds.y = 0;crds.z=1;
	text1.SetRotate(crds,-30,false);
	text2.SetRotate(crds,90,false);
	text3.SetRotate(crds,210,false);*/
	globalinterface.InitMouseMode();
	globalinterface.SetMouseSensivity(0.3,0.3); 
}

void ReleaseOpenGL()
{
  if(hRC)
  {
    wglMakeCurrent(hDC, 0);
    wglDeleteContext(hRC);
    hRC = 0;
  }
  if(hDC)
  {
    ReleaseDC(hWnd, hDC);
    hDC = 0;
  }
}

int InitPixelFormat(HDC hdc)
{
  int pixelformat;
  PIXELFORMATDESCRIPTOR pfd = {0};

  pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 32;

  if (!(pixelformat = ChoosePixelFormat(hdc, &pfd)))
  {
    //Error: ChoosePixelFormat failed
    return 0;
  }

  if(!SetPixelFormat(hdc, pixelformat, &pfd))
  {
    //Error: SetPixelFormat failed"
    return 0;
  }

  return 1;
}

void DrawObjects()
{
	CInterface globalinterface;
	CTimer globaltimer;
	CAniView globalview;


	globalview.ProcessView();
	glColor3f(1,1,1);



	//glPushMatrix();
	//glRotated(45,1,1,0);
	//glRotated(0.5,1,0,0);
	//glRotated(0.5,0,1,0);

	globaltimer.RefreshTime();
	globalinterface.RefreshActions();
	StateManager.Process();
	parts.DrawAll();

	/*	glBegin(GL_LINES);
	glVertex3d(-0.5,-0.5,0);
	glVertex3d(0.5,-0.5,0);

	glVertex3d(0.5,-0.5,0);
	glVertex3d(0.5,0.5,0);

	glVertex3d(0.5,0.5,0);
	glVertex3d(-0.5,0.5,0);

	glVertex3d(-0.5,0.5,0);
	glVertex3d(-0.5,-0.5,0);

	glVertex3d(0,-1,0);
	glVertex3d(0,1,0);
	
	glVertex3d(-1,0,0);
	glVertex3d(1,0,0);
	glEnd();*/

	//triangle.Draw();
	//triangle2.Draw();
	glColor3f(1,1,1);
	//auxSolidSphere(0.1);
	//glPopMatrix();
	
/*	switch(globalinterface.GetLastAction())
		{
			case ACTION_UP:
				shift.y+=0.1;
				globalview.SetViewTranslateByCoords(shift.x,shift.y,shift.z);
				break;
			case ACTION_DOWN:
				shift.y-=0.1;
				globalview.SetViewTranslateByCoords(shift.x,shift.y,shift.z);
				break;
			case ACTION_LEFT:
				shift.x-=0.1;
				globalview.SetViewTranslateByCoords(shift.x,shift.y,shift.z);
				break;
			case ACTION_RIGHT:
				shift.x+=0.1;
				globalview.SetViewTranslateByCoords(shift.x,shift.y,shift.z);
				break;
			case ACTION_OK:
				shift.z+=0.1;
				//globalview.SetViewTranslateAdditive(shift.x,shift.y,shift.z);
				break;
			case ACTION_CANCEL:
				shift.z-=0.1;
				//globalview.SetViewTranslateAdditive(shift.x,shift.y,shift.z);
				//parts.InvertTriangles();
				break;
		}
	glLoadIdentity();
	text1.SetLongIntAsText(shift.x*10);
	text2.SetLongIntAsText(shift.y*10);
	text3.SetLongIntAsText(shift.z*10);
	text1.Draw();
	text2.Draw();
	text3.Draw();*/
}

void DrawFrame()
{
  glClear(GL_COLOR_BUFFER_BIT);
  DrawObjects();
  SwapBuffers(hDC);
}