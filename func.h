#ifndef __DND_FUNC_H__
#define __DND_FUNC_H__

#include <math.h>

/* pi - the ratio of a circle's circumference to its diameter */
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif

/* c - the speed of light in vacuum */
#ifndef M_C
#define M_C 299792458
#endif

#ifdef __cplusplus
extern "C" {
#endif

double deg2rad(double x);
double rad2deg(double x);
double bessel_j1(double x);
double calc_u(double tita);
double f_psi(double psi, double f);
double f_x(double x, double D, unsigned int p);
double f_tita_1(double u);
double f_tita_2(double tita, double u);

#ifdef __cplusplus
}
#endif

#endif

