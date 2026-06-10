/*
 * Lcd_test.c
 *
 *  Created on: 25-Nov-2025
 *      Author: ayush
 */
#include <ABC.h>
void Lcd_test(void){

//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Input Voltage");
//
//    Lcd_printval(2, 1, display_data.Vdc_1_avg, 'V');
//
//    Delay_ms(500);
//
//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Input Current");
//
//    Lcd_printval(2, 1, display_data.Iin_avg, 'A');
//
//    Delay_ms(500);
//
//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Vdc2");
//
//    Lcd_printval(2, 1, display_data.Vdc_2_avg, 'V');
//
//    Delay_ms(500);
//
//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Output Voltage");
//
//    Lcd_printval(2, 1, display_data.Vout_avg, 'V');
//
//    Delay_ms(500);
//
//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Output Current");
//
//    Lcd_printval(2, 1, display_data.Iout_avg, 'A');
//
//    Delay_ms(500);
//
//    Lcd_Cmd(0x01);
//
//    Lcd_out(1, 1, "Battery Voltage");
//
//    Lcd_printval(2, 1, display_data.Vbatt_avg, 'V');
//
//    Delay_ms(500);

    Lcd_Cmd(0x01);

    Lcd_out(1, 1, "freq");

    Lcd_printval(2, 1, fundamental_freq, "hz");

    Lcd_out(1, 9, "Power");

    Lcd_printval(2, 9, Power, "W");

    Delay_ms(500);

    Lcd_Cmd(0x01);

    Lcd_out(1, 1, "Vr");

    Lcd_printval(2, 1, rms.Vr.Rms_Val, "V");

    Lcd_out(1, 9, "Ir");

    Lcd_printval(2, 9, rms.Ir.Rms_Val, "A");

    Delay_ms(500);

    Lcd_Cmd(0x01);

    Lcd_out(1, 1, "Vb");

    Lcd_printval(2, 1, rms.Vb.Rms_Val, "V");

    Lcd_out(1, 9, "Ib");

    Lcd_printval(2, 9, rms.Ib.Rms_Val, "A");

    Delay_ms(500);

    Lcd_Cmd(0x01);

    Lcd_out(1, 1, "Vy");

    Lcd_printval(2, 1, rms.Vy.Rms_Val, "V");

    Lcd_out(1, 9, "Iy");

    Lcd_printval(2, 9, rms.Iy.Rms_Val, "A");

    Delay_ms(500);

}

void Lcd_fault(void){

    Lcd_Cmd(0x01);

    if(fault_type.input_over_vtg_fault){

      Lcd_out(1, 1, "Input Over Vtg");

      Delay_ms(500);
    }

    if(fault_type.input_under_vtg_fault){

        Lcd_out(1, 1, "Input Under Vtg");

        Delay_ms(500);
    }

    if(fault_type.Vdc_2_over_vtg_fault){

        Lcd_out(1, 1, "Vdc_2 Over Vtg");

        Delay_ms(500);
    }

    if(fault_type.output_over_vtg_fault){

        Lcd_out(1, 1, "Output Over Vtg");

        Delay_ms(500);
    }

    if(fault_type.output_over_curr_fault){

        Lcd_out(1, 1, "Output Over Curr");

        Delay_ms(500);
    }
    if(fault_type.input_over_curr_fault){

        Lcd_out(1, 1, "Input Over Curr");

        Delay_ms(500);
    }
    if(fault_type.Hardware_trip_Boost_oc){

        Lcd_out(1, 1, "HardwareTrip");
        Lcd_out(2, 1, "Boost OC");

        Delay_ms(500);
    }
    if(fault_type.Hardware_trip_Boost_uc){

        Lcd_out(1, 1, "HardwareTrip");
        Lcd_out(2, 1, "Boost UC");

        Delay_ms(500);
    }
    if(fault_type.Hardware_trip_Buck_oc){

        Lcd_out(1, 1, "HardwareTrip");
        Lcd_out(2, 1, "Buck OC");

        Delay_ms(500);
    }
    if(fault_type.Hardware_trip_Buck_uc){

        Lcd_out(1, 1, "HardwareTrip");
        Lcd_out(2, 1, "Buck UC");

        Delay_ms(500);
    }

}

//void Lcd_input_vals(void){
//
//    Lcd_Cmd(0x01);
//    Lcd_out(1, 1, "Iref");
//    Iref_set.buf[0] = Iref_set.digit[0] + '0';
//    Iref_set.buf[1] = Iref_set.digit[1] + '0';
//    Iref_set.buf[2] = '.';
//    Iref_set.buf[3] = Iref_set.digit[2] + '0';
//    Iref_set.buf[4] = Iref_set.digit[3] + '0';
//    Iref_set.buf[5] = '\0';
//    Lcd_Cmd(LCD_ROW2);
//    Lcd_out(2, 1, Iref_set.buf);
//
//
//
//
//
//
//
//
//}

