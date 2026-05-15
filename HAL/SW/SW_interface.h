/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 *
 */

#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

#include "STD_TYPES.h"
#include "GPIO_interface.h"


/* ===================================================== */
/*                  Switch States                        */
/* ===================================================== */

#define SW_NOT_PRESSED 0U
#define SW_PRESSED     1U

/* ===================================================== */
/*                  Switch Types                         */
/* ===================================================== */

#define SW_ACTIVE_HIGH     1U
#define SW_ACTIVE_LOW      0U

#define NULL 0 

typedef struct
{
    GPIO_Typedef* Port;
    u8 Pin;
    u8 SW_Type;

} SW_t;

/* ===================================================== */
/*                  APIs                                 */
/* ===================================================== */

void SW_voidInit    (SW_t Copy_Config);
u8   SW_u8GetState  (SW_t Copy_Config);

#endif //_SW_INTERFACE_H_
