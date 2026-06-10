#ifndef ZCFREQUENCY_H
#define ZCFREQUENCY_H

#include <stdint.h>
#include <ABC.h>

/* ===== USER CONFIG ===== */

//#define DC_OFFSET     1.658f          // ADC offset (V)
#define HYST          0.1f          // Hysteresis (V)

#define FREQ_MIN      1.0f
#define FREQ_MAX      100.0f

#define PERIOD_MIN    ((uint32_t)(isr_freq / FREQ_MAX))
#define PERIOD_MAX    ((uint32_t)(isr_freq / FREQ_MIN))

#define MAX_PERIODS  100


#define INVALID_IDX  0xFFFFFFFFu

/* ===== STRUCT ===== */

typedef struct
{
    int prev_state;          // -1 or +1
    int curr_state;
    Uint32 sample_cnt;
    Uint32 periods[MAX_PERIODS];
    Uint32 count;
    Uint64 sum;
    float avg_period;
    float freq;
} ZCD;

/* ===== API ===== */

extern void  ZCD_Init(void);
extern void  ZCD_Process(float sample);
extern float ZCD_Compute(void);
extern bool zcd_compute_flag;


#endif
