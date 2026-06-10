/*
 * z_c_d.c
 *
 *  Created on: 14-Jan-2026
 *      Author: ayush
 */

#include "zc_frequency.h"
ZCD zcd;
bool zcd_compute_flag = false;


/* ================= INIT ================= */
void ZCD_Init(void)
{
    zcd.prev_state = -1;
    zcd.sample_cnt  = 0;
    zcd.count       = 0;
    zcd.freq        = 0.0f;
    zcd.avg_period  = 0.0;
    zcd.sum         = 0;
}

void ZCD_Process(float sample){

    if(sample > HYST){
        zcd.curr_state = +1;
    }
    else if(sample < -HYST){
        zcd.curr_state = -1;
    }
    else{
        zcd.curr_state = zcd.prev_state;
    }

    zcd.sample_cnt++;                                                       // Counts how many ISR calls have happened

    if((zcd.prev_state == -1) && (zcd.curr_state == +1)){                   // Detect a rising zero crossing

        if (zcd.sample_cnt >= PERIOD_MIN &&
            zcd.sample_cnt <= PERIOD_MAX)
        {
            if (zcd.count < MAX_PERIODS)
            {
                zcd.periods[zcd.count++] = zcd.sample_cnt;
                zcd.sum += zcd.sample_cnt;
            }
        }

        zcd.sample_cnt = 0;

    }
    zcd.prev_state = zcd.curr_state;

}
float ZCD_Compute(void){
    if (zcd.count == 0){

        return zcd.freq;

    }

    zcd.avg_period = (float)(zcd.sum) / (float)(zcd.count);

    zcd.freq = isr_freq / zcd.avg_period;

    zcd.count = 0;
    zcd.sum = 0;

    return zcd.freq;
}
/* ============ PROCESS SAMPLE (ISR) ============ */
//void ZCD_Process(float sample)
//{
//    float v = sample - DC_OFFSET;
//    int state;
//
//    if (v > HYST)
//        state = +1;
//    else if (v < -HYST)
//        state = -1;
//    else
//        state = zcd.prev_state;
//
//    if (zcd.prev_state == -1 && state == +1)
//    {
//        if (zcd.last_cross != INVALID_IDX)
//        {
//            uint32_t period = zcd.sample_cnt - zcd.last_cross;
//
//            if (period >= MIN_PERIOD_GUARD && period <= PERIOD_MAX)
//            {
//                if (zcd.count < MAX_PERIODS)
//                    zcd.periods[zcd.count++] = period;
//            }
//        }
//
//        zcd.last_cross = zcd.sample_cnt;
//    }
//
//    zcd.prev_state = state;
//    zcd.sample_cnt++;
//    if (zcd.sample_cnt == 0xFFFFFFFF)
//    {
//        zcd.sample_cnt = 0;
//        zcd.last_cross = INVALID_IDX;
//    }
//}
//
///* ============ COMPUTE FREQUENCY ============ */
//float ZCD_Compute(void)
//{
//    if (zcd.count == 0)
//        return zcd.freq;   // keep last valid frequency
//
//    uint64_t sum = 0;
//    uint32_t i = 0;
//
//    for (i = 0; i < zcd.count; i++)
//    {
//        sum += zcd.periods[i];
//    }
//
//    float avg_period = (float)sum / (float)zcd.count;
//
//    zcd.freq = FS / avg_period;
//
//    zcd.count = 0;         // reset measurement window
//    return zcd.freq;
//}
//
