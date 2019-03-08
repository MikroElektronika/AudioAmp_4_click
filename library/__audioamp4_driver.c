/*
    __audioamp4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__audioamp4_driver.h"
#include "__audioamp4_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __AUDIOAMP4_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _AUDIOAMP4_VOLUME_CHANN_0      = 0x00;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_1      = 0x01;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_2      = 0x02;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_3      = 0x03;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_4      = 0x04;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_5      = 0x05;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_6      = 0x06;
const uint8_t _AUDIOAMP4_VOLUME_CHANN_7      = 0x07;

const uint8_t _AUDIOAMP4_SHUTDOWN_ON         = 0x01;
const uint8_t _AUDIOAMP4_SHUTDOWN_OFF        = 0x00;

const uint8_t _AUDIOAMP4_OK                  = 0x00;
const uint8_t _AUDIOAMP4_SHTDWN_STATE_ERR    = 0x01;
const uint8_t _AUDIOAMP4_VOL_CHANN_ERR       = 0x02;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __AUDIOAMP4_DRV_SPI__

void audioamp4_spiDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AUDIOAMP4_DRV_I2C__

void audioamp4_i2cDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AUDIOAMP4_DRV_UART__

void audioamp4_uartDriverInit(T_AUDIOAMP4_P gpioObj, T_AUDIOAMP4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void audioamp4_gpioDriverInit(T_AUDIOAMP4_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );
}

/* ----------------------------------------------------------- IMPLEMENTATION */

T_AUDIOAMP4_RETVAL audioamp4_setChannel( uint8_t channel )
{
    uint8_t sel0;
    uint8_t sel1;
    uint8_t sel2;
    
    if (channel > _AUDIOAMP4_VOLUME_CHANN_7)
    {
        return _AUDIOAMP4_VOL_CHANN_ERR;
    }
    
    sel0 = channel & 0x01;
    sel1 = (channel & 0x02) >> 1;
    sel2 = (channel & 0x04) >> 2;
    
    hal_gpio_anSet( sel0 );
    hal_gpio_rstSet( sel1 );
    hal_gpio_intSet( sel2 );
    
    return _AUDIOAMP4_OK;
}

T_AUDIOAMP4_RETVAL audioamp4_shutdown( uint8_t state )
{
    if (state > 0x01)
    {
        return _AUDIOAMP4_SHTDWN_STATE_ERR;
    }
    
    hal_gpio_csSet( state );
    
    return _AUDIOAMP4_OK;
}

/* -------------------------------------------------------------------------- */
/*
  __audioamp4_driver.c

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