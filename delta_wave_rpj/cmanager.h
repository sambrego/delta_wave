//cmanager.h
class CStateManager{
public:
	CState* CurrentState;
	CTimer globaltimer;
	CInterface globalinterface;
	CMainMenuGameState MainMenuGameState;
	CMainMenuAboutState MainMenuAboutState;
	CMainMenuExitState MainMenuExitState;
	CIntroLogoState IntroLogoState;
	COutroLogoState OutroLogoState;
	CAboutMenuState AboutMenuState;
	CGameMenuGameState GameMenuGameState;
	CGameMenuStartState GameMenuStartState;
	CGameMenuFinishState GameMenuFinishState;
	CGameMenuGoState GameMenuGoState;
	CGameState GameState;
	bool InitAll(CParts* parts,CSolve* solve);
	bool Process();
	bool SetActiveState(CState* state);
};
