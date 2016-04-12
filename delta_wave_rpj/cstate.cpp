//cstate.cpp
#include "stdafx.h"
bool CState::Process(){
	switch(CurrentStep)
	{
	case STEP_NONE:
		StartUp();
		break;
	case STEP_STARTING:
		Timer = Timer+StateManager->globaltimer.TicksTillPrevRefresh();
		if(Timer>=ProcBegin)
		{
			CurrentStep=STEP_PROCESSING;
			Timer=ProcBegin;
			OnProcessBegan();
		}
		break;
	case STEP_PROCESSING:
		if(EndProcOnTimer)
		{
			Timer = Timer+StateManager->globaltimer.TicksTillPrevRefresh();
			if(Timer>=ProcEnd)EndUp(StateChangeOnFinish);
			break;
		}
		OnProcess();
		ProcessActions();
		break;
	case STEP_FINISHING:
			Timer = Timer+StateManager->globaltimer.TicksTillPrevRefresh();
			if(Timer>=TotalFinish)
			{
				CurrentStep=STEP_NONE;
				Timer=TotalFinish;
				OnFinish();
				StateManager->SetActiveState(StateChangeOnFinish);
			}
		break;
	}
	return true;
}
bool CState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	StateManager = StateManager_new;
	Parts = Parts_new;
	Timer = 0;
	CurrentStep = STEP_NONE;
	StateChangeOnFinish = this;
	return true;
}
bool CState::StartUp()
{
	Timer = 0;
	CurrentStep = STEP_STARTING;
	StateManager->CurrentState = this;
	OnStartUp();
	return true;
}
bool CState::EndUp(CState* StartAfterFinish){
	Timer = ProcEnd;
	CurrentStep = STEP_FINISHING;
	this->OnEndUp();
	StateChangeOnFinish = StartAfterFinish;
	return true;
}

bool CState::ProcessActions()
{
	switch(StateManager->globalinterface.GetLastAction())
	{
	case ACTION_OK:
		this->OnOkAction();
		break;
	case ACTION_CANCEL:
		this->OnCancelAction();
		break;
	case ACTION_LEFT:
		this->OnLeftAction();
		break;
	case ACTION_RIGHT:
		this->OnRightAction();
		break;
	case ACTION_UP:
		this->OnUpAction();
		break;
	case ACTION_DOWN:
		this->OnDownAction();
		break;
	}
	return true;
}

bool CState::OnUpAction(){return true;}
bool CState::OnDownAction(){return true;}
bool CState::OnLeftAction(){return true;}
bool CState::OnRightAction(){return true;}
bool CState::OnOkAction(){return true;}
bool CState::OnCancelAction(){return true;}
bool CState::OnProcess(){return true;}
bool CState::OnStartUp(){return true;}
bool CState::OnEndUp(){return true;}
bool CState::OnFinish(){return true;}
bool CState::OnProcessBegan(){return true;}