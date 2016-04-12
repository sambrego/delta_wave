//graphobj.h
class CGraphObjMix
{
public:
	CGraphObjMix();
	bool SetVisible(bool state);
	bool IsVisible();
	virtual bool Draw()=0;
protected:
	bool bIsVisible;
};