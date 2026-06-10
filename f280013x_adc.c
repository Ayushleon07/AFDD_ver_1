//###########################################################################
//
// FILE:    f280013x_adc.c
//
// TITLE:   F28002x ADC Support Functions.
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
#include <ABC.h>                        // Main include file
#include "f280013x_device.h"      // Header File Include File
#include "f280013x_examples.h"    // Examples Include File
#include "f28x_project.h"
//
// SetVREF - Set Vref mode. Function to select reference mode and offset trim.
// Offset trim for Internal VREF 3.3 is unique.  All other modes use the same
// offset trim. Also note that when the mode parameter is ADC_EXTERNAL, the
// ref parameter has no effect.
//
// In this device, the bandgaps are common for all the ADC instances,
// hence common Vref configuration needs to be done for all the ADCs. This
// API configures same Vref configuration for all the supported ADCs in the
// device.
//
void SetVREF(int module, int mode, int ref)
{
    Uint16 *offset, offsetShiftVal;

    if((mode == ADC_INTERNAL) && (ref == ADC_VREF3P3))
    {
        offsetShiftVal = 8U;         // Internal / 1.65v mode offset
    }
    else
    {
        offsetShiftVal = 0U;        // All other modes
    }

    //
    // Set up pointer to offset trim in OTP for ADCA.
    //
    offset = (Uint16 *)((Uint32)0x7016CU);

    EALLOW;

    //
    // Get offset trim from OTP and write it to the register for ADCA.
    //
    AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (*offset >> offsetShiftVal) & 0xFFU;

    //
    // Set up pointer to offset trim in OTP for ADCC.
    //
    offset = (Uint16 *)((Uint32)0x7016EU);

    //
    // Get offset trim from OTP and write it to the register for ADCC.
    //
    AdccRegs.ADCOFFTRIM.bit.OFFTRIM = (*offset >> offsetShiftVal) & 0xFFU;

    //
    // Configure the reference mode for all ADCs (internal or external).
    //
    AnalogSubsysRegs.ANAREFCTL.bit.ANAREFSEL = mode;

    //
    // Configure the reference voltage for all ADCs (3.3V or 2.5V).
    //
    AnalogSubsysRegs.ANAREFCTL.bit.ANAREF2P5SEL = ref;

    EDIS;
}


