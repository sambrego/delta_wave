//engine.h
//COLOR structure
struct COLOR{
	float r,g,b;
};

//color constants
const COLOR COLOR_RED={1,0,0},
			COLOR_BLACK={0,0,0},
			COLOR_COBALT={(float)102/255,(float)153/255,(float)255/255},
			COLOR_DARK_BLUE={(float)0/255,(float)51/255,(float)153/255},
			COLOR_BLACK_BLUE={(float)0/255,(float)0/255,(float)102/255},
			COLOR_GREY_BLUE={(float)51/255,(float)102/255,(float)153/255},
			COLOR_WHITE={(float)1,(float)1,(float)1},
			COLOR_MIDDLE_BLUE={(float)51/255,(float)102/255,(float)204/255 };
			//COLOR_LIGHT_BLUE={102/255,153/255,255/255},
			//COLOR_LIGHT_BLUE={102/255,153/255,255/255};
//Field size constants
const int FIELD_WIDTH=16,
		FIELD_HEIGHT=16,
		FIELD_WCENTER=7,
		FIELD_HCENTER=7;
//COORD structure
struct COORDS{
	float x,y,z;
};

COORDS xyz(float x,float y,float z);





