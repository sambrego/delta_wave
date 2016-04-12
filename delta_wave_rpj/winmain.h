// Объявление функций
int Init(HWND hWndMain);
void ReleaseAll();
void OnIdle();
int Run();
HWND CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight,
                      int nCmdShow=SW_NORMAL, bool bIsOpenGL=false,bool bIsFullscreen=false);
int InitOpenGL();