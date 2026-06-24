//###########################################################################
//
// FILE:   f280013x_defaultisr.c
//
// TITLE:  f280013x Device Default Interrupt Service Routines
//
//###########################################################################
// $Copyright:
// Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
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
#include <AFDD.h>                        // Main include file
#include <stdio.h>
#include "f280013x_device.h"       // f280013x Header File Include File
#include "f280013x_examples.h"     // f280013x Examples Include File
#include "math.h"




// CPU Timer 1 Interrupt
//
interrupt void TIMER1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// CPU Timer 2 Interrupt
//
interrupt void TIMER2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// Datalogging Interrupt
//
interrupt void DATALOG_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// RTOS Interrupt from ERAD
//
interrupt void RTOS_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// Emulation Interrupt
//
interrupt void EMU_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// Non-Maskable Interrupt
//
interrupt void NMI_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// Illegal Operation Trap
//
interrupt void ILLEGAL_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 1
//
interrupt void USER1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 2
//
interrupt void USER2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 3
//
interrupt void USER3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 4
//
interrupt void USER4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 5
//
interrupt void USER5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 6
//
interrupt void USER6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 7
//
interrupt void USER7_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 8
//
interrupt void USER8_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 9
//
interrupt void USER9_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 10
//
interrupt void USER10_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 11
//
interrupt void USER11_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// User Defined Trap 12
//
interrupt void USER12_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.1 - ADCA Interrupt 1
//
//void Reset_All_Variables(void)
//{
//    /* ================= State Counters ================= */
//    volt_ok_ctr = 0;
//    calib_ctr   = 0;
//    trip_ctr    = 0;
//
//
//    /* ================= Offset Calibration ================= */
//    offset_caliberated = false;
//    buck_dynamic_pi.burst_active = false;
//    boost_dynamic_pi.burst_active = false;
//
//    BOOST_INPUT_CURRENT.sum    = 0.0f;
//    BOOST_INPUT_CURRENT.offset = 0.0f;
//
//    BUCK_OUTPUT_CURRENT.sum    = 0.0f;
//    BUCK_OUTPUT_CURRENT.offset = 0.0f;
//
//    RY_VOLTAGE.sum = 0.0f;
//    RY_VOLTAGE.offset = 1.65f;
//
//    BY_VOLTAGE.sum = 0.0f;
//    BY_VOLTAGE.offset = 1.65f;
//
//    R_CURRENT.sum = 0.0f;
//    R_CURRENT.offset = 1.675f;
//    B_CURRENT.sum = 0.0f;
//    B_CURRENT.offset = 1.675f;
//
//
//    /* ================= Boost PI ================= */
//    Boost.outer_error      = 0.0f;
//    Boost.outer_error_prev = 0.0f;
//    Boost.inner_error      = 0.0f;
//    Boost.inner_error_prev = 0.0f;
//
//    Boost.Iref             = 0.0f;
//    Boost.Iref_prev        = 0.0f;
//
//    Boost.duty             = 0.0f;
//    Boost.duty_prev        = 0.0f;
//
//    /* ================= Buck PI ================= */
//    Buck.outer_error       = 0.0f;
//    Buck.outer_error_prev  = 0.0f;
//    Buck.inner_error       = 0.0f;
//    Buck.inner_error_prev  = 0.0f;
//
//    Buck.Iref              = 0.0f;
//    Buck.Iref_prev         = 0.0f;
//
//    Buck.duty              = 0.0f;
//    Buck.duty_prev         = 0.0f;
//
//    /* ================= PWM ================= */
//    EPwm1Regs.CMPA.bit.CMPA = 0;
//    EPwm2Regs.CMPA.bit.CMPA = 0;
//
//    /* ================= Fault Latches ================= */
//    fault_type.input_under_vtg_fault  = false;
//    fault_type.input_over_vtg_fault   = false;
//    fault_type.Vdc_2_over_vtg_fault   = false;
//    fault_type.output_over_vtg_fault  = false;
//    fault_type.output_over_curr_fault = false;
//    fault_type.input_over_curr_fault  = false;
//    fault_type.Hardware_trip_Boost_oc = false;
//    fault_type.Hardware_trip_Boost_uc = false;
//    fault_type.Hardware_trip_Buck_oc  = false;
//    fault_type.Hardware_trip_Buck_uc  = false;
//
//
//    buck_dynamic_pi.ref_hit = false;
//    boost_dynamic_pi.ref_hit = false;
//
//}

