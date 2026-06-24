//###########################################################################
//
// FILE:   f280013x_gpio.c
//
// TITLE:  f280013x GPIO module support functions
//
//###########################################################################
//
//
// $Copyright:
// Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include <AFDD.h>                        // Main include file
#include "f280013x_device.h"
#include "f280013x_examples.h"

//
// Low-level functions for GPIO configuration
//

//
// InitGpio - Sets all pins to be muxed to GPIO in input mode with pull-ups
// enabled.Also resets CPU control to CPU1 and disables open drain
// and polarity inversion and sets the qualification to synchronous.
// Also unlocks all GPIOs. Only one CPU should call this function.
//

// GPIOs for PWM configuration in ARC Fault Detection Device
//  GPIO   Functionality
//  Gpio0   PWM1A
//  Gpio1   PWM1B
//  Gpio2   PWM2A
//  Gpio3   PWM2B

// GPIOs for LED indication in ARC Fault Detection Device
//  GPIO   Functionality   Color
//   11     CH 1 ON        GREEN
//   20     CH 1 OFF       RED
//   33     CH 2 ON        GREEN
//   21     CH 2 OFF       RED
//   16     CH 3 ON        GREEN
//   13     CH 3 OFF       RED
//   17     CH 4 ON        GREEN
//   12     CH 4 OFF       RED


