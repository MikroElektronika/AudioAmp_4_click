![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# AudioAmp_4 Click

- **CIC Prefix**  : AUDIOAMP4
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the AudioAmp_4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2642/audioamp-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library performs a audio control and works as audio amplifier.
Possible commands are to turn ON or OFF the output (speaker) and to set the output volume by selecting the desired channel.
For more details check documentation.

Key functions :

- ``` T_AUDIOAMP4_RETVAL audioamp4_setChannel( uint8_t channel ) ``` - Function performs a volume channel selection.
- ``` T_AUDIOAMP4_RETVAL audioamp4_shutdown( uint8_t state ) ``` - Function turns shutdown to ON or OFF state.

**Examples Description**

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


```.c
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
```

Additional Functions :

- void checkResponse() - Checks is channel selection parametar valid or not.
- void writeLegend() - Writes the all possible commands on uart.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2642/audioamp-4-click) page.

Other mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
