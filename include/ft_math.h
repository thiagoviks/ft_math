#ifndef FT_MATH_H
#define FT_MATH_H

#define FT_DBL_MIN 2.2250738585072014e-308
#define FT_DBL_MAX 1.7976931348623157e+308
#define FT_DBL_EPSILON 2.2204460492503131e-16
#define FT_DBL_TRUE_MIN 4.9406564584124654e-324

#define FT_M_PI 3.14159265358979323846
#define FT_TWO_PI (FT_M_PI * 2.0)
#define FT_HALF_PI (FT_M_PI / 2.0)
#define FT_TOLERANCE (1e-12)
#define FT_EPSILON (1e-15)
#define FT_NAN (0.0 / 0.0)
#define FT_INFINITY (1.0 / 0.0)
#define FT_NEG_INFINITY (-1.0 / 0.0)

#define TAN_PI_8 0.41421356237309504880  /* tan(pi/8) = sqrt(2)-1 */
#define TAN_3PI_8 2.41421356237309504880 /* tan(3pi/8) = sqrt(2)+1 */

/*
The "real" epsilon of double is ≈ 2.22e-16.

The suggested 1e-15 is a bit more relaxed,
because:

The terms of the series accumulate rounding error,
and since long double is not being used, there is no point in forcing it beyond
~15–16 useful decimal places.
*/

double ft_normalize(double x);
double ft_acos(double);
double ft_asin(double x);
double ft_atan(double x);
double ft_cos(double x);
double ft_exp(double x);
double ft_fabs(double x);
double ft_fmod(double x, double y);
double ft_log(double x);
double ft_pow(double base, double exp);
double ft_sin(double x);
double ft_sqrt(double x);
double ft_tan(double x);
double ft_ceil(double x);

#endif