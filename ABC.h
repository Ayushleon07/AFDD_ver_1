
/**********************************************************************
* File: Self Defined.h
  Self Defined Header File

**********************************************************************/
#ifndef LAB_H
#define LAB_H
#include "f280013x_device.h"
#include "fft.h"


// Include Standard C Language Header Files
// (Header file <string.h> not supported by CLA compiler)
//
#if !defined(__TMS320C28XX_CLA__)
    #include <string.h>
#endif



//---------------------------------------------------------------------------
// Include any other Header Files
//
//#include "F2837xD_Cla_typedefs.h"        // CLA type definitions
//#include "F2837xD_device.h"              // F2837xD header file peripheral address definitions
//#include "F2837xD_Adc_defines.h"         // ADC definitions
//#include "F2837xD_defaultisr.h"          // ISR definitions
//#include "F2837xD_Pie_defines.h"         // PIE definitions

#include "f280013x_examples.h"    // F280013x Examples Include File
#include "f280013x_device.h"      // f280013x Headerfile Include File


//---------------------------------------------------------------------------
// Function Prototypes
//
extern void Delay_ms(Uint16);
extern void Delay_us(Uint32);
extern void AdcSetMode(Uint16, Uint16, Uint16);
extern void CalAdcINL(Uint16);
extern void DelayUs(Uint16);
extern void initADC(void);
extern void InitCla(void);
extern void InitDacb(void);
extern void InitDaca(void);
extern void InitDacc(void);
extern void InitDma(void);
extern void InitECap(void);
extern void InitEPwm(void);
extern void InitFlash(void);
extern void InitGpio(void);
extern void InitPieCtrl(void);
extern void InitSysCtrl(void);
extern void InitWatchdog(void);
extern void InitCanaChargerDriverLib(void);
extern void InitCmpss(void);
extern void InitXBar(void);
extern void InitDigitalComp_Trip(void);
extern void Reset_All_Variables(void);

//====== FOR LCD =================
extern void SCIA_init(void);
extern void SCIAWrite(char *string);
extern void Uart_printval(char *dataDisplay, float value);
extern void float_to_str_1dp(float value, char *buf);
extern void append_param(char *frame, float value);
extern void UART_SendAllParams(void);


//====== FOR LCD =================
extern Uint16 stringLen(char* ipStr);
extern void LcdInit(void);
extern void Lcd_Cmd(unsigned char value);
extern void LcdData(unsigned char value);
extern void Lcd_out(Uint16 rowNumber, Uint16 colNumber, char* dataDisplay);
extern void Lcd_CreateCustomChar(Uint16 location, unsigned char* pattern);
extern void Lcd_printval(Uint16 rowNumber, Uint16 colNumber, float value, char* unit);
extern void Lcd_test(void);
extern void Lcd_fault(void);

//extern void Lcd_input_vals(void);

// Test Code Varibles
extern Uint16 mainRelay_cmd;
extern Uint16 batteryRelay_cmd;

extern Uint16 led1_cmd;
extern Uint16 led2_cmd;
extern Uint16 led3_cmd;
extern Uint16 led4_cmd;

extern Uint16 mainRelay_status;
extern Uint16 batteryRelay_status;

extern Uint16 led1_status;
extern Uint16 led2_status;
extern Uint16 led3_status;
extern Uint16 led4_status;

// -------- Input status variables -----------
extern Uint16 sw1_status;
extern Uint16 sw2_status;
extern Uint16 sw3_status;
extern Uint16 sw4_status;


//---------------------------------------------------------------------------
// CLA Function Prototypes
//
extern interrupt void Cla1Task1();
extern interrupt void Cla1Task2();
extern interrupt void Cla1Task3();
extern interrupt void Cla1Task4();
extern interrupt void Cla1Task5();
extern interrupt void Cla1Task6();
extern interrupt void Cla1Task7();
extern interrupt void Cla1Task8();


//---------------------------------------------------------------------------
// Global symbols defined in the linker command file
//
extern Uint16 cla1Funcs_loadstart;
extern Uint16 cla1Funcs_loadsize;
extern Uint16 cla1Funcs_runstart;
extern Uint16 secureRamFuncs_loadstart;
extern Uint16 secureRamFuncs_loadsize;
extern Uint16 secureRamFuncs_runstart;
extern Uint16 Cla1Prog_Start;

//---------------------------------------------------------------------------
// Global Variables References
//
extern const struct PIE_VECT_TABLE PieVectTableInit;    // PieVectTableInit is always extern



