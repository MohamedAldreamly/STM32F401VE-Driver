/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 *  STM32F401 Update:
 *  ----------------
 *  This file keeps the original switch configuration style.
 *
 *  Switch logic:
 *      SW_ACTIVE_HIGH:
 *          Pressed  -> GPIO_HIGH
 *
 *      SW_ACTIVE_LOW:
 *          Pressed  -> GPIO_LOW
 *
 */

#ifndef _SW_CONFIG_H_
#define _SW_CONFIG_H_


#define SW_CONFIG SW_ACTIVE_LOW


#define SW_DEBOUNCE_TIME_MS    20U


#endif //_SW_CONFIG_H_
