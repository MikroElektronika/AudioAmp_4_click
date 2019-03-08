/*
    __audioamp4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __audioamp4_driver.h
@brief    AudioAmp_4 Driver
@mainpage AudioAmp_4 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   AUDIOAMP4
@brief      AudioAmp_4 Click Driver
@{

| Global Library Prefix | **AUDIOAMP4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _AUDIOAMP4_H_
#define _AUDIOAMP4_H_

/** 
 * @macro T_AUDIOAMP4_P
 * @brief Driver Abstract type 
 */
#define T_AUDIOAMP4_P    const uint8_t*
#define T_AUDIOAMP4_RETVAL     uint8_t

/** @defgroup AUDIOAMP4_COMPILE Compilation Config */              /** @{ */

//  #define   __AUDIOAMP4_DRV_SPI__                            /**<     @macro __AUDIOAMP4_DRV_SPI__  @brief SPI driver selector */
//  #define   __AUDIOAMP4_DRV_I2C__                            /**<     @macro __AUDIOAMP4_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __AUDIOAMP4_DRV_UART__                           /**<     @macro __AUDIOAMP4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup AUDIOAMP4_VAR Variables */                           /** @{ */

/** Settings for volume channel selection */
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_0    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_1    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_2    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_3    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_4    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_5    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_6    ;
extern const uint8_t _AUDIOAMP4_VOLUME_CHANN_7    ;

/** Shutdown states */
extern const uint8_t _AUDIOAMP4_SHUTDOWN_ON       ;
extern const uint8_t _AUDIOAMP4_SHUTDOWN_OFF      ;

/** Function response */
extern const uint8_t _AUDIOAMP4_OK                ;
extern const uint8_t _AUDIOAMP4_SHTDWN_STATE_ERR  ;
extern const uint8_t _AUDIOAMP4_VOL_CHANN_ERR     ;

                                                                       /** @} */
/** @defgroup AUDIOAMP4_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup AUDIOAMP4_INIT Driver Initialization */              /** @{ */

#ifdef   __AUDIOAMP4_DRV_SPI__
void audioamp4_spiDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P spiObj);
#endif
#ifdef   __AUDIOAMP4_DRV_I2C__
void audioamp4_i2cDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P i2cObj, uint8_t slave);
#endif
#ifdef   __AUDIOAMP4_DRV_UART__
void audioamp4_uartDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P uartObj);
#endif

void audioamp4_gpioDriverInit(T_AUDIOAMP4_P gpioObj);
                                                                       /** @} */
/** @defgroup AUDIOAMP4_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Volume Channel Setting function
 *
 * @param[in] channel  Volume channel selection, from 0 to 7
 *
 * @returns 0 - OK, 2 - Wrong channel selection
 *
 * Function performs a volume channel selection.
 */
T_AUDIOAMP4_RETVAL audioamp4_setChannel( uint8_t channel );

/**
 * @brief Shutdown function
 *
 * @param[in] state  0 - Shutdown OFF, 1 - Shutdown ON
 *
 * @returns 0 - OK, 1 - Wrong Shutdown state
 *
 * Function turns shutdown to ON or OFF state.
 */
T_AUDIOAMP4_RETVAL audioamp4_shutdown( uint8_t state );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_AudioAmp_4_STM.c
    @example Click_AudioAmp_4_TIVA.c
    @example Click_AudioAmp_4_CEC.c
    @example Click_AudioAmp_4_KINETIS.c
    @example Click_AudioAmp_4_MSP.c
    @example Click_AudioAmp_4_PIC.c
    @example Click_AudioAmp_4_PIC32.c
    @example Click_AudioAmp_4_DSPIC.c
    @example Click_AudioAmp_4_AVR.c
    @example Click_AudioAmp_4_FT90x.c
    @example Click_AudioAmp_4_STM.mbas
    @example Click_AudioAmp_4_TIVA.mbas
    @example Click_AudioAmp_4_CEC.mbas
    @example Click_AudioAmp_4_KINETIS.mbas
    @example Click_AudioAmp_4_MSP.mbas
    @example Click_AudioAmp_4_PIC.mbas
    @example Click_AudioAmp_4_PIC32.mbas
    @example Click_AudioAmp_4_DSPIC.mbas
    @example Click_AudioAmp_4_AVR.mbas
    @example Click_AudioAmp_4_FT90x.mbas
    @example Click_AudioAmp_4_STM.mpas
    @example Click_AudioAmp_4_TIVA.mpas
    @example Click_AudioAmp_4_CEC.mpas
    @example Click_AudioAmp_4_KINETIS.mpas
    @example Click_AudioAmp_4_MSP.mpas
    @example Click_AudioAmp_4_PIC.mpas
    @example Click_AudioAmp_4_PIC32.mpas
    @example Click_AudioAmp_4_DSPIC.mpas
    @example Click_AudioAmp_4_AVR.mpas
    @example Click_AudioAmp_4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __audioamp4_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */