/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 *
 */  

#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#include "STD_TYPES.h"
#include "GPIO_interface.h"


/* ===================================================== */
/*                  SSD Enable States                    */
/* ===================================================== */

#define SSD_ENABLED              1U
#define SSD_DISABLED             0U


/* ===================================================== */
/*                  SSD Connection Types                 */
/* ===================================================== */

#define SSD_COMMON_CATHODE       0U
#define SSD_COMMON_ANODE         1U


/* ===================================================== */
/*                  SSD Segment Index                    */
/* ===================================================== */

/*
 * These indexes are used to access:
 *      Port[]
 *      Pin[]
 *
 * Example:
 *      Port[SSD_SEG_A]
 *      Pin[SSD_SEG_A]
 */
#define SSD_SEG_A                0U
#define SSD_SEG_B                1U
#define SSD_SEG_C                2U
#define SSD_SEG_D                3U
#define SSD_SEG_E                4U
#define SSD_SEG_F                5U
#define SSD_SEG_G                6U
#define SSD_SEG_EN               7U

#define SSD_SEGMENT_COUNT        7U
#define SSD_TOTAL_PINS           8U


typedef struct
{
    GPIO_Typedef* Port[SSD_TOTAL_PINS];
    u8 Pin[SSD_TOTAL_PINS];

    /*
     * SSD_Type:
     *      SSD_COMMON_CATHODE
     *      SSD_COMMON_ANODE
     */
    u8 SSD_Type; // Common Cathode Or Common Anode

    //u8 sevenSegmentConnectionMap [8][2] ; 

} SSD_Config_t;


/*
 * Backward compatibility:
 * -----------------------
 * Your old struct name was SSD_PinConfig.
 * The new cleaner name is SSD_Config_t.
 *
 * This typedef keeps old application code working.
 */
typedef SSD_Config_t SSD_PinConfig;


void SSD_voidInit(SSD_Config_t Copy_Config);
void SSD_voidDisplay(SSD_Config_t Copy_Config, u8 Copy_u8Number);
void SSD_voidClear(SSD_Config_t Copy_Config);
void SSD_voidEnable(SSD_Config_t Copy_Config);
void SSD_voidDisable(SSD_Config_t Copy_Config);


#endif //_SSD_INTERFACE_H_
