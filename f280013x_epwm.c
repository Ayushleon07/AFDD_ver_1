//=============================================================================
// Author : Ayush Dinkar
// PWM Module for 4 Bi-Directional Switches
// Switching Frequency : 200 kHz
//=============================================================================

#include <ABC.h>     // Main include file


//=============================================================================
// Function : InitEPwm()
// Purpose  : Initializes the Enhanced PWM modules on the F28x7x
//=============================================================================
void InitEPwm(void)
{
    //-------------------------------------------------------------------------
    // Disable TBCLK Synchronization
    //
    // Must disable TBCLKSYNC before configuring ePWM modules.
    // Re-enable after all ePWM modules are configured to ensure synchronization.
    //-------------------------------------------------------------------------
    asm(" EALLOW");
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC         = 0;
    asm(" EDIS");


    //-------------------------------------------------------------------------
    // Reset ePWM Modules
    //-------------------------------------------------------------------------
    asm(" EALLOW");

    DevCfgRegs.SOFTPRES2.bit.EPWM1           = 1;
    DevCfgRegs.SOFTPRES2.bit.EPWM1           = 0;

    DevCfgRegs.SOFTPRES2.bit.EPWM2           = 1;
    DevCfgRegs.SOFTPRES2.bit.EPWM2           = 0;

    asm(" EDIS");


    //-------------------------------------------------------------------------
    // EPWM1 Configuration: Start
    // PWM1A : I_out_1
    // PWM1B : I_out_2
    // ADC Sampling Trigger
    //-------------------------------------------------------------------------

    // Disable Timer
    EPwm1Regs.TBCTL.bit.CTRMODE             = 3;

    // Time-Base Configuration
    EPwm1Regs.TBCTL.bit.HSPCLKDIV           = 0;
    EPwm1Regs.TBCTL.bit.CLKDIV              = 1;

    EPwm1Regs.TBCTR                         = 0;
    EPwm1Regs.TBPRD                         = Tbprd;      // 200 kHz Switching frequency

    // PWM1A Output
    EPwm1Regs.CMPA.bit.CMPA                 = 0;
    EPwm1Regs.AQCTLA.bit.CAU                = 2;
    EPwm1Regs.AQCTLA.bit.CAD                = 1;

    // PWM1B Output
    EPwm1Regs.CMPB.bit.CMPB                 = 0;
    EPwm1Regs.AQCTLB.bit.CBU                = 2;
    EPwm1Regs.AQCTLB.bit.CBD                = 1;

    // ADC SOCA Trigger
    EPwm1Regs.ETSEL.bit.SOCAEN              = 1;
    EPwm1Regs.ETSEL.bit.SOCASEL             = 1;        // CTR = ZRO
    EPwm1Regs.ETPS.bit.SOCAPRD              = 1;        // Sampling frequency = Switching frequency

    // Synchronization
    EPwm1Regs.TBCTL.bit.PHSEN               = 0;
    EPwm1Regs.EPWMSYNCOUTEN.bit.ZEROEN      = 1;

    // Enable Timer (Up-Down Count Mode)
    EPwm1Regs.TBCTL.bit.CTRMODE             = 0x2;

    //-------------------------------------------------------------------------
    // EPWM1 Configuration: End
    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    // EPWM2 Configuration: Start
    // PWM2A : I_out_3
    // PWM2B : I_out_4
    //-------------------------------------------------------------------------

    // Disable Timer
    EPwm2Regs.TBCTL.bit.CTRMODE             = 3;

    // Time-Base Configuration
    EPwm2Regs.TBCTL.bit.HSPCLKDIV           = 0;
    EPwm2Regs.TBCTL.bit.CLKDIV              = 1;

    EPwm2Regs.TBCTR                         = 0;
    EPwm2Regs.TBPRD                         = Tbprd;    // 200 kHz Switching frequency

    // PWM2A Output
    EPwm2Regs.CMPA.bit.CMPA                 = 0;
    EPwm2Regs.AQCTLA.bit.CAU                = 1;
    EPwm2Regs.AQCTLA.bit.CAD                = 2;

    // PWM2B Output
    EPwm2Regs.CMPB.bit.CMPB                 = 0;
    EPwm2Regs.AQCTLB.bit.CBU                = 1;
    EPwm2Regs.AQCTLB.bit.CBD                = 2;

    // Synchronization
    EPwm2Regs.EPWMSYNCINSEL.bit.SEL         = 1;

    EPwm2Regs.TBCTL.bit.PHSEN               = 1;
    EPwm2Regs.TBCTL.bit.PHSDIR              = 1;
    EPwm2Regs.TBPHS.bit.TBPHS               = 0;

    // Enable Timer (Up-Down Count Mode)
    EPwm2Regs.TBCTL.bit.CTRMODE             = 0x2;

    //-------------------------------------------------------------------------
    // EPWM2 Configuration: End
    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    // Interrupt Configuration
    //-------------------------------------------------------------------------
    asm(" EALLOW");

    PieCtrlRegs.PIEIER2.bit.INTx1           = 1;       // Trip ISR
    IER                                    |= 0x0002;

    asm(" EDIS");


    //-------------------------------------------------------------------------
    // Enable TBCLK Synchronization
    //-------------------------------------------------------------------------
    asm(" EALLOW");

    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC         = 1;

    asm(" EDIS");
}


//=============================================================================
// End of File
//=============================================================================
