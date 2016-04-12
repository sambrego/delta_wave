//intrface.h
enum ACTION{ACTION_NO,ACTION_UP,ACTION_DOWN,ACTION_RIGHT,ACTION_LEFT,ACTION_CANCEL,ACTION_OK};
class CInterface{
public:
	bool InitMouseMode();
	bool DeInitMouseMode();
	bool IsInitMouseMode();
	bool SetMouseSensivity(float xsens_new,float ysens_new);
	ACTION GetLastAction();
	bool RefreshActions();
private:
	friend LRESULT WINAPI MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	bool WasLeftClick();
	bool WasRightClick();
	bool WasKeyPressed(char KeyPressed);

	static ACTION LastAction;
	static bool bIsInitMouseMode;
	static float xsens,ysens;
	static int x, y;
	static bool bWasLeftClick;
	static bool bWasRightClick;

	static bool bWasKeyPressed;
	static char key;
};

