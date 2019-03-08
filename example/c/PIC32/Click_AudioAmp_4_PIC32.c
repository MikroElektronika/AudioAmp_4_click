/*
Example for AudioAmp_4 Click

    Date          : Nov 2018.
    Author        : Nemanja Medakovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface, turns shutdown OFF and performs
  a volume channel 3 selection.
- Application Task - (code snippet) - Checks which command is sent from uart and performs a
  determined command.
Note : Possible commands are:
+    Shutdown OFF
-    Shutdown ON
l    Legend
0-7  Volume channel selection

Additional Functions :

- void checkResponse() - Checks is channel selection parametar valid or not.
- void writeLegend() - Writes the all possible commands on uart.

*/

#include "Click_AudioAmp_4_types.h"
#include "Click_AudioAmp_4_config.h"

const uint8_t _NO_RECEIVED_DATA = 0x00;

uint8_t rxDat;
uint8_t channSel;
T_AUDIOAMP4_RETVAL responseCheck;
char logDat[ 2 ];

void checkResponse()
{
    if (responseCheck == _AUDIOAMP4_OK)
    {
        logDat[ 0 ] = rxDat;
        mikrobus_logWrite( "* Volume channel ", _LOG_TEXT );
        mikrobus_logWrite( logDat, _LOG_TEXT );
        mikrobus_logWrite( " is enabled *", _LOG_LINE );
    }
    else
    {
        mikrobus_logWrite( "* Wrong channel is selected! *", _LOG_LINE );
    }
}

void writeLegend()
{
    mikrobus_logWrite( "** Press - to turn Shutdown ON, or + to turn Shutdown OFF **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 1000 );
    mikrobus_logWrite( "** Turn ON the desired volume channel (from 0 to 7) **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite( "*** Initializing... ***", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    audioamp4_gpioDriverInit( (T_AUDIOAMP4_P)&_MIKROBUS1_GPIO );
    Delay_ms( 200 );
    
    logDat[ 1 ] = 0;
    audioamp4_shutdown( _AUDIOAMP4_SHUTDOWN_OFF );
    audioamp4_setChannel( _AUDIOAMP4_VOLUME_CHANN_3 );

    mikrobus_logWrite( "** AudioAmp 4 is initialized **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 1000 );
    writeLegend();
}

void applicationTask()
{
    rxDat = UART_Rdy_Ptr();

    if (rxDat != _NO_RECEIVED_DATA)
    {
        rxDat = UART_Rd_Ptr();

        if (rxDat == '+')
        {
            audioamp4_shutdown( _AUDIOAMP4_SHUTDOWN_OFF );

            mikrobus_logWrite( "* Shutdown OFF *", _LOG_LINE );
        }
        else if (rxDat == '-')
        {
            audioamp4_shutdown( _AUDIOAMP4_SHUTDOWN_ON );

            mikrobus_logWrite( "* Shutdown ON *", _LOG_LINE );
        }
        else if (rxDat == 'l')
        {
            writeLegend();
        }
        else
        {
            channSel = rxDat - '0';
            responseCheck = audioamp4_setChannel( channSel );

            checkResponse();
        }
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
