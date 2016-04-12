//ctext.h
//CText class
const int MAX_TEXT_LENGHT=255;
enum HORIZ_ALIGN{HA_LEFT,HA_RIGHT,HA_CENTER};
enum VERT_ALIGN{VA_TOP,VA_BOTTOM,VA_CENTER};
class CText:public CGraphObjMix{
public:
	CText();
	bool InitText(char* srcstr,COORDS crds,float scale,bool isautoscale,COLOR col,HORIZ_ALIGN align,VERT_ALIGN valign);
	bool SetText(char* srcstr);
	bool SetLongIntAsText(long srclong);
	bool SetRotate(COORDS vectorcoord,int degrees,bool bfrtranslate);
	virtual bool Draw();
	CAniColor color;
private:
	char str[MAX_TEXT_LENGHT];
	int lenght;
	COORDS coords;
	float textscale;
	bool autoscale;
	HORIZ_ALIGN textalign;
	VERT_ALIGN verttextalign;
	int vertcorrect;
	COORDS vcoord;
	int rdegree;
	bool isinit;
	bool RotateBeforeTranslate;
	bool DrawLetter(char c,COORDS lettercoords);
	bool DrawTriangle(int t1x,int t1y,int t2x,int t2y,int t3x,int t3y);
};