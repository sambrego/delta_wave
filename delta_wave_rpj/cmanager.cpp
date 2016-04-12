//cmanager.cpp
#include "stdafx.h"
bool CStateManager::InitAll(CParts* parts,CSolve* solve)
{
	SetActiveState(&IntroLogoState);
	MainMenuGameState.Init(this,parts);
	MainMenuAboutState.Init(this,parts);
	MainMenuExitState.Init(this,parts);
	IntroLogoState.Init(this,parts);
	OutroLogoState.Init(this,parts);
	AboutMenuState.Init(this,parts);
	GameMenuGameState.Init(this,parts);
	GameMenuStartState.Init(this,parts);
	GameMenuFinishState.Init(this,parts);
	GameMenuGoState.Init(this,parts);
	GameState.Init(this,parts);
	GameMenuStartState.SetStartDigit(1);
	GameMenuFinishState.SetFinishDigit(10);

	GameMenuGameState.InitSolve(solve);
	GameMenuStartState.InitSolve(solve);
	GameMenuFinishState.InitSolve(solve);
	GameMenuGoState.InitSolve(solve);
	GameState.InitSolve(solve);
	return true;
}
bool CStateManager::Process()
{
	return CurrentState->Process();
}
bool CStateManager::SetActiveState(CState* state)
{
	CurrentState = state;
	return true;
}