void
InitGpio()
{


// ################################################################################################
// ---------   Unlock the GPxLOCK register bits for all ports --------------
// ################################################################################################

    GpioCtrlRegs.GPACR.all   = 0x00000000;
    GpioCtrlRegs.GPBCR.all   = 0x00000000;
    GpioCtrlRegs.GPHCR.all   = 0x00000000;

// ################################################################################################
// ---------   Disable the register locks for all ports --------------
// ################################################################################################

    EALLOW;

    GpioCtrlRegs.GPALOCK.all = 0x00000000;
    GpioCtrlRegs.GPBLOCK.all = 0x00000000;
    GpioCtrlRegs.GPHLOCK.all = 0x00000000;

// ################################################################################################
// ---------   Group-A GPIO Pins --------------
// ################################################################################################

    GpioCtrlRegs.GPACTRL.all  = 0x00000000;     // QUALPRD = PLLSYSCLK for all group A GPIO
    GpioCtrlRegs.GPAQSEL1.all = 0x00000000;     // Synchronous qualification for all group A GPIO 0-15
    GpioCtrlRegs.GPAQSEL2.all = 0x00000000;     // Synchronous qualification for all group A GPIO 16-31
    GpioCtrlRegs.GPADIR.all   = 0x00000000;     // All GPIO are inputs
    GpioCtrlRegs.GPAPUD.all   = 0x00000000;     // All pullups enabled
    GpioCtrlRegs.GPAINV.all   = 0x00000000;     // No inputs inverted
    GpioCtrlRegs.GPAODR.all   = 0x00000000;     // All outputs normal mode (no open-drain outputs)

// ################################################################################################
// ---------   Group-B GPIO Pins --------------
// ################################################################################################

    GpioCtrlRegs.GPBCTRL.all  = 0x00000000;     // QUALPRD = PLLSYSCLK for all group B GPIO
    GpioCtrlRegs.GPBQSEL1.all = 0x00000000;     // Synchronous qualification for all group B GPIO 32-47
    GpioCtrlRegs.GPBDIR.all   = 0x00000000;     // All group B GPIO are inputs
    GpioCtrlRegs.GPBPUD.all   = 0x00000000;     // All group B pullups enabled
    GpioCtrlRegs.GPBINV.all   = 0x00000000;     // No inputs inverted
    GpioCtrlRegs.GPBODR.all   = 0x00000000;     // All outputs normal mode (no open-drain outputs)

// ################################################################################################
// ---------   Group-H GPIO Pins --------------
// ################################################################################################

    GpioCtrlRegs.GPHCTRL.all  = 0x00000000;     // QUALPRD = PLLSYSCLK for all group H GPIO
    GpioCtrlRegs.GPHQSEL1.all = 0x00000000;     // Synchronous qualification for all group H GPIO 224-239
    GpioCtrlRegs.GPHQSEL2.all = 0x00000000;     // Synchronous qualification for all group H GPIO 240-255
    GpioCtrlRegs.GPHINV.all   = 0x00000000;     // No inputs inverted



//  Configuring pins as ADCs
    AnalogSubsysRegs.AGPIOCTRLH.bit.GPIO242 = 1;    // A3/C5
    GpioCtrlRegs.GPHAMSEL.bit.GPIO242 = 1;

    AnalogSubsysRegs.AGPIOCTRLH.bit.GPIO224 = 1;    // A2/C9
    GpioCtrlRegs.GPHAMSEL.bit.GPIO224 = 1;

//  Configuring pins as GPIOs
    AnalogSubsysRegs.AGPIOCTRLA.bit.GPIO20 = 0;     // Using as digital pin
    GpioCtrlRegs.GPAAMSEL.bit.GPIO20 = 0;           // Using as digital pin

    AnalogSubsysRegs.AGPIOCTRLA.bit.GPIO21 = 0;     // Using as digital pin
    GpioCtrlRegs.GPAAMSEL.bit.GPIO21 = 0;           // Using as digital pin

    AnalogSubsysRegs.AGPIOCTRLA.bit.GPIO13 = 0;     // Using as digital pin
    GpioCtrlRegs.GPAAMSEL.bit.GPIO13 = 0;           // Using as digital pin

    AnalogSubsysRegs.AGPIOCTRLA.bit.GPIO12 = 0;     // Using as digital pin
    GpioCtrlRegs.GPAAMSEL.bit.GPIO12 = 0;           // Using as digital pin

// ################################################################################################
// ---------------------------------  Pins configuration -------------------------------------
// ################################################################################################

    // ---------------------------------  EPWM Pins configuration --------------------------------
    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0;        // 0|1 = PWM Signal     GPIO 0 : 1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO0  = 1;

    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0;        // 0|1 = PWM Signal     GPIO 1 : 1B
    GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 1;

    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX1.bit.GPIO2 = 0;        // 0|1 = PWM Signal     GPIO 2 : 2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO2  = 1;

    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX1.bit.GPIO3 = 0;        // 0|1 = PWM Signal     GPIO 3 : 2B
    GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 1;

    //-----------------------------------------------------------------------------------------------------

    // ---------------------------------  GPIO Pins configuration --------------------------------

    GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 0;         // Green LED
    GpioCtrlRegs.GPAMUX1.bit.GPIO11  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO11   = 1;         //Configuring GPIO11 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX2.bit.GPIO20 = 0;         // Red LED
    GpioCtrlRegs.GPAMUX2.bit.GPIO20  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO20   = 1;         //Configuring GPIO20 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPBGMUX1.bit.GPIO33 = 0;         // Green LED
    GpioCtrlRegs.GPBMUX1.bit.GPIO33  = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO33   = 1;         //Configuring GPIO33 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX2.bit.GPIO21 = 0;         // Red LED
    GpioCtrlRegs.GPAMUX2.bit.GPIO21  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO21   = 1;         //Configuring GPIO21 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX2.bit.GPIO16 = 0;         // Green LED
    GpioCtrlRegs.GPAMUX2.bit.GPIO16  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO16   = 1;         //Configuring GPIO21 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX1.bit.GPIO13 = 0;         // Red LED
    GpioCtrlRegs.GPAMUX1.bit.GPIO13  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO13   = 1;         //Configuring GPIO21 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 0;         // Red LED
    GpioCtrlRegs.GPAMUX2.bit.GPIO17  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO17   = 1;         //Configuring GPIO21 as output direction//

    //-----------------------------------------------------------------------------------------------------

    GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 0;         // Red LED
    GpioCtrlRegs.GPAMUX1.bit.GPIO12  = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12   = 1;         //Configuring GPIO21 as output direction//

    //-----------------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX2.bit.GPIO18 = 0;        // 0|3 = CANA RX
    GpioCtrlRegs.GPAMUX2.bit.GPIO18  = 3;

    //-----------------------------------------------------------------------------------------------------
    GpioCtrlRegs.GPAGMUX2.bit.GPIO19 = 0;        // 0|3 = CANA TX
    GpioCtrlRegs.GPAMUX2.bit.GPIO19  = 3;

    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX1.bit.GPIO6  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX1.bit.GPIO7  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX1.bit.GPIO8  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX1.bit.GPIO9  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX1.bit.GPIO10  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX2.bit.GPIO17  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO22 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX2.bit.GPIO22  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO23 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPAMUX2.bit.GPIO23  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO39 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPBMUX1.bit.GPIO39  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO40 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPBMUX1.bit.GPIO40  = 0;
//
//    //-----------------------------------------------------------------------------------------------------
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO41 = 0;        // 0|0 = Digital Output
//    GpioCtrlRegs.GPBMUX1.bit.GPIO41  = 0;

// ################################################################################################
// ----------------------------  Initialization of GPIOs as OUTPUT Pins ---------------------------
// ################################################################################################

    // ******* Making GPIO pins as Output Pins: START *******
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO40 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1;
    // ******* Making GPIO pins as Output Pins: END *******

// ################################################################################################
// --------------------------- Enable the register locks for all ports ----------------------------
// ################################################################################################

    GpioCtrlRegs.GPALOCK.all = 0xFFFFFFFF;
    GpioCtrlRegs.GPBLOCK.all = 0xFFFFFFFF;
    GpioCtrlRegs.GPHLOCK.all = 0xFFFFFFFF;

// ################################################################################################
// --------------------   Lock the GPxLOCK register bits for all ports ----------------------------
// ################################################################################################

    GpioCtrlRegs.GPACR.all   = 0xFFFFFFFF;
    GpioCtrlRegs.GPBCR.all   = 0xFFFFFFFF;
    GpioCtrlRegs.GPHCR.all   = 0xFFFFFFFF;

    EDIS;
}

