//customstates.cpp
#include "stdafx.h"

//----------------==Main Menu States==----------------------

//CMainMenuState
const int MAIN_MENU_STARTING_TIME=400;
bool CMainMenuState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	CState::Init(StateManager_new,Parts_new);
	ProcBegin = MAIN_MENU_STARTING_TIME;
	ProcEnd = ProcBegin + 1000;
	TotalFinish = ProcEnd;
	EndProcOnTimer = false;
	return true;
}
bool CMainMenuState::OnStartUp()
{
	Parts->SetFadeAll(MAIN_MENU_STARTING_TIME);

	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuGame.SetVisible(true);
	Parts->MenuAbout.SetVisible(true);
	Parts->MenuExit.SetVisible(true);
	Parts->Trngl(9,0)->SetAniColor(COLOR_DARK_BLUE,COLOR_DARK_BLUE,COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuGame.color.SetAniTo(COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuExit.color.SetAniTo(COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuAbout.color.SetAniTo(COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->globalview.SetAniTranslateToByCoords(Parts->Trngl(9,0)->GetTrueCenter().x,Parts->Trngl(9,0)->GetTrueCenter().y,-1.4,-1,MAIN_MENU_STARTING_TIME);
	return true;
}
bool CMainMenuState::OnProcessBegan()
{
	Parts->SetInvisibleAll();
	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuGame.SetVisible(true);
	Parts->MenuAbout.SetVisible(true);
	Parts->MenuExit.SetVisible(true);
	return true;
}
bool CMainMenuState::OnCancelAction()
{
	EndUp(&(StateManager->MainMenuExitState));
	return true;
}
//end of CMainMenuState

//CMainMenuGameState
bool CMainMenuGameState::OnStartUp()
{
	CMainMenuState::OnStartUp();
	Parts->Trngl(9,0)->SetAniColor(COLOR_DARK_BLUE,COLOR_COBALT,COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuGame.color.SetAniTo(COLOR_COBALT,-1,MAIN_MENU_STARTING_TIME);
	Parts->globalview.SetAniRotateToByCoords(0,0,-1,-90,-1,MAIN_MENU_STARTING_TIME);
	return true;
}
bool CMainMenuGameState::OnDownAction()
{
	EndUp(&(StateManager->MainMenuAboutState));
	return true;
}
bool CMainMenuGameState::OnUpAction()
{
	Parts->globalview.SetViewRotateByCoords(0,0,-1,270);
	EndUp(&(StateManager->MainMenuExitState));
	return true;
}

bool CMainMenuGameState::OnOkAction()
{
	EndUp(&(StateManager->GameMenuGoState));
	return true;
}
//end of CMainMenuGameState

//CMainMenuAboutState
bool CMainMenuAboutState::OnStartUp()
{
	CMainMenuState::OnStartUp();
	Parts->Trngl(9,0)->SetAniColor(COLOR_DARK_BLUE,COLOR_DARK_BLUE,COLOR_COBALT,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuAbout.color.SetAniTo(COLOR_COBALT,-1,MAIN_MENU_STARTING_TIME);
	Parts->globalview.SetAniRotateToByCoords(0,0,-1,30,-1,MAIN_MENU_STARTING_TIME);
	return true;
}
bool CMainMenuAboutState::OnDownAction()
{
	EndUp(&(StateManager->MainMenuExitState));
	return true;
}
bool CMainMenuAboutState::OnUpAction()
{
	EndUp(&(StateManager->MainMenuGameState));
	return true;
}
bool CMainMenuAboutState::OnOkAction()
{
	EndUp(&(StateManager->AboutMenuState));
	return true;
}
//end of CMainMenuAboutState

//CMainMenuExitState
bool CMainMenuExitState::OnStartUp()
{
	CMainMenuState::OnStartUp();
	Parts->Trngl(9,0)->SetAniColor(COLOR_COBALT,COLOR_DARK_BLUE,COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuExit.color.SetAniTo(COLOR_COBALT,-1,MAIN_MENU_STARTING_TIME);
	Parts->globalview.SetAniRotateToByCoords(0,0,-1,150,-1,MAIN_MENU_STARTING_TIME);
	return true;
}
bool CMainMenuExitState::OnOkAction()
{
	EndUp(&(StateManager->OutroLogoState));
	return true;
}
bool CMainMenuExitState::OnDownAction()
{
	Parts->globalview.SetViewRotateByCoords(0,0,-1,-210);
	EndUp(&(StateManager->MainMenuGameState));
	return true;
}
bool CMainMenuExitState::OnUpAction()
{
	EndUp(&(StateManager->MainMenuAboutState));
	return true;
}
//end of CMainMenuExitState

//----------------==Delta Logo States==----------------------

//CDeltaLogoState
const int LOGO_STARTING_TIME=400;
bool CDeltaLogoState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	CState::Init(StateManager_new,Parts_new);
	ProcBegin = LOGO_STARTING_TIME;
	ProcEnd = ProcBegin + 1000;
	TotalFinish = ProcEnd + 1000;
	EndProcOnTimer = true;
	return true;
}
bool CDeltaLogoState::OnStartUp()
{
	Parts->SetFadeAll(LOGO_STARTING_TIME);
	Parts->Trngl(9,0)->SetVisible(true);
	Parts->LogoDeltaWave.SetVisible(true);
	Parts->Trngl(9,0)->SetAniColor(COLOR_COBALT,COLOR_COBALT,COLOR_COBALT,-1,LOGO_STARTING_TIME);
	Parts->LogoDeltaWave.color.SetAniTo(COLOR_COBALT,-1,LOGO_STARTING_TIME);
	Parts->globalview.SetAniTranslateToByCoords(Parts->Trngl(9,0)->GetTrueCenter().x,Parts->Trngl(9,0)->GetTrueCenter().y,-1.4,-1,LOGO_STARTING_TIME);
	Parts->globalview.SetViewRotateByCoords(0,0,-1,150);
	return true;
}
bool CDeltaLogoState::OnProcessBegan()
{
	Parts->SetInvisibleAll();
	Parts->Trngl(9,0)->SetVisible(true);
	Parts->LogoDeltaWave.SetVisible(true);
	return true;
}
//end of CDeltaLogoState

//CIntroLogoState
bool CIntroLogoState::OnStartUp()
{
		CDeltaLogoState::OnStartUp();
		StateChangeOnFinish = &(StateManager->MainMenuGameState);
		return true;
}
//end of CIntroLogoState

//COutroLogoState
bool COutroLogoState::OnEndUp()
{
	Parts->SetFadeAll(1000);
	return true;
}
bool COutroLogoState::OnFinish()
{
	PostQuitMessage(0);
	return true;
}
//end of COutroLogoState

//----------------==About State==----------------------
const int ABOUT_MENU_STARTING_TIME=400;
bool CAboutMenuState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	CState::Init(StateManager_new,Parts_new);
	ProcBegin = ABOUT_MENU_STARTING_TIME;
	ProcEnd = ProcBegin + 1000;
	TotalFinish = ProcEnd;
	EndProcOnTimer = false;
	return true;
}
bool CAboutMenuState::OnStartUp()
{
	Parts->SetFadeAll(ABOUT_MENU_STARTING_TIME);

	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuAbout.SetVisible(true);
	Parts->AboutBlahBlah.SetVisible(true);
	Parts->Trngl(9,0)->SetAniColor(COLOR_DARK_BLUE,COLOR_DARK_BLUE,COLOR_COBALT,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuAbout.color.SetAniTo(COLOR_COBALT,-1,ABOUT_MENU_STARTING_TIME);
	Parts->AboutBlahBlah.color.SetAniTo(COLOR_COBALT,-1,ABOUT_MENU_STARTING_TIME);
	Parts->globalview.SetAniRotateToByCoords(0,0,-1,30,-1,ABOUT_MENU_STARTING_TIME);
	Parts->globalview.SetAniTranslateToByCoords(11.8,0,-1.4,-1,ABOUT_MENU_STARTING_TIME);
	return true;
}
bool CAboutMenuState::OnProcessBegan()
{
	Parts->SetInvisibleAll();
	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuAbout.SetVisible(true);
	Parts->AboutBlahBlah.SetVisible(true);
	return true;
}
bool CAboutMenuState::OnOkAction()
{
	EndUp(&(StateManager->MainMenuAboutState));
	return true;
}
bool CAboutMenuState::OnCancelAction()
{
	EndUp(&(StateManager->MainMenuAboutState));
	return true;
}
//----------------==Game Menu States==----------------------
const int GAME_MENU_STARTING_TIME=400;
bool CGameMenuState::InitSolve(CSolve* solve_new)
{
	solve = solve_new;
	return true;
}
bool CGameMenuState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	CState::Init(StateManager_new,Parts_new);
	ProcBegin = GAME_MENU_STARTING_TIME;
	ProcEnd = ProcBegin + 1000;
	TotalFinish = ProcEnd;
	EndProcOnTimer = false;
	return true;
}
bool CGameMenuState::OnStartUp()
{
	Parts->SetFadeAll(GAME_MENU_STARTING_TIME);

	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuGame.SetVisible(true);
	Parts->MenuGo.SetVisible(true);
	Parts->StartDigit.SetVisible(true);
	Parts->StartDigitLable.SetVisible(true);
	Parts->FinDigitLable.SetVisible(true);
	Parts->FinDigit.SetVisible(true);
	Parts->GMJumpCountLable.SetVisible(true);
	Parts->GMJumpCount.SetVisible(true);
	

	Parts->Trngl(9,0)->SetAniColor(COLOR_DARK_BLUE,COLOR_COBALT,COLOR_DARK_BLUE,-1,MAIN_MENU_STARTING_TIME);
	Parts->MenuGame.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->MenuGo.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->StartDigit.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->StartDigitLable.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->FinDigitLable.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->FinDigit.color.SetAniTo(COLOR_DARK_BLUE,-1,GAME_MENU_STARTING_TIME);
	Parts->StartDigit.SetLongIntAsText(StateManager->GameMenuStartState.GetStartDigit());
	Parts->FinDigit.SetLongIntAsText(StateManager->GameMenuFinishState.GetFinishDigit());
	SetResultsVisiblity();

	Parts->globalview.SetAniRotateToByCoords(0,0,-1,-90,-1,GAME_MENU_STARTING_TIME);
	Parts->globalview.SetAniTranslateToByCoords(Parts->Trngl(9,0)->GetTrueCenter().x-2.2,Parts->Trngl(9,0)->GetTrueCenter().y-3.5,-1.4,-1,GAME_MENU_STARTING_TIME);
	return true;
}
bool CGameMenuState::OnProcessBegan()
{
	Parts->SetInvisibleAll();
	Parts->Trngl(9,0)->SetVisible(true);
	Parts->MenuGame.SetVisible(true);
	Parts->MenuGo.SetVisible(true);
	Parts->StartDigit.SetVisible(true);
	Parts->StartDigitLable.SetVisible(true);
	Parts->FinDigitLable.SetVisible(true);
	Parts->FinDigit.SetVisible(true);
	//if(solve->IsFinish()){
	Parts->GMJumpCountLable.SetVisible(true);
	Parts->GMJumpCount.SetVisible(true);
	//}
	return true;
}
bool CGameMenuState::OnCancelAction()
{
	EndUp(&(StateManager->MainMenuGameState));
	return true;
}
bool CGameMenuState::SetResultsVisiblity()
{
	if((solve->IsFinish())&&(StateManager->GameMenuStartState.GetStartDigit()==(solve->GetStartTerm()))&&(StateManager->GameMenuFinishState.GetFinishDigit()==solve->GetFinishTerm())){
		Parts->GMJumpCount.color.SetAniTo(COLOR_MIDDLE_BLUE,-1,GAME_MENU_STARTING_TIME);
		Parts->GMJumpCountLable.color.SetAniTo(COLOR_MIDDLE_BLUE,-1,GAME_MENU_STARTING_TIME);	
	}else{
		Parts->GMJumpCount.color.SetAniTo(COLOR_BLACK,-1,GAME_MENU_STARTING_TIME);
		Parts->GMJumpCountLable.color.SetAniTo(COLOR_BLACK,-1,GAME_MENU_STARTING_TIME);	
	}
	return true;
}
//GameMenuGameState-----------
bool CGameMenuGameState::OnStartUp()
{
	CGameMenuState::OnStartUp();
	Parts->MenuGame.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	return true;
}
bool CGameMenuGameState::OnUpAction()
{
	//EndUp(&(StateManager->GameMenuGoState));
	return true;
}
bool CGameMenuGameState::OnDownAction()
{
	EndUp(&(StateManager->GameMenuStartState));
	return true;
}
bool CGameMenuGameState::OnOkAction()
{
	EndUp(&(StateManager->MainMenuGameState));
	return true;
}
//GameMenuStartState-----------
TDigit CGameMenuStartState::GetStartDigit()
{
	return StartDigit;
}
bool CGameMenuStartState::SetStartDigit(TDigit newdigit)
{
	if(newdigit<1)return false;
	StartDigit = newdigit;
	return true;
}
bool CGameMenuStartState::OnStartUp()
{
	CGameMenuState::OnStartUp();
	Parts->StartDigit.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	Parts->StartDigitLable.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	return true;
}
bool CGameMenuStartState::OnUpAction()
{
	EndUp(&(StateManager->GameMenuGameState));
	return true;
}
bool CGameMenuStartState::OnDownAction()
{
	EndUp(&(StateManager->GameMenuFinishState));
	return true;
}
bool CGameMenuStartState::OnLeftAction()
{
	SetStartDigit(GetStartDigit()-1);
	Parts->StartDigit.SetLongIntAsText(GetStartDigit());
	SetResultsVisiblity();
	return true;
}
bool CGameMenuStartState::OnRightAction()
{
	SetStartDigit(GetStartDigit()+1);
	Parts->StartDigit.SetLongIntAsText(GetStartDigit());
	SetResultsVisiblity();
	return true;
}
//GameMenuFinishState-----------
TDigit CGameMenuFinishState::GetFinishDigit()
{
	return FinishDigit;
}
bool CGameMenuFinishState::SetFinishDigit(TDigit newdigit)
{
	if(newdigit<1)return false;
	FinishDigit = newdigit;
	return true;
}
bool CGameMenuFinishState::OnStartUp()
{
	CGameMenuState::OnStartUp();
	Parts->FinDigit.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	Parts->FinDigitLable.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	return true;
}
bool CGameMenuFinishState::OnUpAction()
{
	EndUp(&(StateManager->GameMenuStartState));
	return true;
}
bool CGameMenuFinishState::OnDownAction()
{
	EndUp(&(StateManager->GameMenuGoState));
	return true;
}
bool CGameMenuFinishState::OnLeftAction()
{
	SetFinishDigit(GetFinishDigit()-1);
	Parts->FinDigit.SetLongIntAsText(GetFinishDigit());
	SetResultsVisiblity();
	return true;
}
bool CGameMenuFinishState::OnRightAction()
{
	SetFinishDigit(GetFinishDigit()+1);
	Parts->FinDigit.SetLongIntAsText(GetFinishDigit());
	SetResultsVisiblity();
	return true;
}
//GameMenuGoState-----------
bool CGameMenuGoState::OnStartUp()
{
	CGameMenuState::OnStartUp();
	Parts->MenuGo.color.SetAniTo(COLOR_COBALT,-1,GAME_MENU_STARTING_TIME);
	return true;
}
bool CGameMenuGoState::OnUpAction()
{
	EndUp(&(StateManager->GameMenuFinishState));
	return true;
}
bool CGameMenuGoState::OnDownAction()
{
	//EndUp(&(StateManager->GameMenuGoState));
	return true;
}
bool CGameMenuGoState::OnOkAction()
{
	EndUp(&(StateManager->GameState));
	return true;
}

//----------------==Game State==----------------------
const int GAME_STARTING_TIME=3000;
const int JUMP_TIME=3000;
const int FADE_TIME=3000;
const int RISE_TIME=100;
const int CAMERA_Z=-2;
bool CGameState::Init(CStateManager* StateManager_new,CParts* Parts_new)
{
	CState::Init(StateManager_new,Parts_new);
	ProcBegin = GAME_STARTING_TIME;
	ProcEnd = ProcBegin + 1000;
	TotalFinish = ProcEnd+3500;
	EndProcOnTimer = false;
	BaseColor.SetColor(COLOR_DARK_BLUE);
	return true;
}
bool CGameState::InitSolve(CSolve* solve_new)
{
	solve = solve_new;
	return true;
}

bool CGameState::OnStartUp()
{
	int i,j;
	solve->InitTerms(StateManager->GameMenuStartState.GetStartDigit(),StateManager->GameMenuFinishState.GetFinishDigit());

	if((StateManager->GameMenuStartState.GetStartDigit()-((int)sqrt(StateManager->GameMenuStartState.GetStartDigit()-1)+1 ))%2==1)Parts->InvertTriangles();

	Parts->SetFadeAll(GAME_STARTING_TIME);
	FillUpText();
	for(i=0;i<FIELD_WIDTH;i++)
		for(j=0;j<FIELD_HEIGHT;j++)
			Parts->Trngl(i,j)->SetAniColor(COLOR_DARK_BLUE,COLOR_DARK_BLUE,COLOR_DARK_BLUE,-1,GAME_STARTING_TIME);
		HideNulls();
	Parts->globalview.SetAniTranslateToByStruct(Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->GetCenter(),-1,GAME_STARTING_TIME/2);
	JUMP_DIR q=solve->NextJump();
	SetCameraRotate(solve->NextJump());
	//Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER+5)->SetColor(COLOR_WHITE,COLOR_WHITE,COLOR_WHITE);
	//Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->SetAniColor(COLOR_COBALT,COLOR_COBALT,COLOR_COBALT,-1,GAME_STARTING_TIME);
	//Parts->globalview.SetAniRotateToByCoords(0,0,-1,0,-1,GAME_STARTING_TIME);
	//Parts->globalview.SetAniRotateToByCoords(-1,0,0,45,-1,JUMP_TIME);
	return true;
}

bool CGameState::OnProcessBegan()
{
	Parts->SetInvisibleAll();
	HideNulls();
	FirstStep=true;
	return 0;
}

bool CGameState::OnProcess()
{
	if(!solve->IsFinish())
	{
		if(!Parts->globalview.IsActiveTranslateAni())
		{			
			if(!FirstStep){
				solve->Jump();
				Parts->InvertTriangles();
				//Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->SetAniColor(COLOR_DARK_BLUE,COLOR_DARK_BLUE,COLOR_DARK_BLUE,-1000,FADE_TIME);
				FillUpTriangles(solve->PrevJump());
				FillUpText();
				HideNulls();
				Parts->globalview.SetViewTranslateByStruct(xyz(Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->GetCenter().x,Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->GetCenter().y,CAMERA_Z));
			}else FirstStep=false;
			Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->SetAniColor(COLOR_COBALT,COLOR_COBALT,COLOR_COBALT,-1,RISE_TIME);
			SetCameraTranslate(solve->NextJump());
			SetCameraRotate(solve->NextNextJump());
					
		}
	}else{
		Parts->GMJumpCount.SetLongIntAsText(solve->JumpCount());
		EndUp(&(StateManager->GameMenuGoState));
	}
	return true;
}

bool CGameState::OnEndUp()
{
	Parts->SetFadeAll(4000);
	return true;
}

bool CGameState::OnFinish()
{
	int i;
	i=solve->JumpCount();
	if((i%2)==1)Parts->InvertTriangles();
	if((StateManager->GameMenuStartState.GetStartDigit()-((int)sqrt(StateManager->GameMenuStartState.GetStartDigit()-1)+1 ))%2==1)Parts->InvertTriangles();
	return true;
}

bool CGameState::OnCancelAction()
{
	EndUp(&(StateManager->GameMenuGoState));
	return true;
}

bool CGameState::FillUpText()
{
	int i,j;
	for(i=0;i<FIELD_WIDTH;i++)
		for(j=0;j<FIELD_HEIGHT;j++)
			Parts->Text(i,j)->SetLongIntAsText(solve->GetCell(i,j));
	return true;
}

bool CGameState::FillUpTriangles(JUMP_DIR direction)
{
	int i,j;
	switch(direction)
	{
	case JUMP_LEFT:
		for(i=0;i<FIELD_WIDTH-1;i++)
			for(j=0;j<FIELD_HEIGHT;j++)
			{
				Parts->Trngl(i,j)->v1=Parts->Trngl(i+1,j)->v1;
				Parts->Trngl(i,j)->v2=Parts->Trngl(i+1,j)->v2;
				Parts->Trngl(i,j)->v3=Parts->Trngl(i+1,j)->v3;
			}
		for(j=0;j<FIELD_HEIGHT;j++)
		{
			Parts->Trngl(FIELD_WIDTH-1,j)->v1=BaseColor;
			Parts->Trngl(FIELD_WIDTH-1,j)->v2=BaseColor;
			Parts->Trngl(FIELD_WIDTH-1,j)->v3=BaseColor;
		}
		break;
	case
 JUMP_RIGHT:
		for(i=1;i<FIELD_WIDTH;i++)
			for(j=0;j<FIELD_HEIGHT;j++)
			{
				Parts->Trngl(i,j)->v1=Parts->Trngl(i-1,j)->v1;
				Parts->Trngl(i,j)->v2=Parts->Trngl(i-1,j)->v2;
				Parts->Trngl(i,j)->v3=Parts->Trngl(i-1,j)->v3;
			}
		for(j=0;j<FIELD_HEIGHT;j++)
		{
			Parts->Trngl(0,j)->v1=BaseColor;
			Parts->Trngl(0,j)->v2=BaseColor;
			Parts->Trngl(0,j)->v3=BaseColor;
		}
		break;
	case JUMP_UP:
		for(i=0;i<FIELD_WIDTH;i++)
			for(j=0;j<FIELD_HEIGHT-1;j++)
			{
				Parts->Trngl(i,j)->v1=Parts->Trngl(i,j+1)->v1;
				Parts->Trngl(i,j)->v2=Parts->Trngl(i,j+1)->v2;
				Parts->Trngl(i,j)->v3=Parts->Trngl(i,j+1)->v3;
			}
		for(i=0;i<FIELD_WIDTH;i++)
		{
			Parts->Trngl(i,FIELD_HEIGHT-1)->v1=BaseColor;
			Parts->Trngl(i,FIELD_HEIGHT-1)->v2=BaseColor;
			Parts->Trngl(i,FIELD_HEIGHT-1)->v3=BaseColor;
		}
		break;
	case JUMP_DOWN:
		for(i=0;i<FIELD_WIDTH;i++)
			for(j=1;j<FIELD_HEIGHT;j++)
			{
				Parts->Trngl(i,j)->v1=Parts->Trngl(i,j-1)->v1;
				Parts->Trngl(i,j)->v2=Parts->Trngl(i,j-1)->v2;
				Parts->Trngl(i,j)->v3=Parts->Trngl(i,j-1)->v3;
			}
		for(i=0;i<FIELD_WIDTH;i++)
		{
			Parts->Trngl(i,0)->v1=BaseColor;
			Parts->Trngl(i,0)->v2=BaseColor;
			Parts->Trngl(i,0)->v3=BaseColor;
		}
		break;
	case JUMP_NOT:
		break;
}
	return true;
}

bool CGameState::SetCameraTranslate(JUMP_DIR jump)
{
	switch(jump)
	{
	case JUMP_UP:
		Parts->globalview.SetAniTranslateToByStruct(xyz(Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER-1)->GetCenter().x,Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER-1)->GetCenter().y,CAMERA_Z),-1,JUMP_TIME);
		break;
	case JUMP_DOWN:
		Parts->globalview.SetAniTranslateToByStruct(xyz(Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER+1)->GetCenter().x,Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER+1)->GetCenter().y,CAMERA_Z),-1,JUMP_TIME);
		break;
	case JUMP_LEFT:
		Parts->globalview.SetAniTranslateToByStruct(xyz(Parts->Trngl(FIELD_WCENTER-1,FIELD_HCENTER)->GetCenter().x,Parts->Trngl(FIELD_WCENTER-1,FIELD_HCENTER)->GetCenter().y,CAMERA_Z),-1,JUMP_TIME);
		break;
	case JUMP_RIGHT:
		Parts->globalview.SetAniTranslateToByStruct(xyz(Parts->Trngl(FIELD_WCENTER+1,FIELD_HCENTER)->GetCenter().x,Parts->Trngl(FIELD_WCENTER+1,FIELD_HCENTER)->GetCenter().y,CAMERA_Z),-1,JUMP_TIME);
		break;
	}
	//Parts->globalview.SetAniTranslateToByStruct(Parts->Trngl(FIELD_WCENTER,FIELD_HCENTER)->GetCenter(),-1,JUMP_TIME);
	return true;
}

bool CGameState::SetCameraRotate(JUMP_DIR jump)
{
	switch(jump)
	{
	case JUMP_UP:
		Parts->globalview.SetAniRotateToByCoords(-0.25,0,0,45,-(JUMP_TIME/2),(JUMP_TIME/2));
		break;
	case JUMP_DOWN:
		Parts->globalview.SetAniRotateToByCoords(0,-0.25,-1,180,-(JUMP_TIME/2),(JUMP_TIME/2));
		break;
	case JUMP_LEFT:
		Parts->globalview.SetAniRotateToByCoords(0,0,-1,90,-(JUMP_TIME/2),(JUMP_TIME/2));
		break;
	case JUMP_RIGHT:
		Parts->globalview.SetAniRotateToByCoords(0,0,-1,270,-(JUMP_TIME/2),(JUMP_TIME/2));
		break;
	case JUMP_NOT:
		Parts->globalview.SetAniRotateToByCoords(0,0,-1,0,-1,GAME_STARTING_TIME);
		break;

	}
	return true;
}

bool CGameState::HideNulls()
{
	int i,j;
	for(i=0;i<FIELD_WIDTH;i++)
		for(j=0;j<FIELD_HEIGHT;j++)
		{
			if(solve->GetCell(i,j)==0)
			{
				Parts->Trngl(i,j)->SetVisible(false);
				Parts->Text(i,j)->SetVisible(false);
			}else
			{
				Parts->Trngl(i,j)->SetVisible(true);
				Parts->Text(i,j)->SetVisible(true);
			}
		}
		return true;
}