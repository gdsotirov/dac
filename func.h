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

/* Title: Functions and constants
 * Description: Defintions of the main functions and constants used for calculations
 * File: func.h
 * ---
 * Written by Georgi D. Sotirov <gdsotirov@gmail.com>
 */

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

