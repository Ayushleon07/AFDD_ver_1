/*
 * Hardware_tripping.c
 *
 *  Created on: 29-Dec-2025
 *      Author: Kshitij Kumar
 */

#include <ABC.h>    // Main include file

//======================================================================
//  CMPSS ------> EPwm XBar ------> Digital Compare, Trip Zone
//InitCmpss ----> InitXBar -------> InitDigitalComp_Trip
//======================================================================




void InitCmpss(void){
    EALLOW;
//===========================================================================================
//------------ For Buck Output Current sensing on ADC A1 SOC2 : Start ----------------------------
//===========================================================================================

    AnalogSubsysRegs.CMPHPMXSEL.bit.CMP1HPMXSEL = 4;
    AnalogSubsysRegs.CMPLPMXSEL.bit.CMP1LPMXSEL = 4;

    Cmpss1Regs.DACHVALS.bit.DACVAL = 3125;
    Cmpss1Regs.DACLVALS.bit.DACVAL = 1241;

    Cmpss1Regs.COMPDACHCTL.bit.DACSOURCE = 0;
    Cmpss1Regs.COMPDACHCTL.bit.SWLOADSEL = 0;

    Cmpss1Regs.COMPCTL.bit.COMPHSOURCE = 0;
    Cmpss1Regs.COMPCTL.bit.COMPLSOURCE = 0;

    Cmpss1Regs.COMPCTL.bit.COMPHINV = 0;
    Cmpss1Regs.COMPCTL.bit.COMPLINV = 1;

    Cmpss1Regs.COMPCTL.bit.CTRIPHSEL = 2;
    Cmpss1Regs.COMPCTL.bit.CTRIPLSEL = 2;

    Cmpss1Regs.COMPCTL.bit.ASYNCHEN = 0;
    Cmpss1Regs.COMPCTL.bit.ASYNCLEN = 0;

    Cmpss1Regs.COMPHYSCTL.bit.COMPHYS = 1;


//    Configuring Digital Filter
    //For COMPH comparator
    Cmpss1Regs.CTRIPHFILCLKCTL = 5;             // High filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.
    Cmpss1Regs.CTRIPLFILCLKCTL = 5;             // High filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.

    Cmpss1Regs.CTRIPHFILCTL.bit.SAMPWIN = 9;    // High filter sample window size
    Cmpss1Regs.CTRIPLFILCTL.bit.SAMPWIN = 9;    // High filter sample window size

    Cmpss1Regs.CTRIPHFILCTL.bit.THRESH = 5;     // High filter majority voting threshold
    Cmpss1Regs.CTRIPLFILCTL.bit.THRESH = 5;     // High filter majority voting threshold

    Cmpss1Regs.CTRIPHFILCTL.bit.FILINIT = 1;    // High filter initialization
    Cmpss1Regs.CTRIPLFILCTL.bit.FILINIT = 1;    // High filter initialization

    Cmpss1Regs.COMPCTL.bit.COMPDACE = 1;
//===========================================================================================
//------------ For Buck Output Current sensing on ADC A1 SOC2 : End ----------------------------
//===========================================================================================





//===========================================================================================
//------------ For Boost Input Current sensing on ADC C1 SOC0 : Start ---------------------------
//===========================================================================================
    AnalogSubsysRegs.CMPHPMXSEL.bit.CMP2HPMXSEL = 1;    // Route CMP2 High-side input (CMP2H)
    AnalogSubsysRegs.CMPLPMXSEL.bit.CMP2LPMXSEL = 1;    // Route CMP2 High-side input (CMP2H)

    CmpssLite2Regs.DACHVALS.bit.DACVAL = 3125;
    CmpssLite2Regs.DACLVALS.bit.DACVAL = 1241;

    CmpssLite2Regs.COMPDACHCTL.bit.SWLOADSEL = 0;

    CmpssLite2Regs.COMPCTL.bit.COMPHSOURCE = 0;
    CmpssLite2Regs.COMPCTL.bit.COMPLSOURCE = 0;

    CmpssLite2Regs.COMPCTL.bit.COMPHINV = 0;
    CmpssLite2Regs.COMPCTL.bit.COMPLINV = 1;

    CmpssLite2Regs.COMPCTL.bit.CTRIPHSEL = 2;
    CmpssLite2Regs.COMPCTL.bit.CTRIPLSEL = 2;

    CmpssLite2Regs.COMPCTL.bit.ASYNCHEN = 0;
    CmpssLite2Regs.COMPCTL.bit.ASYNCLEN = 0;

    CmpssLite2Regs.COMPHYSCTL.bit.COMPHYS = 1;

//    Configuring Digital Filter
    //For COMPH comparator
    CmpssLite2Regs.CTRIPHFILCLKCTL = 5;             // High filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.
    CmpssLite2Regs.CTRIPLFILCLKCTL = 5;             // High filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.

    CmpssLite2Regs.CTRIPHFILCTL.bit.SAMPWIN = 9;    // High filter sample window size
    CmpssLite2Regs.CTRIPLFILCTL.bit.SAMPWIN = 9;    // High filter sample window size

    CmpssLite2Regs.CTRIPHFILCTL.bit.THRESH = 5;     // High filter majority voting threshold
    CmpssLite2Regs.CTRIPLFILCTL.bit.THRESH = 5;     // High filter majority voting threshold

    CmpssLite2Regs.CTRIPHFILCTL.bit.FILINIT = 1;    // High filter initialization
    CmpssLite2Regs.CTRIPLFILCTL.bit.FILINIT = 1;    // High filter initialization

    CmpssLite2Regs.COMPCTL.bit.COMPDACE = 1;
//===========================================================================================
//------------ For Boost Input Current sensing on ADC C1 SOC0 : End ----------------------------
//===========================================================================================

    EDIS;
}



