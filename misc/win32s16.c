/*
 * WIN32S16
 * DLL for Win32s
 *
 * Copyright (c) 1997 Andreas Mohr
 */

#include <string.h>
#include <stdlib.h>
#include "wintypes.h"
#include "debug.h"

void WINAPI BootTask16()
{
	MSG("BootTask(): should only be used by WIN32S.EXE.\n");
}

/***********************************************************************
 *           StackLinearToSegmented       (WIN32S16.43)
 *
 * Written without any docu.
 */
SEGPTR WINAPI StackLinearToSegmented16(WORD w1, WORD w2)
{
	FIXME(dll,"(%d,%d):stub.\n",w1,w2);
	return (SEGPTR)NULL;
}
