//stdafx.h
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E2DAD541_3F96_47DE_B5B6_26E53CFF238E__INCLUDED_)
#define AFX_STDAFX_H__E2DAD541_3F96_47DE_B5B6_26E53CFF238E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "engine.h"
#include "winmain.h"
#include "opengl.h"
#include "graphobj.h"
#include "intrface.h"
#include "timer.h"
#include "aniview.h"
#include "anicolor.h"
#include "ctext.h"
#include "triangle.h"
#include "parts.h"
#include "cstate.h"
#include "solve.h"
#include "customstates.h"
#include "cmanager.h"



// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E2DAD541_3F96_47DE_B5B6_26E53CFF238E__INCLUDED_)
