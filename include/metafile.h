/*
 * Metafile definitions
 *
 * Copyright  David W. Metcalfe, 1994
 */

#ifndef __WINE_METAFILE_H
#define __WINE_METAFILE_H

#include "wingdi.h"
#include "gdi.h"

#define MFHEADERSIZE (sizeof(METAHEADER))
#define MFVERSION 0x300
#define META_EOF 0x0000

BOOL MF_MetaParam0(DC *dc, short func);
BOOL MF_MetaParam1(DC *dc, short func, short param1);
BOOL MF_MetaParam2(DC *dc, short func, short param1, short param2);
BOOL MF_MetaParam4(DC *dc, short func, short param1, short param2, 
		   short param3, short param4);
BOOL MF_MetaParam6(DC *dc, short func, short param1, short param2, 
		   short param3, short param4, short param5, short param6);
BOOL MF_MetaParam8(DC *dc, short func, short param1, short param2, 
		   short param3, short param4, short param5,
		   short param6, short param7, short param8);
BOOL MF_CreateBrushIndirect(DC *dc, HBRUSH16 hBrush, LOGBRUSH16 *logbrush);
BOOL MF_CreatePatternBrush(DC *dc, HBRUSH16 hBrush, LOGBRUSH16 *logbrush);
BOOL MF_CreatePenIndirect(DC *dc, HPEN16 hPen, LOGPEN16 *logpen);
BOOL MF_CreateFontIndirect(DC *dc, HFONT16 hFont, LOGFONT16 *logfont);
BOOL MF_TextOut(DC *dc, short x, short y, LPCSTR str, short count);
BOOL MF_ExtTextOut(DC *dc, short x, short y, UINT16 flags, const RECT16 *rect,
                   LPCSTR str, short count, const INT16 *lpDx);
BOOL MF_MetaPoly(DC *dc, short func, LPPOINT16 pt, short count);
BOOL MF_BitBlt(DC *dcDest, short xDest, short yDest, short width,
	       short height, DC *dcSrc, short xSrc, short ySrc, DWORD rop);
BOOL MF_StretchBlt(DC *dcDest, short xDest, short yDest, short widthDest,
		   short heightDest, DC *dcSrc, short xSrc, short ySrc, 
		   short widthSrc, short heightSrc, DWORD rop);
INT16 MF_CreateRegion(DC *dc, HRGN hrgn);
#endif   /* __WINE_METAFILE_H */