//
// GPIO_SetupPinMux - Set the peripheral muxing for the specified pin.
// The appropriate parameters can be found in the pinout spreadsheet.
//
void
GPIO_SetupPinMux(Uint16 gpioNumber, Uint16 cpu, Uint16 muxPosition)
{
    volatile Uint32 *gpioBaseAddr;
    volatile Uint32 *mux, *gmux, *csel;
    Uint16 pin32, pin16, pin8;

    pin32 = gpioNumber % 32;
    pin16 = gpioNumber % 16;
    pin8 = gpioNumber % 8;
    gpioBaseAddr = (Uint32 *)&GpioCtrlRegs + (gpioNumber/32)*GPY_CTRL_OFFSET;

    //
    // Sanity check for valid cpu and peripheral values
    //
    if (cpu > GPIO_MUX_CPU1 || muxPosition > 0xF)
    {
        return;
    }

    //
    // Create pointers to the appropriate registers. This is a workaround
    // for the way GPIO registers are defined. The standard definition
    // in the header file makes it very easy to do named accesses of one
    // register or bit, but hard to do arbitrary numerical accesses. It's
    // easier to have an array of GPIO modules with identical registers,
    // including arrays for multi-register groups like GPyCSEL1-4. But
    // the header file doesn't define anything we can turn into an array,
    // so manual pointer arithmetic is used instead.
    //
    mux = gpioBaseAddr + GPYMUX + pin32/16;
    gmux = gpioBaseAddr + GPYGMUX + pin32/16;
    csel = gpioBaseAddr + GPYCSEL + pin32/8;

    //
    // Now for the actual function
    //
    EALLOW;

    //
    // To change the muxing, set the peripheral mux to 0/GPIO first to avoid
    // glitches, then change the group mux, then set the peripheral mux to
    // its target value. Finally, set the CPU select. This procedure is
    // described in the TRM. Unfortunately, since we don't know the pin in
    // advance we can't hardcode a bitfield reference, so there's some tricky
    // bit twiddling here.
    //
    *mux &= ~(0x3UL << (2*pin16));
    *gmux &= ~(0x3UL << (2*pin16));
    *gmux |= (Uint32)((muxPosition >> 2) & 0x3UL) << (2*pin16);
    *mux |= (Uint32)(muxPosition & 0x3UL) << (2*pin16);

    *csel &= ~(0x3L << (4*pin8));
    *csel |= (Uint32)(cpu & 0x3L) << (4*pin8);

    //
    // WARNING: This code does not touch the analog mode select registers.
    //

    EDIS;
}