void initADC(void)
{

    asm(" EALLOW");                     // Enable EALLOW protected register access

// ################################################################################################
// --------------------------------   Resetting ADCs - A and C  -----------------------------------
// ################################################################################################

    //******* Resetting the ADCs A, C: START *******

    DevCfgRegs.SOFTPRES13.bit.ADC_A         = 1;    // ADC A is reset
    DevCfgRegs.SOFTPRES13.bit.ADC_A         = 0;    // ADC A is released from reset

    DevCfgRegs.SOFTPRES13.bit.ADC_C         = 1;    // ADC C is reset
    DevCfgRegs.SOFTPRES13.bit.ADC_C         = 0;    // ADC C is released from reset

    //******** Resetting the ADCs A, C: END ********

// ################################################################################################
// ----------------------------    Configure the ADC base register  -------------------------------
// ################################################################################################

    // ------ Configuring ADC A, ADC C Control-1 Register: START -------

    AdcaRegs.ADCCTL1.all                    = 0x0004;      // Main ADC A configuration
    AdccRegs.ADCCTL1.all                    = 0x0004;      // Main ADC C configuration

    // bit 15-14     00:     reserved
    // bit 13        0:      ADCBSY, ADC busy, read-only
    // bit 12        0:      reserved
    // bit 11-8      0's:    ADCBSYCHN, ADC busy channel, read-only
    // bit 7         0:      ADCPWDNZ, ADC power down, 0=powered down, 1=powered up
    // bit 6-3       0000:   reserved
    // bit 2         1:      INTPULSEPOS, INT pulse generation, 0=start of conversion, 1=end of conversion
    // bit 1-0       00:     reserved

    // ------ Configuring ADC A, ADC C Control-1 Register: END -------

    // ------ Configuring ADC A, ADC C Control-2 Register: START ------

    AdcaRegs.ADCCTL2.all                    = 0x0006;      // ADC A clock configuration (Set to 25MHz)
    AdccRegs.ADCCTL2.all                    = 0x0006;      // ADC C clock configuration (Set to 25MHz)

    // bit 15-8      0's:    reserved
    // bit 7         0:      reserved
    // bit 6         0:      reserved
    // bit 5-4       00:     reserved
    // bit 3-0       0110:   PRESCALE, ADC clock prescaler.  0110=CPUCLK/4 = 120MHz/4 = 30MHz

    // ------- Configuring ADC A, ADC C Control-2 Register: END -------

    // ------ Configuring ADC A, ADC C Burst Control Register (ADCBURSTCTL): START ------

    AdcaRegs.ADCBURSTCTL.all                = 0x0000;
    AdccRegs.ADCBURSTCTL.all                = 0x0000;

    // bit 15        0:      BURSTEN, 0=burst mode disabled, 1=burst mode enabled
    // bit 14-12     000:    reserved
    // bit 11-8      0000:   BURSTSIZE, 0=1 SOC converted (don't care)
    // bit 7-6       00:     reserved
    // bit 5-0       000000: BURSTTRIGSEL, 00=software only (don't care)

    // ------- Configuring ADC A, ADC C Burst Control Register (ADCBURSTCTL): END -------


    asm(" EDIS");                               // Disable EALLOW protected register access

    // --------  Set Vref as Internal with 0 to 3.3V Range: START ----------

    SetVREF(ADC_ADCA, ADC_INTERNAL, ADC_VREF3P3);
    SetVREF(ADC_ADCC, ADC_INTERNAL, ADC_VREF3P3);


// ################################################################################################
// -------------------   SOC Configure for the 4 ADC Groups (A, B, C, D)   ------------------------
// ################################################################################################

    asm(" EALLOW");                     // Enable EALLOW protected register access

    //----- SOC (SOC0, SOC1, SOC2...) Configuration for ADC A: START -----

    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC0CTL.bit.CHSEL   = 14;               // ADC A14 I1_out current
    AdcaRegs.ADCSOC0CTL.bit.ACQPS   = 9;

    AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC1CTL.bit.CHSEL   = 2;                // ADC A2: I3_out current
    AdcaRegs.ADCSOC1CTL.bit.ACQPS   = 9;

    AdcaRegs.ADCSOC2CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC2CTL.bit.CHSEL   = 11;               // ADC A11: Rogowski_coil_1
    AdcaRegs.ADCSOC2CTL.bit.ACQPS   = 9;

    AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC3CTL.bit.CHSEL   = 1;                // ADC A1: Rogowski_coil_3
    AdcaRegs.ADCSOC3CTL.bit.ACQPS   = 9;

//    AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
//    AdcaRegs.ADCSOC3CTL.bit.CHSEL   = 8;              // ADC A8: Heat Sink
//    AdcaRegs.ADCSOC3CTL.bit.ACQPS   = 9;


//    AdcaRegs.ADCSOC5CTL.bit.TRIGSEL = 5;
//    AdcaRegs.ADCSOC5CTL.bit.CHSEL   = 3;              // ADC A3: BY VOLTAGE
//    AdcaRegs.ADCSOC5CTL.bit.ACQPS   = 9;

//    AdcaRegs.ADCSOC6CTL.bit.TRIGSEL = 5;
//    AdcaRegs.ADCSOC6CTL.bit.CHSEL   = 6;              // ADC A6: Arc vtg
//    AdcaRegs.ADCSOC6CTL.bit.ACQPS   = 9;



//----- SOC (SOC0, SOC1, SOC2...) Configuration for ADC A: END -----

    //----- SOC (SOC0, SOC1, SOC2...) Configuration for ADC C: START -----
    AdccRegs.ADCSOC0CTL.bit.TRIGSEL = 5;
    AdccRegs.ADCSOC0CTL.bit.CHSEL   = 7;                // ADC C7: I2_out current
    AdccRegs.ADCSOC0CTL.bit.ACQPS   = 9;

    AdccRegs.ADCSOC1CTL.bit.TRIGSEL = 5;
    AdccRegs.ADCSOC1CTL.bit.CHSEL   = 5;                // ADC C5: I4_out current
    AdccRegs.ADCSOC1CTL.bit.ACQPS   = 9;

    AdccRegs.ADCSOC2CTL.bit.TRIGSEL = 5;
    AdccRegs.ADCSOC2CTL.bit.CHSEL   = 2;                // ADC C2: Rogowski_coil_2
    AdccRegs.ADCSOC2CTL.bit.ACQPS   = 9;


    AdccRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
    AdccRegs.ADCSOC3CTL.bit.CHSEL   = 15;                // ADC C15: Rogowski_coil_4
    AdccRegs.ADCSOC3CTL.bit.ACQPS   = 9;


//    AdccRegs.ADCSOC4CTL.bit.TRIGSEL = 5;
//    AdccRegs.ADCSOC4CTL.bit.CHSEL   = 6;              // ADC C6: RY VOLTAGE
//    AdccRegs.ADCSOC4CTL.bit.ACQPS   = 9;

//    AdccRegs.ADCSOC5CTL.bit.TRIGSEL = 5;
//    AdccRegs.ADCSOC5CTL.bit.CHSEL   = 3;              // ADC C3: B CURRENT
//    AdccRegs.ADCSOC5CTL.bit.ACQPS   = 9;

    //----- SOC (SOC0, SOC1, SOC2...) Configuration for ADC C: END -----

// ################################################################################################
// ----------------------------   Triggring the ADC Interrupts   ---------------------------------
// ################################################################################################

    //----- Triggering ADC Interrupts: START -----

    AdcaRegs.ADCINTSOCSEL1.bit.SOC0         = 0;                // No ADCINT will trigger SOC0
    AdcaRegs.ADCINTSOCSEL1.bit.SOC1         = 0;                // No ADCINT will trigger SOC1
    AdcaRegs.ADCINTSOCSEL1.bit.SOC2         = 0;                // No ADCINT will trigger SOC2
    AdcaRegs.ADCINTSOCSEL1.bit.SOC3         = 0;                // No ADCINT will trigger SOC3
//    AdcaRegs.ADCINTSOCSEL1.bit.SOC4         = 0;                // No ADCINT will trigger SOC4
//    AdcaRegs.ADCINTSOCSEL1.bit.SOC5         = 0;                // No ADCINT will trigger SOC5
//    AdcaRegs.ADCINTSOCSEL1.bit.SOC6         = 0;                // No ADCINT will trigger SOC5

    AdccRegs.ADCINTSOCSEL1.bit.SOC0         = 0;                // No ADCINT will trigger SOC0
    AdccRegs.ADCINTSOCSEL1.bit.SOC1         = 0;                // No ADCINT will trigger SOC1
    AdccRegs.ADCINTSOCSEL1.bit.SOC2         = 0;                // No ADCINT will trigger SOC2
    AdccRegs.ADCINTSOCSEL1.bit.SOC3         = 0;                // No ADCINT will trigger SOC3
//    AdccRegs.ADCINTSOCSEL1.bit.SOC4         = 0;                // No ADCINT will trigger SOC4
//    AdccRegs.ADCINTSOCSEL1.bit.SOC5         = 0;                // No ADCINT will trigger SOC5

    //----- Triggering ADC Interrupts: END -----

// ################################################################################################
// --------------------------------   SOC Priority Selection   ------------------------------------
// ################################################################################################

    //----- SOC Priority Selection for ADC SOC Channels: START -----

    AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY   = 0;  // SOC priority mode
    AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY   = 0;  // SOC priority mode

    //----- SOC Priority Selection for ADC SOC Channels: END -----

// ################################################################################################
// ------------------------------   ADC Interrupt Configuration   ---------------------------------
// ################################################################################################

    //----- Configuring ADC A Interrupt-1 and disable ADC C interrupts  : START -----

     AdcaRegs.ADCINTSEL1N2.bit.INT1CONT      = 1;     // Interrupt pulses
     AdcaRegs.ADCINTSEL1N2.bit.INT1E         = 1;     // ADC A interrupt enable
     AdcaRegs.ADCINTSEL1N2.bit.INT1SEL       = 3;     // EOC3 triggers the interrupt

     AdccRegs.ADCINTSEL1N2.bit.INT1E         = 0;     // ADC C interrupt disable

    //----- Configuring ADC A Interrupt-1 and disable ADC C interrupts  : END -----


// ################################################################################################
// ----------------------------------------   Power UP the ADCs --------------------------------
// ################################################################################################

      //******** Powering Up ADCs : START *******

      AdcaRegs.ADCCTL1.bit.ADCPWDNZ           = 1;          // Power up the ADC A
      AdccRegs.ADCCTL1.bit.ADCPWDNZ           = 1;          // Power up the ADC C

      //******** Powering Up ADCs : END *******

      //******** Waiting Period after Power-Up the ADCs : START *******

      DELAY_US(1000);                              // Wait 1 ms after power-up before using the ADC

      //******** Waiting Period after Power-Up the ADCs : END *******

        asm(" EDIS");                               // Disable EALLOW protected register access
     InitCmpss();                               // CMPSS configration


}

//
// End of File
//
