/*
 * Graphics driver management functions
 *
 * Copyright 1996 Alexandre Julliard
 */

#include "gdi.h"
#include "heap.h"
#include "debug.h"
#include <string.h>

typedef struct tagGRAPHICS_DRIVER
{
    struct tagGRAPHICS_DRIVER *next;
    LPSTR                      name;
    const DC_FUNCTIONS        *funcs;
} GRAPHICS_DRIVER;

static GRAPHICS_DRIVER *firstDriver = NULL;
static GRAPHICS_DRIVER *genericDriver = NULL;

/**********************************************************************
 *	     DRIVER_RegisterDriver
 */
BOOL DRIVER_RegisterDriver( LPCSTR name, const DC_FUNCTIONS *funcs )
{
    GRAPHICS_DRIVER *driver = HeapAlloc( SystemHeap, 0, sizeof(*driver) );
    if (!driver) return FALSE;
    driver->funcs = funcs;
    if (name)
    {
        driver->name  = HEAP_strdupA( SystemHeap, 0, name );
        driver->next  = firstDriver;
        firstDriver = driver;
        return TRUE;
    }
    /* No name -> it's the generic driver */
    if (genericDriver)
    {
        WARN(driver, " already a generic driver\n" );
        HeapFree( SystemHeap, 0, driver );
        return FALSE;
    }
    driver->name = NULL;
    genericDriver = driver;
    return TRUE;
}


/**********************************************************************
 *	     DRIVER_FindDriver
 */
const DC_FUNCTIONS *DRIVER_FindDriver( LPCSTR name )
{
    GRAPHICS_DRIVER *driver = firstDriver;

    while (driver && name)
    {
        if (!strcasecmp( driver->name, name )) return driver->funcs;
        driver = driver->next;
    }
    return genericDriver ? genericDriver->funcs : NULL;
}


/**********************************************************************
 *	     DRIVER_UnregisterDriver
 */
BOOL DRIVER_UnregisterDriver( LPCSTR name )
{
    if (name)
    {
        GRAPHICS_DRIVER **ppDriver = &firstDriver;
        while (*ppDriver)
        {
            if (!strcasecmp( (*ppDriver)->name, name ))
            {
                GRAPHICS_DRIVER *driver = *ppDriver;
                (*ppDriver) = driver->next;
                HeapFree( SystemHeap, 0, driver->name );
                HeapFree( SystemHeap, 0, driver );
                return TRUE;
            }
            ppDriver = &(*ppDriver)->next;
        }
        return FALSE;
    }
    else
    {
        if (!genericDriver) return FALSE;
        HeapFree( SystemHeap, 0, genericDriver );
        genericDriver = NULL;
        return TRUE;
    }
}