//
// GPIO_SetupPinOptions - Setup up the GPIO input/output options for the
// specified pin. The flags are a 16-bit mask produced by ORing together
// options. For input pins, the valid flags are:
// GPIO_PULLUP  Enable pull-up
// GPIO_INVERT  Enable input polarity inversion
// GPIO_SYNC  Synchronize the input latch to PLLSYSCLK
//              (default -- you don't need to specify this)
// GPIO_QUAL3  Use 3-sample qualification
// GPIO_QUAL6  Use 6-sample qualification
// GPIO_ASYNC  Do not use synchronization or qualification
// (Note: only one of SYNC, QUAL3, QUAL6, or ASYNC is allowed)
//
// For output pins, the valid flags are:
// GPIO_OPENDRAIN  Output in open drain mode
// GPIO_PULLUP    If open drain enabled, also enable the pull-up
// and the input qualification flags (SYNC/QUAL3/QUAL6/SYNC) listed above.
//
// With no flags, the default input state is synchronous with no
// pull-up or polarity inversion. The default output state is
// the standard digital output.
//
void
GPIO_SetupPinOptions(Uint16 gpioNumber, Uint16 output, Uint16 flags)
{
    volatile Uint32 *gpioBaseAddr;
    volatile Uint32 *dir, *pud, *inv, *odr, *qsel;
    Uint32 pin32, pin16, pinMask, qual;

    pin32 = gpioNumber % 32;
    pin16 = gpioNumber % 16;
    pinMask = 1UL << pin32;
    gpioBaseAddr = (Uint32 *)&GpioCtrlRegs + (gpioNumber/32)*GPY_CTRL_OFFSET;

    //
    // Create pointers to the appropriate registers. This is a workaround
    // for the way GPIO registers are defined. The standard definition
    // in the header file makes it very easy to do named accesses of one
    // register or bit, but hard to do arbitrary numerical accesses. It's
    // easier to have an array of GPIO modules with identical registers,
    // including arrays for multi-register groups like GPyQSEL1-2. But
    // the header file doesn't define anything we can turn into an array,
    // so manual pointer arithmetic is used instead.
    //
    dir = gpioBaseAddr + GPYDIR;
    pud = gpioBaseAddr + GPYPUD;
    inv = gpioBaseAddr + GPYINV;
    odr = gpioBaseAddr + GPYODR;
    qsel = gpioBaseAddr + GPYQSEL + pin32/16;

    EALLOW;

    //
    // Set the data direction
    //
    *dir &= ~pinMask;
    if (output == 1)
    {
        //
        // Output, with optional open drain mode and pull-up
        //
        *dir |= pinMask;

        //
        // Enable open drain if necessary
        //
        if (flags & GPIO_OPENDRAIN)
        {
            *odr |= pinMask;
        }
        else
        {
            *odr &= ~pinMask;
        }

        //
        // Enable pull-up if necessary. Open drain mode must be active.
        //
        if (flags & (GPIO_OPENDRAIN | GPIO_PULLUP))
        {
            *pud &= ~pinMask;
        }
        else
        {
            *pud |= pinMask;
        }
    }

    else
    {
        //
        // Input, with optional pull-up, qualification, and polarity inversion
        //
        *dir &= ~pinMask;

        //
        // Enable pull-up if necessary
        //
        if (flags & GPIO_PULLUP)
        {
            *pud &= ~pinMask;
        }
        else
        {
            *pud |= pinMask;
        }

        //
        // Invert polarity if necessary
        //
        if (flags & GPIO_INVERT)
        {
            *inv |= pinMask;
        }
        else
        {
            *inv &= ~pinMask;
        }
    }

    //
    // Extract the qualification parameter and load it into the register.
    // This is also needed for open drain outputs, so we might as well do it
    // all the time.
    //
    qual = (flags & GPIO_ASYNC) / GPIO_QUAL3;
    *qsel &= ~(0x3L << (2 * pin16));
    if (qual != 0x0)
    {
        *qsel |= qual << (2 * pin16);
    }

    EDIS;
}

