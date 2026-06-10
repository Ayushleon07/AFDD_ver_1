/*
 * fft.c
 *
 *  Created on: 21-Jan-2026
 *      Author: ayush
 */
#include <ABC.h>
#include "fft.h"

/* ================= GLOBAL TABLES ================= */

complex_t W[FFT_SIZE / 2];
float window[FFT_SIZE];
//complex_t x[FFT_SIZE];
//float fft_input[FFT_SIZE];
//float magnitude[FFT_SIZE / 2];


/* ================= TWIDDLE FACTORS ================= */

void compute_twiddles(void)
{
    int k;
    for (k = 0; k < FFT_SIZE / 2; k++) {
        W[k].real = cosf(2.0f * M_PI * k / FFT_SIZE);
        W[k].imag = -sinf(2.0f * M_PI * k / FFT_SIZE);
    }
}

/* ================= HANN WINDOW ================= */

void compute_window(void)
{
    int n;
    for (n = 0; n < FFT_SIZE; n++) {
        window[n] = 0.5f * (1.0f -
            cosf((2.0f * M_PI * n) / (FFT_SIZE - 1)));
    }
}

/* ================= APPLY WINDOW ================= */
/* input[] = raw samples (voltage)
   x[]     = complex FFT input */

void apply_window(complex_t *x, float *input)
{
    int i;
    for (i = 0; i < FFT_SIZE; i++) {
        x[i].real = input[i] * window[i];
        x[i].imag = 0.0f;
    }
}

/* ================= BIT REVERSAL ================= */

static unsigned int bit_reverse(unsigned int x, int log2n)
{
    unsigned int n = 0;
    int i;
    for (i = 0; i < log2n; i++) {
        n = (n << 1) | (x & 1);
        x >>= 1;
    }
    return n;
}

void bit_reversal(complex_t *x)
{
    unsigned int i, j;
    complex_t temp;

    for (i = 0; i < FFT_SIZE; i++) {
        j = bit_reverse(i, LOG2_FFT);
        if (j > i) {
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
}

/* ================= RADIX-2 DIT FFT ================= */

void fft_dit(complex_t *x)
{
    int stage, step, half_step;
    int k, j;
    complex_t u, t;

    for (stage = 1; stage <= LOG2_FFT; stage++) {

        step = 1 << stage;
        half_step = step >> 1;

        for (k = 0; k < FFT_SIZE; k += step) {

            for (j = 0; j < half_step; j++) {

                int twiddle_index = j * (FFT_SIZE / step);

                /* Upper value */
                u = x[k + j];

                /* t = W * lower value */
                C_MUL(t, W[twiddle_index], x[k + j + half_step]);

                /* Butterfly outputs */
                C_ADD(x[k + j], u, t);
                C_SUB(x[k + j + half_step], u, t);
            }
        }
    }
}
void compute_magnitude(complex_t *x, float *mag)
{
    int i;
    for (i = 0; i < FFT_SIZE / 2; i++) {
        mag[i] = sqrtf(
            x[i].real * x[i].real +
            x[i].imag * x[i].imag
        );
        if(Reset){
            max_magnitude[i] = 0.0f;
        }
        else{
            if(mag[i] > max_magnitude[i]){
                max_magnitude[i] = mag[i];
            }
        }
    }
}
float find_fundamental(float *mag)
{
    int i;
    int max_index = 1;        /* Ignore DC bin */
    float max_value = mag[1];

    for (i = 2; i < FFT_SIZE / 2; i++) {
        if (mag[i] > max_value) {
            max_value = mag[i];
            max_index = i;
        }
    }


    return (max_index * FFT_SAM_FREQ) / FFT_SIZE;
}

float compute_band_energy(complex_t *x,
                          float f_low,
                          float f_high)
{
    int i;

    int start_bin = (int)(f_low  * FFT_SIZE / FFT_SAM_FREQ);
    int end_bin   = (int)(f_high * FFT_SIZE / FFT_SAM_FREQ);

    if(start_bin < 1) start_bin = 1;
    if(end_bin >= FFT_SIZE / 2) end_bin = FFT_SIZE/2 - 1;

    float energy = 0.0f;

    for(i = start_bin; i <= end_bin; i++)
    {
        energy +=
            x[i].real * x[i].real +
            x[i].imag * x[i].imag;

    }
    if(energy > Max_energy){
        Max_energy = energy;
    }

    return energy;
}
void compute_range_magnitude(complex_t *x, float *ranged_magnitude, float f_low, float f_high)
{
    int i, idx = 0;

    int start_bin = (int)(f_low  * FFT_SIZE / FFT_SAM_FREQ);
    int end_bin   = (int)(f_high * FFT_SIZE / FFT_SAM_FREQ);

    if(start_bin < 0) start_bin = 0;
    if(end_bin >= FFT_SIZE / 2) end_bin = FFT_SIZE/2 - 1;

    for(i = start_bin; i <= end_bin; i++)
    {
        ranged_magnitude[idx++] = sqrtf(
            x[i].real * x[i].real +
            x[i].imag * x[i].imag
        );
    }

}



