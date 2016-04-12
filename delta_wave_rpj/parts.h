//parts.h
class CParts{
public:
	CParts(int arrwidth_new, int arrheight_new);
	~CParts();
	CInterface globalinterface;
	CAniView globalview;
	CTriangle* Trngl(int i,int j);
	CText* Text(int i,int j);
	bool SetVisible(bool state,CGraphObjMix* obj,...);
	bool SetInvisibleAll();
	bool SetFadeAll(long time);
	bool InitStartState();
	bool DrawAll();
	bool InvertTriangles();
	//text
	CText MenuGame;
	CText MenuAbout;
	CText MenuExit;
	CText StartDigitLable;
	CText StartDigit;
	CText FinDigitLable;
	CText FinDigit;
	CText AboutBlahBlah;
	CText MenuGo;
	CText LogoDeltaWave;
	CText JumpCount;
	CText GMJumpCount;
	CText GMJumpCountLable;
	//end of text
private:
	CTriangle** trianglearr;
	CText** textarr;
	int arrwidth, arrheight;
};