#define FS        200000.0f                         // 200 kHz
#define a 0.0008056640625f       //       (3.3f / 4096.0f)
#define ainv 1241.2121f          //
#define T0 0.0033557047          //       (1.0f / 298.0f)
#define beta 0.00025144581       //       (1.0f / 3977.0f)
#define R0 10000.0f
#define Rf 273.0f
#define isr_freq (100000 / 3)
#define one_sec_cnt (Uint32)(1.0f * FS)
#define two_sec_cnt (Uint32)(2.0f * isr_freq)
#define three_sec_cnt (Uint32)(2.0f * isr_freq)
#define five_sec_cnt (Uint32)(5.0f * isr_freq)
#define twenty_ms_cnt (Uint32)(0.02f * isr_freq)
#define Tbprd 150
#define Ts 30e-06
#define one_by_three    (0.333333333f)
#define two_by_three    (0.666666667f)
#define sqrt3           (1.732050807f)
#define sqrt3by2        (0.866025403f)
#define N_SAMPLES 200
#define TS        (1.0f / FS)                       // 5 microseconds
#define ENERGY_AVG_LEN  8                           // number of energy blocks to average


#define bin1 10000.0f
#define bin2 20000.0f
#define range (int)((bin2 * FFT_SIZE / FFT_SAM_FREQ) - (bin1 * FFT_SIZE / FFT_SAM_FREQ))



// Switch Status
//Gpio9 sw1 , Gpio7 sw2, Gpio22 sw3, Gpio41 sw4
#define Trip_Switch_Status GpioDataRegs.GPADAT.bit.GPIO19
#define Reset_Switch_Status GpioDataRegs.GPADAT.bit.GPIO18


// LED 1 : GPIO39
#define Trip_LED_ON        (GpioDataRegs.GPBSET.bit.GPIO39   = 1)
#define Trip_LED_OFF       (GpioDataRegs.GPBCLEAR.bit.GPIO39 = 1)
#define Trip_LED_STATUS    (GpioDataRegs.GPBDAT.bit.GPIO39)



typedef struct{
    float sense;
    float offset;
    float multiplier;
    float sum;
    float actual;
}ac_parameters;




extern ac_parameters ARC_VTG;
extern Uint32 ctr;
extern bool flag;
extern Uint16 Acc;
extern float waveform_ry[512];
extern float waveform_RY[200];
extern float fft_input[FFT_SIZE];
extern Uint16 fft_index;
extern bool fft_ready;
extern float Energy;
extern bool Reset;
extern float ranged_magnitude[range];
extern bool Arc;
extern Uint32 arc_ctr;
extern float Max_energy;

//static inline float PIcontroller(float *out, float *out_prev, float *error, float *error_prev, float *upper_sat, float *lower_sat, float *Kp, float *Ki ){
//
//    // Incremental PI update
//       *out = *out_prev +  *Kp * (*error - *error_prev) + (*Ki * Ts * 0.5f) * (*error + *error_prev);
//
//
//       // Apply saturation
//       if (*out >= *upper_sat)
//           *out = *upper_sat;
//       if (*out <= *lower_sat)
//           *out = *lower_sat;
//
//       *out_prev = *out;
//       // Update previous error
//       *error_prev = *error;
//
//
//       return *out;
//
//}


//static inline float compute_energy(float *signal)
//{
//    float energy = 0.0f;
//    int n = 0;
//    for (n = 0; n < N_SAMPLES; n++)
//    {
//        energy += signal[n] * signal[n];
//    }
//
//    energy *= TS;    // account for sampling period
//
//    return energy;
//}
//static inline float update_energy_moving_avg(float new_energy)
//{
//    // Remove oldest value
//    energy_sum -= energy_buffer[energy_index];
//
//    // Insert new energy
//    energy_buffer[energy_index] = new_energy;
//    energy_sum += new_energy;
//
//    // Advance index
//    energy_index++;
//    if (energy_index >= ENERGY_AVG_LEN)
//        energy_index = 0;
//
//    // Track how many values we actually have
//    if (energy_count < ENERGY_AVG_LEN)
//        energy_count++;
//
//    // Return moving average
//    return energy_sum / energy_count;
//}



//---------------------------------------------------------------------------
// Macros
//

// The following pointer to a function call calibrates the ADC reference, 
// DAC offset, and internal oscillators
//#define Device_cal (void   (*)(void))0x070282

// The following pointers to functions calibrate the ADC linearity.  Use this
// in the AdcSetMode(...) function only
#define CalAdcaINL (void   (*)(void))0x0703B4
#define CalAdcbINL (void   (*)(void))0x0703B2
#define CalAdccINL (void   (*)(void))0x0703B0
#define CalAdcdINL (void   (*)(void))0x0703AE

// The following pointer to a function call looks up the ADC offset trim for a
// given condition. Use this in the AdcSetMode(...) function only.
#define GetAdcOffsetTrimOTP (Uint16 (*)(Uint16 OTPoffset))0x0703AC


//---------------------------------------------------------------------------
#endif  // end of LAB_H definition


//--- end of file -----------------------------------------------------
