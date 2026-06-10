
/**********************************************************************
Code   : Main C file for Single Phase Single MPPT GTSI
Author : Ayush Dinkar
Author : Aman Kumar
**********************************************************************/
#include <AFDD.h>    // Main include file
#include "fft.h"

//**********************************************************************
//--- Global Variables---
//**********************************************************************
complex_t x[FFT_SIZE];
float magnitude[FFT_SIZE / 2];
float max_magnitude[FFT_SIZE / 2] = {0.0f};
float ranged_magnitude[range];
float fft_input[FFT_SIZE];
//**********************************************************************
//--- Test Variables---
//**********************************************************************
Uint16 Acc = 0;
float waveform_RY[200] = {0.0f};

ac_parameters ARC_VTG = {
          .sense = 0.0f,
          .offset = 1.65f,
          .multiplier = 1.0f,
          .sum = 0.0f,
          .actual = 0.0f
};

Uint32 ctr = 0;
bool flag = false;
Uint16 fft_index = 0;
bool fft_ready = false;
float Energy = 0.0f;
bool Reset = false;
bool Arc = false;
Uint32 arc_ctr = 0;
float Max_energy = 10.0f;


void main(void)
{

    //--- CPU Initialization
    //    SysCtl_setClock(DEVICE_SETCLOCK_CFG);
    //    // Make sure the LSPCLK divider is set to the default (divide by 4)
    //    SysCtl_setLowSpeedClock(SYSCTL_LSPCLK_PRESCALE_4);

    InitSysCtrl();                      // Initialize the CPU (FILE: f28002x_sysCtrl.c)
    InitGpio();                         // Initialize the shared GPIO pins (FILE: f28002x_gpio.c)
    DINT;
    InitPieCtrl();                      // Initialize and enable the PIE (FILE: PieCtrl.c)
//    InitWatchdog();                   // Initialize the Watchdog Timer (FILE: WatchDog.c)

    //Initialize the Flash
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    //
    // Call Flash Initialization to setup flash wait states. This function must
    // reside in RAM.
    //
    InitFlash();

    // Disable CPU interrupts and clear all CPU interrupt flags:
    IER = 0x0000;
    IFR = 0x0000;

    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    InitPieVectTable();

    // Map ISR functions
    EALLOW;
    PieVectTable.ADCA1_INT = &ADCA1_ISR;        // Function for ADCA interrupt 1
    PieVectTable.EPWM1_TZ_INT = &EPWM1_TZ_ISR;  // Function for EPWM1_TZ interrupt
    EDIS;

    //--- Peripheral Initialization

    InitEPwm();                                     // Initialize the EPwm (FILE: EPwm.c)
    initADC();                                      // Initialize the ADC-A (FILE: Adc.c)
//    LcdInit();

//    SCIA_init();
    // Interrupt Enable for ADC A1
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;              // ADC A1 Interrupt
    IER |= 0x0001;                                  // Enable INT1 in IER to enable PIE group 1
    // Enable PIE interrupt


    //--- Enable global interrupts
    EINT;           // Enable Global interrupt INTM
    ERTM;           // Enable Global realtime interrupt DBGM


    compute_twiddles();
    compute_window();

    while(1){
        if(fft_ready)
        {
            GpioDataRegs.GPASET.bit.GPIO16 = 1;
            apply_window(x, fft_input);
            bit_reversal(x);
            fft_dit(x);
            compute_magnitude(x, magnitude);
            GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;
            compute_range_magnitude(x, ranged_magnitude, 10000.0f, 20000.0f);
            Energy = compute_band_energy(x, 10000.0f, 20000.0f);

            fft_ready = false;
        }



    } //end of while(true)
}  //end of main

