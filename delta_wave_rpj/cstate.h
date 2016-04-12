//cstate.h
enum STEP{STEP_NONE,STEP_STARTING,STEP_PROCESSING,STEP_FINISHING};
class CStateManager;
class CState{
public:
	bool Process();
	virtual bool Init(CStateManager* StateManager_new,CParts* Parts_new);
protected:
	bool EndProcOnTimer;
	STEP CurrentStep;
	CStateManager* StateManager;
	CParts* Parts;
	CState* StateChangeOnFinish;
	long ProcBegin,ProcEnd,TotalFinish,Timer;
	bool StartUp();
	bool EndUp(CState* StartAfterFinish);
	bool ProcessActions();
	virtual bool OnUpAction();
	virtual bool OnDownAction();
	virtual bool OnLeftAction();
	virtual bool OnRightAction();
	virtual bool OnOkAction();
	virtual bool OnCancelAction();
	virtual bool OnProcess();
	virtual bool OnStartUp();
	virtual bool OnEndUp();
	virtual bool OnFinish();
	virtual bool OnProcessBegan();
private:

};