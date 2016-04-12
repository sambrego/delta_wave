//aniview.h
typedef float DEGREES;
//enum ROTATE_SIDE{ROTATE_SIDE_CLOCKWISE,ROTATE_SIDE_ACLOCKWISE,ROTATE_SIDE_AUTO};
class CAniView{
public:
	CAniView();
	bool SetViewTranslateByStruct(COORDS TranslateCoords_new);
	bool SetViewTranslateByCoords(float x,float y,float z);
	bool SetViewTranslateAdditive(float x,float y,float z);

	bool SetViewRotateByStruct(COORDS RotateVector_new,DEGREES degrees_new);
	bool SetViewRotateByCoords(float x,float y,float z,DEGREES degrees_new);

	bool SetAniTranslateToByStruct(COORDS TranslateCoords_new,int timer,int limit);
	bool SetAniTranslateToByCoords(float x,float y,float z,int timer,int limit);

	bool SetAniRotateToByStruct(COORDS RotateVector_new,DEGREES degrees_new,int timer_new,int limit_new);
	bool SetAniRotateToByCoords(float x,float y,float z,DEGREES degrees_new,int timer_new,int limit_new);

	bool IsActiveTranslateAni();
	bool IsActiveRotateAni();
	bool ProcessView();
private:
	static COORDS TranslateCoords;
	static COORDS TranslateCoordsDelta;
	static long TranslateTimer;
	static long TranslateLimit;
	static bool bTranslateAniActive;
	
	static COORDS RotateVector;
	static COORDS RotateVectorDelta;
	static DEGREES degrees;
	static DEGREES degreesDelta;
	static long RotateTimer;
	static long RotateLimit;
	static bool bRotateAniActive;

	CTimer globaltimer;
};