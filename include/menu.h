/*
 * Menu definitions
 */

#ifndef __WINE_MENU_H
#define __WINE_MENU_H

#include "win.h"

#define MAGIC_REDUCE  3
#define MAGIC_RESTORE 2
#define MAGIC_CLOSE   5

extern BOOL MENU_Init(void);
extern HMENU MENU_GetSysMenu(HWND hWndOwner, HMENU hSysPopup);
extern UINT MENU_GetMenuBarHeight( HWND hwnd, UINT menubarWidth,
                                     INT orgX, INT orgY );
extern BOOL MENU_PatchResidentPopup( HQUEUE16, WND* );
extern void MENU_TrackMouseMenuBar( WND *wnd, INT ht, POINT pt );
extern void MENU_TrackKbdMenuBar( WND *wnd, UINT wParam, INT vkey );
extern UINT MENU_DrawMenuBar( HDC hDC, LPRECT lprect,
                                HWND hwnd, BOOL suppress_draw );

#endif /* __WINE_MENU_H */
