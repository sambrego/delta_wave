//triangle.h
//CTriangle class
class CTriangle:public CGraphObjMix{
public:
	CTriangle();
	~CTriangle();
	bool SetColor(COLOR vertex1,COLOR vertex2,COLOR vertex3);
	bool SetAniColor(COLOR vertex1,COLOR vertex2,COLOR vertex3,long newtimer,long newlimit);
	bool SetParams(COORDS center,bool rotated,float newscale);
	bool SetRotated(bool rotated);

	bool InvertRotate();
	bool IsRotated();
	bool Draw();
	COORDS GetTrueCenter();
	COORDS GetCenter();
	COORDS Vertex1();
	COORDS Vertex2();
	COORDS Vertex3();
	CAniColor v1,v2,v3;
private:
	COORDS centercoords;
	bool isrotated;
	float scale;
};