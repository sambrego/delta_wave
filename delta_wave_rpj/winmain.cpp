//winmain.cpp
#include "stdafx.h"

 // ���������� ����������
HINSTANCE hInstance;
HWND hWndMain;

// ��������������� ���������� ����������
 const char * szAppName = "Demo";

// WinMain
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
  hInstance = hInst;
  // ������� ���� �������� ����������
  hWndMain = CreateMainWindow("Delta-Wave",640,480,nCmdShow,true,true);
  if(!hWndMain)
    return 0;
  // �������������
  if(!Init(hWndMain))
    return 0;
  // ��������� ���� ��������� ���������
  int nRet = Run();
  // ������������ ��������
  ReleaseAll();
  return nRet;
}

// �������������
int Init(HWND hWndMain)
{
	InitOpenGL(hWndMain);
	return 1;
}

// ������������ ������� ��������
void ReleaseAll()
{
	ReleaseOpenGL();
}

// �������, ������������ ��� ������ ������� ���������
void OnIdle()
{
	DrawFrame();
}


// ��������� ��������� �������� ���� ����������
LRESULT WINAPI MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
CInterface globalinterface;
  switch( msg )
  {
	case WM_ACTIVATE:
		if(wParam==WA_ACTIVE)globalinterface.InitMouseMode();
		else if(wParam==WA_INACTIVE)globalinterface.DeInitMouseMode();
		break;
    case WM_LBUTTONDOWN:
		globalinterface.WasLeftClick();
      break;
	case WM_RBUTTONDOWN:
		globalinterface.WasRightClick();
      break;
	case WM_KEYDOWN:
		globalinterface.WasKeyPressed((char)wParam);
      break;
    case WM_SIZE:
      break;
    case WM_DESTROY:
      PostQuitMessage( 0 );
      return 0;
  }
  return CallWindowProc( (WNDPROC)DefWindowProc, hWnd, msg, wParam, lParam );
}

// �������� �������� ���� ����������.
HWND CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight,
                      int nCmdShow, bool bIsOpenGL, bool bIsFullscreen)
{
  WNDCLASS wndclass;
  int c_left,c_top,c_width,c_height;
  
  // ������������ ����� ����
  wndclass.style         = 0;
  wndclass.lpfnWndProc   = (WNDPROC)MainWndProc;
  wndclass.cbClsExtra    = 0;
  wndclass.cbWndExtra    = 0;
  wndclass.hInstance     = hInstance;
  wndclass.hIcon         = LoadIcon (hInstance, szAppName);
  wndclass.hCursor       = LoadCursor (NULL,IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
  wndclass.lpszMenuName  = szAppName;
  wndclass.lpszClassName = szAppName;

  if(!RegisterClass(&wndclass))
    return 0;

    if(!bIsFullscreen){
	  c_left = (GetSystemMetrics(SM_CXSCREEN)-nWidth)/2;
	  c_top = (GetSystemMetrics(SM_CYSCREEN)-nHeight)/2;
	  c_width = nWidth;
	  c_height = nHeight;
  }else{
	  c_left = 0;
	  c_top = 0;
	  c_width = GetSystemMetrics(SM_CXSCREEN);
	  c_height = GetSystemMetrics(SM_CYSCREEN);
  }

  //if(bIsOpenGL)
    //dwStyle |= WS_EX_TOPMOST|WS_DLGFRAME;

  // ������� ����
  HWND hWnd = CreateWindowEx(/*WS_EX_TOPMOST*/0, szAppName, pWindowName, WS_POPUP, c_left, c_top,
                        c_width,
						c_height,
                        0, 0,         
                        hInstance, NULL);
	  /*CreateWindow(szAppName, pWindowName, WS_OVERLAPPED | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
                      c_left,
                      c_top,
                      c_width, c_height,
                      0, 0, hInstance, NULL);*/
  if(hWnd)
  {
    // ������ ���� �������
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
  }
  
  return hWnd;
}

// ���������� ���������
int Run()
{
  MSG msg={0};

  while(msg.message!=WM_QUIT)
  {
    if(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
    {
      if(GetMessage(&msg, NULL, 0, 0))
      {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }
    else
      OnIdle();
  }
  return msg.wParam;
}