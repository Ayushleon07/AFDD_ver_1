/*
 * fft.h
 *
 *  Created on: 21-Jan-2026
 *      Author: ayush
 */

#ifndef FFT_H_
#define FFT_H_

#include <math.h>
#include <ABC.h>

/* ================= FFT CONFIGURATION ================= */

#define FFT_SIZE   512
#define LOG2_FFT   9        // log2(FFT_SIZE)
#define FFT_SAM_FREQ 200000.0f
#define FFT_MAG_THRESHOLD  0.05f

/* ================= COMPLEX DATA TYPE ================= */

typedef struct {
    float real;
    float imag;
} complex_t;

/* ================= COMPLEX MACROS ================= */

/* Complex Addition: res = a + b */
#define C_ADD(res, a, b)                     \
    do {                                     \
        (res).real = (a).real + (b).real;    \
        (res).imag = (a).imag + (b).imag;    \
    } while (0)

/* Complex Subtraction: res = a - b */
#define C_SUB(res, a, b)                     \
    do {                                     \
        (res).real = (a).real - (b).real;    \
        (res).imag = (a).imag - (b).imag;    \
    } while (0)

/* Complex Multiplication: res = a * b */
#define C_MUL(res, a, b)                                     \
    do {                                                     \
        (res).real = (a).real * (b).real - (a).imag * (b).imag; \
        (res).imag = (a).real * (b).imag + (a).imag * (b).real; \
    } while (0)

/* Complex Division: res = a / b */
#define C_DIV(res, a, b)                                             \
    do {                                                             \
        float denom = (b).real * (b).real + (b).imag * (b).imag;    \
        (res).real = ((a).real * (b).real + (a).imag * (b).imag) / denom; \
        (res).imag = ((a).imag * (b).real - (a).real * (b).imag) / denom; \
    } while (0)

/* ================= GLOBAL ARRAYS ================= */


extern complex_t W[FFT_SIZE / 2];   /* Twiddle factors */
extern float window[FFT_SIZE];      /* Window coefficients */
extern complex_t x[FFT_SIZE];
extern float magnitude[FFT_SIZE / 2];
extern float max_magnitude[FFT_SIZE / 2];
extern float fundamental_freq;


//extern float magnitude[FFT_SIZE / 2];



/* ================= FUNCTION DECLARATIONS ================= */

void compute_twiddles(void);
void compute_window(void);
void apply_window(complex_t *x, float *input);
void bit_reversal(complex_t *x);
void fft_dit(complex_t *x);
float find_fundamental(float *mag);
void compute_magnitude(complex_t *x, float *mag);
void compute_range_magnitude(complex_t *x, float *ranged_magnitude, float f_low, float f_high);
float compute_band_energy(complex_t *x, float f_low, float f_high);



#endif /* FFT_H_ */
