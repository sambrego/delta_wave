//anicolor.h
//CAniColor class
class CAniColor{
public:
	CAniColor();
	bool SetColor(COLOR newcolor);
	bool SetAniTo(COLOR fincolor, long newtimer, long newlimit);
	bool Process();
	float r();
	float g();
	float b();
private:
	COLOR col;
	float dr,dg,db;
	long timer;
	long limit;
	bool isactive;
	CTimer globaltimer;
};
