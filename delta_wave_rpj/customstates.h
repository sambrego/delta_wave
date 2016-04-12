//customstates.h
class CStateManager;
class CMainMenuState:public CState{
public:
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
protected:
	virtual bool OnStartUp();
	virtual bool OnProcessBegan();
	virtual bool OnCancelAction();
private:
};

class CMainMenuGameState:public CMainMenuState{
public:
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnOkAction();
private:
};

class CMainMenuAboutState:public CMainMenuState{
public:
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnOkAction();
private:
};

class CMainMenuExitState:public CMainMenuState{
public:
protected:
	virtual bool OnStartUp();
	virtual bool OnOkAction();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
private:
};

class CDeltaLogoState:public CState{
public:
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
protected:
	virtual bool OnStartUp();
	virtual bool OnProcessBegan();
private:
};

class CIntroLogoState:public CDeltaLogoState{
public:
protected:
	virtual bool OnStartUp();
private:
};

class COutroLogoState:public CDeltaLogoState{
public:
protected:
	virtual bool OnEndUp();
	virtual bool OnFinish();
private:
};

class CAboutMenuState:public CState{
public:
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
protected:	
	virtual bool OnStartUp();
	virtual bool OnProcessBegan();
	virtual bool OnOkAction();
	virtual bool OnCancelAction();
private:
};

//Game Menu State
class CGameMenuState:public CState{
public:
	virtual bool InitSolve(CSolve* solve_new);
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
protected:	
	virtual bool OnStartUp();
	virtual bool OnProcessBegan();
	virtual bool OnCancelAction();
	bool SetResultsVisiblity();
	CSolve* solve;
};
class CGameMenuGameState:public CGameMenuState{
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnOkAction();
};
class CGameMenuStartState:public CGameMenuState{
public:
	TDigit GetStartDigit();
	bool SetStartDigit(TDigit newdigit);
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnLeftAction();
	virtual bool OnRightAction();
	TDigit StartDigit;
};
class CGameMenuFinishState:public CGameMenuState{
public:
	TDigit GetFinishDigit();
	bool SetFinishDigit(TDigit newdigit);
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnLeftAction();
	virtual bool OnRightAction();
	TDigit FinishDigit;
};
class CGameMenuGoState:public CGameMenuState{
protected:
	virtual bool OnStartUp();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnOkAction();
};
//Game State
class CGameState: public CState{
public:
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
	virtual bool InitSolve(CSolve* solve_new);
protected:
	virtual bool OnStartUp();
	virtual bool OnProcess();
	virtual bool OnProcessBegan();
	virtual bool OnCancelAction();
	virtual bool OnEndUp();
	virtual bool OnFinish();
	bool HideNulls();
	bool FillUpText();
	bool FillUpTriangles(JUMP_DIR direction);
	bool SetCameraTranslate(JUMP_DIR jump);
	bool SetCameraRotate(JUMP_DIR jump);
	CSolve* solve;
	CAniColor BaseColor;
	bool FirstStep;
};