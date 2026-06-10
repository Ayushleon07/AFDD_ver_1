#include <ABC.h>                        // Main include file
#include <stdio.h>

void SCIAWrite(char *string)
{
    while(*string)
    {
        while (SciaRegs.SCICTL2.bit.TXEMPTY == 0);
        SciaRegs.SCITXBUF.bit.TXDT = *string++ ;
        //DelayUs(2);
    }
}

void SCIA_init()
{
SciaRegs.SCICTL1.bit.SWRESET = 0;

    SciaRegs.SCICCR.bit.SCICHAR = 7;
    SciaRegs.SCICCR.bit.STOPBITS = 0;
    SciaRegs.SCICCR.bit.PARITYENA = 0;

    SciaRegs.SCICTL1.bit.TXENA = 1;
    SciaRegs.SCICTL1.bit.RXENA = 1;
    // SYSCLOCKOUT = 120MHz; LSPCLK = 1/4 = 30.0 MHz
    // BRR = (LSPCLK / (9600 x 8)) -1
    // BRR = 390  gives 9590 Baud
    SciaRegs.SCIHBAUD.bit.BAUD   = 390 >> 8;        // Highbyte
    SciaRegs.SCILBAUD.bit.BAUD   = 390 & 0x00FF;    // Lowbyte

    SciaRegs.SCICTL1.bit.SWRESET = 1;

}
void Uart_printval(char *dataDisplay, float value)
{
    char buffer[50];
    int intPart, decPart;

    // Split the float into integer and decimal parts
    intPart = (int)value;
    decPart = (int)((value - intPart) * 100);   // two decimal digits
    if (decPart < 0) decPart = -decPart;        // handle negative decimals

    // Format the final string (e.g. "Speed: 123.45\r\n")
    sprintf(buffer, "%s %d.%02d\r\n", dataDisplay, intPart, decPart);

    // Send the formatted string through SCI-A
    SCIAWrite(buffer);
}


/* ============================================================
 * FLOAT to STRING (1 DECIMAL, NO LEADING ZEROS, SAFE ROUNDING)
 * ============================================================ */
void float_to_str_1dp(float value, char *buf)
{
    int intPart;
    int decPart;
    char *p = buf;

    /* Handle negative values */
    if (value < 0.0f)
    {
        *p++ = '-';
        value = -value;
    }

    intPart = (int)value;
    decPart = (int)((value - intPart) * 10.0f + 0.5f);

    /* ---- FIX: decimal rollover  ---- */
    if (decPart >= 10)
    {
        intPart++;
        decPart = 0;
    }

    /* Integer part */
    if (intPart == 0)
    {
        *p++ = '0';
    }
    else
    {
        char temp[6];
        int i = 0;

        while (intPart > 0)
        {
            temp[i++] = (intPart % 10) + '0';
            intPart /= 10;
        }

        while (i > 0)
        {
            *p++ = temp[--i];
        }
    }

    /* Decimal part */
    *p++ = '.';
    *p++ = decPart + '0';

    *p = '\0';
}


/* ============================================================
 * APPEND ONE PARAMETER TO FRAME
 * ============================================================ */
void append_param(char *frame, float value)
{
    char num[10];
    char *p = frame;

    /* Move to end of string */
    while (*p) p++;

    /* Add comma */
    *p++ = ',';

    /* Convert number */
    float_to_str_1dp(value, num);

    /* Copy into frame */
    char *n = num;
    while (*n)
    {
        *p++ = *n++;
    }

    *p = '\0';
}



/* ============================================================
 * BUILD & SEND COMPLETE TELEMETRY FRAME
 * ============================================================ */
void UART_SendAllParams(void)
{
    char frame[200];
    char num[10];
    char *p = frame;

    /* Start character */

    *p++ = 'P';
    *p++ = 'a';
    *p++ = 'r';
    *p++ = 'a';
    *p++ = 'm';
    *p++ = ':';

    *p = '\0';

    /* First parameter (no comma before) */
    float_to_str_1dp(display_data.Vdc_1_avg, num);
    char *n = num;
    while (*n) *p++ = *n++;
    *p = '\0';

    /* Remaining parameters */
    append_param(frame, display_data.Vdc_2_avg);
    append_param(frame, display_data.Vout_avg);
    append_param(frame, display_data.Iin_avg);
    append_param(frame, display_data.Iout_avg);
    append_param(frame, CHARGER_TEMP_SENSE.actual);
    append_param(frame, ALTR_TEMP_SENSE.actual);
    append_param(frame, HEAT_SINK_TEMP_SENSE.actual);
    append_param(frame, display_data.output_pwr);
    append_param(frame, display_data.Vbatt_avg);
//    append_param(frame, fault_type.input_over_vtg_fault);
//    append_param(frame, fault_type.input_under_vtg_fault);
//    append_param(frame, fault_type.input_over_curr_fault);
//    append_param(frame, fault_type.Vdc_2_over_vtg_fault);
//    append_param(frame, fault_type.output_over_vtg_fault);
//    append_param(frame, fault_type.output_over_curr_fault);
//    append_param(frame, fault_type.Hardware_trip_Boost_oc);
//    append_param(frame, fault_type.Hardware_trip_Boost_uc);
//    append_param(frame, fault_type.Hardware_trip_Buck_oc);
//    append_param(frame, fault_type.Hardware_trip_Buck_uc);

    while (*p) p++;

    *p++ = ',';
    *p++ = (fault_type.input_over_vtg_fault + '0');
    *p++ = (fault_type.input_under_vtg_fault + '0');
    *p++ = (fault_type.input_over_curr_fault + '0');
    *p++ = (fault_type.Vdc_2_over_vtg_fault + '0');
    *p++ = (fault_type.output_over_vtg_fault + '0');
    *p++ = (fault_type.output_over_curr_fault + '0');
    *p++ = (fault_type.Hardware_trip_Boost_oc + '0');
    *p++ = (fault_type.Hardware_trip_Boost_uc + '0');
    *p++ = (fault_type.Hardware_trip_Buck_oc + '0');
    *p++ = (fault_type.Hardware_trip_Buck_uc + '0');
    *p++ = '\r';
    *p++ = '\n';
    *p   = '\0';

    /* Line termination */
//    p = frame;
//    while (*p) p++;
//    *p++ = '\r';
//    *p++ = '\n';
//    *p   = '\0';

    /* Transmit */
    SCIAWrite(frame);
}