interrupt void ADCA1_ISR(void){

    I1_out.sense = AdcaResultRegs.ADCRESULT0 * a;
    I2_out.sense = AdccResultRegs.ADCRESULT0 * a;
    I3_out.sense = AdcaResultRegs.ADCRESULT1 * a;
    I4_out.sense = AdccResultRegs.ADCRESULT1 * a;
    Rogowski_coil_1_vtg.sense = AdcaResultRegs.ADCRESULT2 * a;
    Rogowski_coil_2_vtg.sense = AdccResultRegs.ADCRESULT2 * a;
    Rogowski_coil_3_vtg.sense = AdcaResultRegs.ADCRESULT3 * a;
    Rogowski_coil_4_vtg.sense = AdccResultRegs.ADCRESULT3 * a;

    if(offset_calibrated){
        I1_out.actual = (I1_out.sense - I1_out.offset) * I1_out.multiplier;
        I2_out.actual = (I2_out.sense - I2_out.offset) * I2_out.multiplier;
        I3_out.actual = (I3_out.sense - I3_out.offset) * I3_out.multiplier;
        I4_out.actual = (I4_out.sense - I4_out.offset) * I4_out.multiplier;
        Rogowski_coil_1_vtg.actual = (Rogowski_coil_1_vtg.sense - Rogowski_coil_1_vtg.offset) * Rogowski_coil_1_vtg.multiplier;
        Rogowski_coil_2_vtg.actual = (Rogowski_coil_2_vtg.sense - Rogowski_coil_2_vtg.offset) * Rogowski_coil_2_vtg.multiplier;
        Rogowski_coil_3_vtg.actual = (Rogowski_coil_3_vtg.sense - Rogowski_coil_3_vtg.offset) * Rogowski_coil_3_vtg.multiplier;
        Rogowski_coil_4_vtg.actual = (Rogowski_coil_4_vtg.sense - Rogowski_coil_4_vtg.offset) * Rogowski_coil_4_vtg.multiplier;
    }


    switch(currstate){
        case test:{
            break;
        }
        case offset_calibration:{

            ctr++;
            I1_out.sum += I1_out.sense;
            I2_out.sum += I2_out.sense;
            I3_out.sum += I3_out.sense;
            I4_out.sum += I4_out.sense;
            Rogowski_coil_1_vtg.sum += Rogowski_coil_1_vtg.sense;
            Rogowski_coil_2_vtg.sum += Rogowski_coil_2_vtg.sense;
            Rogowski_coil_3_vtg.sum += Rogowski_coil_3_vtg.sense;
            Rogowski_coil_4_vtg.sum += Rogowski_coil_4_vtg.sense;

            if(ctr >= two_sec_cnt){
                I1_out.offset = I1_out.sum / two_sec_cnt;
                I2_out.offset = I2_out.sum / two_sec_cnt;
                I3_out.offset = I3_out.sum / two_sec_cnt;
                I4_out.offset = I4_out.sum / two_sec_cnt;
                Rogowski_coil_1_vtg.offset = Rogowski_coil_1_vtg.sum / two_sec_cnt;
                Rogowski_coil_2_vtg.offset = Rogowski_coil_2_vtg.sum / two_sec_cnt;
                Rogowski_coil_3_vtg.offset = Rogowski_coil_3_vtg.sum / two_sec_cnt;
                Rogowski_coil_4_vtg.offset = Rogowski_coil_4_vtg.sum / two_sec_cnt;
                offset_calibrated = true;
                ctr = 0;
            }

            break;
        }
        case controller_active:{
            switch(state){
                case rogo_1:{

                    fft_1.fft_input[fft_1.fft_index++] = Rogowski_coil_1_vtg.actual;
                    if(fft_1.fft_index >= FFT_SIZE){
                        fft_1.fft_index = 0;
                        fft_1.fft_ready = true;
                    }
                    break;
                }
                case rogo_2:{

                    fft_2.fft_input[fft_2.fft_index++] = Rogowski_coil_2_vtg.actual;
                    if(fft_2.fft_index >= FFT_SIZE){
                        fft_2.fft_index = 0;
                        fft_2.fft_ready = true;
                    }
                    break;
                }
                case rogo_3:{

                    fft_3.fft_input[fft_3.fft_index++] = Rogowski_coil_3_vtg.actual;
                    if(fft_3.fft_index >= FFT_SIZE){
                        fft_3.fft_index = 0;
                        fft_3.fft_ready = true;
                    }
                    break;
                }
                case rogo_4:{

                    fft_4.fft_input[fft_4.fft_index++] = Rogowski_coil_4_vtg.actual;
                    if(fft_4.fft_index >= FFT_SIZE){
                        fft_4.fft_index = 0;
                        fft_4.fft_ready = true;
                    }
                    break;
                }
            }


            break;
        }
        case trip_state:{
            break;
        }
    }

//    ARC_VTG.sense = (AdcaResultRegs.ADCRESULT2 * a);
//
//    if(!flag){
//        ARC_VTG.sum = ARC_VTG.sum + ARC_VTG.sense;
//        ctr++;
//        if(ctr >= 200000){
//            flag = true;
//            ARC_VTG.offset = (ARC_VTG.sum) / 200000.0f;
//        }
//    }
//    else if(flag){
//        ARC_VTG.actual = (ARC_VTG.sense - ARC_VTG.offset) * ARC_VTG.multiplier;
//        waveform_RY[Acc] = ARC_VTG.actual;
//        Acc++;
//        if(Acc >= 200){
//            Acc = 0;
//        }
//
//        fft_input[fft_index++] = ARC_VTG.actual;
//
//        if(fft_index >= FFT_SIZE)
//        {
//            fft_index = 0;
//            fft_ready = true;
//        }
//        if(Energy >= 75.0f){
//
//            arc_ctr++;
//            if(arc_ctr > 10000){
//                Arc = true;
//                Trip_LED_ON;
//            }
//        }
//    }

    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;          // Clear ADCINT1 flag
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;         // Must acknowledge the PIE group

    //--- Manage the ADC registers
}

