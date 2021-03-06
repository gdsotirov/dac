/* DND - a D.N.D. grapher utility
 * Copyright (C) 2005 Georgi D. Sotirov, Boayn D. Sotirov
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/* Title: Functions
 * Description: Implementations of the main functions used for calculations
 * File: func.c
 * ---
 * Written by Georgi D. Sotirov <gdsotirov@gmail.com>
 */

#include <math.h>

#include "func.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function    : deg2rad
 * Description : Calculate angle in radians from given degrees
 */
double deg2rad(double x) {
  return (x * 2 * M_PI / 360);
}

/* Function    : rad2deg
 * Description : Calculate angle in degress from given radians
 */
double rad2deg(double x) {
  return (180 * x / M_PI);
}

/* Function    : bessel_j1
 * Description : Calculates the Bessel function J1(x) for any real x
 */
double bessel_j1(double x) {
  double ax;
  double z;
  double xx;
  double y;
  double ans;
  double ans1;
  double ans2;

  if ( (ax = fabs(x)) < 8.0 ) { /* Direct rational approximation. */
    y = x * x;
    ans1 = x * (72362614232.0 + y * (-7895059235.0 + y * (242396853.1 + y * (-2972611.439 + y * (15704.48260 + y * (-30.16036606))))));
    ans2 = 144725228442.0 + y * (2300535178.0 + y * (18583304.74 + y * (99447.43394 + y * (376.9991397 + y * 1.0))));
    ans = ans1 / ans2;
  }
  else {
    z = 8.0 / ax;
    y = z * z;
    xx = ax - 2.356194491;
    ans1 = 1.0 + y * (0.183105e-2 + y * (-0.3516396496e-4 + y * (0.2457520174e-5 + y * (-0.240337019e-6))));
    ans2 = 0.04687499995 + y * (-0.2002690873e-3 + y * (0.8449199096e-5 + y * (-0.88228987e-6 + y * 0.105787412e-6)));
    ans = sqrt(0.636619772 / ax) * (cos(xx) * ans1 - z * sin(xx) * ans2);
    if ( x < 0.0 )
      ans = -ans;
  }

  return ans;
}

double f_psi(double psi, double f) {
  return atan(psi/f);
}

double f_x(double x, double D, unsigned int p) {
  return (pow(1 - pow(2*x/D, 2.0), p));
}

double f_tita_1(double u) {
  if ( u != 0 )
    return (2 * bessel_j1(u)/u);
  else
    return 0;
}

double f_tita_2(double tita, double u) {
  return (((1 + cos(tita))/2) * (sin(u)/u));
}

#ifdef __cplusplus
}
#endif