//
// GPIO_SetupLock - Enable or disable the GPIO register bit lock for the
// specified pin. The valid flags are:
// GPIO_UNLOCK  Unlock the pin setup register bits for the specified pin
// GPIO_LOCK   Lock the pin setup register bits for the specified pin
//
void
GPIO_SetupLock(Uint16 gpioNumber, Uint16 flags)
{
    volatile Uint32 *gpioBaseAddr;
    volatile Uint32 *lock;
    Uint32 pin32, pinMask;

    pin32 = gpioNumber % 32;
    pinMask = 1UL << pin32;
    gpioBaseAddr = (Uint32 *)&GpioCtrlRegs + (gpioNumber/32)*GPY_CTRL_OFFSET;

    //
    // Create pointers to the appropriate registers. This is a workaround
    // for the way GPIO registers are defined. The standard definition
    // in the header file makes it very easy to do named accesses of one
    // register or bit, but hard to do arbitrary numerical accesses. It's
    // easier to have an array of GPIO modules with identical registers,
    // including arrays for multi-register groups like GPyQSEL1-2. But
    // the header file doesn't define anything we can turn into an array,
    // so manual pointer arithmetic is used instead.
    //
    lock = gpioBaseAddr + GPYLOCK;

    EALLOW;

    if(flags)
    {
        //
        // Lock the pin
        //
        *lock |= pinMask;
    }

    else
    {
        //
        // Unlock the pin
        //
        *lock &= ~pinMask;
    }
    EDIS;
}

//
// External interrupt setup
//
void
GPIO_SetupXINT1Gpio(Uint16 gpioNumber)
{
    EALLOW;
    InputXbarRegs.INPUT4SELECT = gpioNumber;       // Set XINT1 source to GPIO-pin
    EDIS;
}

void
GPIO_SetupXINT2Gpio(Uint16 gpioNumber)
{
    EALLOW;
    InputXbarRegs.INPUT5SELECT = gpioNumber;       // Set XINT2 source to GPIO-pin
    EDIS;
}

void
GPIO_SetupXINT3Gpio(Uint16 gpioNumber)
{
    EALLOW;
    InputXbarRegs.INPUT6SELECT = gpioNumber;       // Set XINT3 source to GPIO-pin
    EDIS;
}
void
GPIO_SetupXINT4Gpio(Uint16 gpioNumber)
{
    EALLOW;
    InputXbarRegs.INPUT13SELECT = gpioNumber;      // Set XINT4 source to GPIO-pin
    EDIS;
}

void
GPIO_SetupXINT5Gpio(Uint16 gpioNumber)
{
    EALLOW;
    InputXbarRegs.INPUT14SELECT = gpioNumber;     // Set XINT5 source to GPIO-pin
    EDIS;
}

//
// GPIO_ReadPin - Read the GPyDAT register bit for the specified pin.
// Note that this returns the actual state of the pin, not the state of the
// output latch.
//
Uint16
GPIO_ReadPin(Uint16 gpioNumber)
{
    volatile Uint32 *gpioDataReg;
    Uint16 pinVal;

    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (gpioNumber/32)*GPY_DATA_OFFSET;
    pinVal = (gpioDataReg[GPYDAT] >> (gpioNumber % 32)) & 0x1;

    return pinVal;
}

//
// GPIO_WritePin - Set the GPyDAT register bit for the specified pin.
//
void
GPIO_WritePin(Uint16 gpioNumber, Uint16 outVal)
{
    volatile Uint32 *gpioDataReg;
    Uint32 pinMask;

    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (gpioNumber/32)*GPY_DATA_OFFSET;
    pinMask = 1UL << (gpioNumber % 32);

    if (outVal == 0)
    {
        gpioDataReg[GPYCLEAR] = pinMask;
    }

    else
    {
        gpioDataReg[GPYSET] = pinMask;
    }
}

//
// End of File
//