//
// 1.2 - ADCC Interrupt 1
//
interrupt void ADCC1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.4 - XINT1 Interrupt
//
interrupt void XINT1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.5 - XINT2 Interrupt
//
interrupt void XINT2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.6 - SYS_ERR Interrupt
//
interrupt void SYS_ERR_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.7 - Timer 0 Interrupt
//
interrupt void TIMER0_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 1.8 - Standby and Halt Wakeup Interrupt
//
interrupt void WAKE_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 2.1 - ePWM1 Trip Zone Interrupt
//
interrupt void EPWM1_TZ_ISR(void)
{

//    asm ("      ESTOP0");

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}

//
// 2.2 - ePWM2 Trip Zone Interrupt
//
interrupt void EPWM2_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    //    asm ("      ESTOP0");
    //    for(;;);
}

//
// 2.3 - ePWM3 Trip Zone Interrupt
//
interrupt void EPWM3_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//        asm ("      ESTOP0");
//        for(;;);
}

//
// 2.4 - ePWM4 Trip Zone Interrupt
//
interrupt void EPWM4_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 2.5 - ePWM5 Trip Zone Interrupt
//
interrupt void EPWM5_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 2.6 - ePWM6 Trip Zone Interrupt
//
interrupt void EPWM6_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 2.7 - ePWM7 Trip Zone Interrupt
//
interrupt void EPWM7_TZ_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.1 - ePWM1 Interrupt
//
interrupt void EPWM1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.2 - ePWM2 Interrupt
//
interrupt void EPWM2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.3 - ePWM3 Interrupt
//
interrupt void EPWM3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.4 - ePWM4 Interrupt
//
interrupt void EPWM4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.5 - ePWM5 Interrupt
//
interrupt void EPWM5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.6 - ePWM6 Interrupt
//
interrupt void EPWM6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 3.7 - ePWM7 Interrupt
//
interrupt void EPWM7_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 4.1 - eCAP1 Interrupt
//
interrupt void ECAP1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 4.2 - eCAP2 Interrupt
//
interrupt void ECAP2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 5.1 - eQEP1 Interrupt
//
interrupt void EQEP1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 6.1 - SPIA Receive Interrupt
//
interrupt void SPIA_RX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 6.2 - SPIA Transmit Interrupt
//
interrupt void SPIA_TX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 6.7 - DCC0 Interrupt
//
interrupt void DCC0_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.1 - I2CA Interrupt 1
//
interrupt void I2CA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.2 - I2CA Interrupt 2
//
interrupt void I2CA_FIFO_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.3 - I2CB Interrupt 1
//
interrupt void I2CB_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.4 - I2CB Interrupt 2
//
interrupt void I2CB_FIFO_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.5 - SCIC Receive Interrupt : MCU-LCU UART Communication
//
interrupt void SCIC_RX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 8.6 - SCIC Transmit Interrupt
//
interrupt void SCIC_TX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.1 - SCIA Receive Interrupt : MCU-HMI Communication
//
interrupt void SCIA_RX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.2 - SCIA Transmit Interrupt
//
interrupt void SCIA_TX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.3 - SCIB Receive Interrupt : MCU:RFID Reader EM-18
//
interrupt void SCIB_RX_ISR(void)
{

    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.4 - SCIB Transmit Interrupt
//
interrupt void SCIB_TX_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.5 - CANA Interrupt 0
//
interrupt void CANA0_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 9.6 - CANA Interrupt 1
//
interrupt void CANA1_ISR(void)
{

    // CAN Interrupt Code : End
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

//
// 10.1 - ADCA Event Interrupt
//
interrupt void ADCA_EVT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.2 - ADCA Interrupt 2
//
interrupt void ADCA2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.3 - ADCA Interrupt 3
//
interrupt void ADCA3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.4 - ADCA Interrupt 4
//
interrupt void ADCA4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.5 - ADCC Event Interrupt
//
interrupt void ADCC_EVT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.6 - ADCC Interrupt 2
//
interrupt void ADCC2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.7 - ADCC Interrupt 3
//
interrupt void ADCC3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 10.8 - ADCC Interrupt 4
//
interrupt void ADCC4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 12.1 - XINT3 Interrupt
//
interrupt void XINT3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 12.2 - XINT4 Interrupt
//
interrupt void XINT4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 12.3 - XINT5 Interrupt
//
interrupt void XINT5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// 12.5 - Interrupt from flash sub-system
//
interrupt void FLSS_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group,
    // acknowledge this interrupt.
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
//    asm ("      ESTOP0");
//    for(;;);
}

//
// Catch-all Default ISRs:
//

//
// PIE_RESERVED_ISR - Reserved ISR
//
interrupt void PIE_RESERVED_ISR(void)
{
//    asm ("      ESTOP0");
//    for(;;);
}

//
// EMPTY_ISR - Only does a return
//
interrupt void EMPTY_ISR(void)
{

}

//
// NOTUSED_ISR - Unused ISR
//
interrupt void NOTUSED_ISR(void)
{
//    asm ("      ESTOP0");
//    for(;;);
}

//
// End of File
//