void InitXBar(void){
    EALLOW;
//============================================================================
//--------------- Used TRIP4 (MUX - 0,1) (CMPSS 1 -> Buck Output Current) ---------
//============================================================================
    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX0 = 1;
    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0 = 0;
//----------------------------------------------------------------------------




//============================================================================
//--------------- Used TRIP4 (MUX - 0,1) (CMPSS 2 -> Boost Input Current) --------
//============================================================================
    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX2 = 1;
    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX2 = 0;
//----------------------------------------------------------------------------

    EPwmXbarRegs.TRIPOUTINV.bit.TRIP4 = 0;
    EDIS;
}


void InitDigitalComp_Trip(void){
    EALLOW;
    // Digital Compare configuration (Buck Output current)
    EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL = 3;        // TRIP4 select
    EPwm1Regs.TZDCSEL.bit.DCAEVT1 = 2;              // Digital Compare Output A Event 1 Selection | 2 -> DCAH = high, DCAL = don't care
    EPwm1Regs.DCACTL.bit.EVT1SRCSEL = 0;            // DCAEVT1 Source Signal Select | 0 -> Source Is DCAEVT1 Signal
    EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL = 1;        // DCAEVT1 Force Synchronization Signal Select | 1 -> asynchronously
    EPwm1Regs.DCACTL.bit.EVT1LATSEL = 1;            // DCAEVT1 Latched signal select: 0: Does not select the DCAEVT1 latched signal as source of DCAEVT1.force.
    EPwm1Regs.DCACTL.bit.EVT1SOCE = 0;              // SOC generation Disabled
    EPwm1Regs.DCACTL.bit.EVT1SYNCE = 0;             // Synch disabled

    // Digital Compare configuration (Boost Input current)
    EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL = 3;        // TRIP4 select
    EPwm2Regs.TZDCSEL.bit.DCAEVT1 = 2;              // Digital Compare Output A Event 1 Selection | 2 -> DCAH = high, DCAL = don't care
    EPwm2Regs.DCACTL.bit.EVT1SRCSEL = 0;            // DCAEVT1 Source Signal Select | 0 -> Source Is DCAEVT1 Signal
    EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL = 1;        // DCAEVT1 Force Synchronization Signal Select | 1 -> asynchronously
    EPwm2Regs.DCACTL.bit.EVT1LATSEL = 1;            // DCAEVT1 Latched signal select: 0: Does not select the DCAEVT1 latched signal as source of DCAEVT1.force.
    EPwm2Regs.DCACTL.bit.EVT1SOCE = 0;              // SOC generation Disabled
    EPwm2Regs.DCACTL.bit.EVT1SYNCE = 0;             // Synch disabled


    // TRIP ZONE Programming
    // Buck Output current
    EPwm1Regs.TZCTL2.bit.ETZE = 1;              // TZCTL2 Enable | 1 -> Use trip action defined in TZCTL2, TZCTLDCA and TZCTLDCB
    EPwm1Regs.TZCTLDCA.bit.DCAEVT1D = 2;        // Action on EPWMxA - Forced Low
    EPwm1Regs.TZCTLDCA.bit.DCAEVT1U = 2;        // Action on EPWMxA - Forced Low
    EPwm1Regs.TZCTLDCB.bit.DCBEVT1D = 2;        // Action on EPWMxB - Forced Low
    EPwm1Regs.TZCTLDCB.bit.DCBEVT1U = 2;        // Action on EPWMxB - Forced Low
//    EPwm1Regs.DCACTL.bit.rsvd1 = 1;
    EPwm1Regs.TZCTL2.bit.TZAU = 2;
    EPwm1Regs.TZCTL2.bit.TZAD = 2;
    EPwm1Regs.TZCTL2.bit.TZBD = 2;
    EPwm1Regs.TZCTL2.bit.TZBU = 2;
    EPwm1Regs.TZSEL.bit.DCAEVT1 = 1;            // Enable DCAEVT1 as one-shot-trip source for this ePWM module.
    EPwm1Regs.TZEINT.bit.DCAEVT1 = 1;           // DCAEVT1 interrupt enable


    // Boost Input current
    EPwm2Regs.TZCTL2.bit.ETZE = 1;              // TZCTL2 Enable | 1 -> Use trip action defined in TZCTL2, TZCTLDCA and TZCTLDCB
    EPwm2Regs.TZCTLDCA.bit.DCAEVT1D = 2;        // Action on EPWMxA - Forced Low
    EPwm2Regs.TZCTLDCA.bit.DCAEVT1U = 2;        // Action on EPWMxA - Forced Low
    EPwm2Regs.TZCTLDCB.bit.DCBEVT1D = 2;        // Action on EPWMxB - Forced Low
    EPwm2Regs.TZCTLDCB.bit.DCBEVT1U = 2;        // Action on EPWMxB - Forced Low
//    EPwm2Regs.DCACTL.bit.rsvd1 = 1;
    EPwm2Regs.TZCTL2.bit.TZAU = 2;
    EPwm2Regs.TZCTL2.bit.TZAD = 2;
    EPwm2Regs.TZCTL2.bit.TZBD = 2;
    EPwm2Regs.TZCTL2.bit.TZBU = 2;
    EPwm2Regs.TZSEL.bit.DCAEVT1 = 1;            // Enable DCAEVT1 as one-shot-trip source for this ePWM module.
    EPwm2Regs.TZEINT.bit.DCAEVT1 = 1;           // DCAEVT1 interrupt enable



    EDIS;
}

