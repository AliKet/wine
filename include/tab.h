/*
 * Tab control class extra info
 *
 * Copyright 1998 Anders Carlsson
 */

#ifndef __WINE_TAB_H  
#define __WINE_TAB_H

typedef struct tagTAB_ITEM
{
	UINT  mask;
	DWORD	dwState;
    LPSTR	pszText;
	INT   cchTextMax;
    INT	iImage;
    LPARAM	lParam;
    RECT   	rect;		/* bounding rectangle of the item */
} TAB_ITEM;

typedef struct tagTAB_INFO
{
    UINT	    uNumItem;	/* number of tab items */
    INT	    nHeight;	/* height of the tab row */
    HFONT	    hFont;		/* handle to the current font */
    HCURSOR	hcurArrow;	/* handle to the current cursor */
	HIMAGELIST  himl;       /* handle to a image list (may be 0) */
	HWND		hwndToolTip; /* handle to tab's tooltip */
	UINT		cchTextMax;
    INT	    iSelected;	/* the currently selected item */
    INT	    uFocus;		/* item which has the focus */
    TAB_ITEM	*items;		/* pointer to an array of TAB_ITEM's */
    RECT	    rect;
    BOOL	    DoRedraw;	/* flag for redrawing when tab contents is changed*/
} TAB_INFO;


extern VOID TAB_Register (VOID);
extern VOID TAB_Unregister (VOID);

#endif  /* __WINE_TAB_H */
