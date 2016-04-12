//solve.h
enum JUMP_DIR{JUMP_UP,JUMP_DOWN,JUMP_LEFT,JUMP_RIGHT,JUMP_NOT};

typedef int TDigit;

class CSolve{
public:
	CSolve(int width,int height,int xcenter,int ycenter);
	~CSolve();
	bool InitTerms(TDigit start, TDigit finish);
	JUMP_DIR Jump();
	bool IsFinish();
	JUMP_DIR PrevJump();
	JUMP_DIR NextJump();
	JUMP_DIR NextNextJump();
	TDigit GetCell(int x, int y);
	int JumpCount();
	TDigit GetStartTerm();
	TDigit GetFinishTerm();
private:
	TDigit **field;
	TDigit start_digit;
	TDigit finish_digit;
	int dx,dy;
	int ijumpcount;
	JUMP_DIR LastJump;
	bool JumpTo(JUMP_DIR dir);
	bool IsEven(TDigit dig);
	int FieldWidth;
	int FieldHeight;
	int FieldCenterX;
	int FieldCenterY;
	bool isTermsInit;
	int GetJByDigit(TDigit dig);
	int GetRowCenterByJ(int j);
	int GetRowNByJ(int j);
};