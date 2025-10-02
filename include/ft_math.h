#ifndef  FT_MATH_H
#define FT_MATH_H

#define	FT_DBL_MIN		2.2250738585072014e-308
#define FT_DBL_MAX		1.7976931348623157e+308
#define FT_DBL_EPSILON	2.2204460492503131e-16
#define FT_DBL_TRUE_MIN 4.9406564584124654e-324

#define FT_M_PI			3.14159265358979323846
#define FT_TWO_PI		(FT_M_PI * 2.0)
#define FT_HALF_PI		(FT_M_PI / 2.0)
#define FT_EPSILON    	(1e-15)
#define FT_NAN			(0.0/0.0)

#define TAN_PI_8  0.41421356237309504880  /* tan(pi/8) = sqrt(2)-1 */
#define TAN_3PI_8 2.41421356237309504880  /* tan(3pi/8) = sqrt(2)+1 */

/*
O epsilon “real” do double é ≈ 2.22e-16.

O 1e-15 sugerido é um pouco mais relaxado,
 porque:

os termos da série (term) vão acumulando erro de arredondamento,
e como não está sendo usado long double, não adianta forçar além 
de ~15–16 casas decimais úteis.
*/

double		ft_normalize(double x);

double      ft_acos(double);
float       ft_acosf(float);
long double ft_acosl(long double);

double      ft_acosh(double);
float       ft_acoshf(float);
long double ft_acoshl(long double);

double      ft_asin(double);
float       ft_asinf(float);
long double ft_asinl(long double);

double      ft_asinh(double);
float       ft_asinhf(float);
long double ft_asinhl(long double);

double      ft_atan(double);
float       ft_atanf(float);
long double ft_atanl(long double);

double      ft_atan2(double, double);
float       ft_atan2f(float, float);
long double ft_atan2l(long double, long double);

double      ft_atanh(double);
float       ft_atanhf(float);
long double ft_atanhl(long double);

double      ft_cbrt(double);
float       ft_cbrtf(float);
long double ft_cbrtl(long double);

double      ft_ceil(double);
float       ft_ceilf(float);
long double ft_ceill(long double);

double      ft_copysign(double, double);
float       ft_copysignf(float, float);
long double ft_copysignl(long double, long double);

double      ft_cos(double);
float       ft_cosf(float);
long double ft_cosl(long double);

double      ft_cosh(double);
float       ft_coshf(float);
long double ft_coshl(long double);

double      ft_erf(double);
float       ft_erff(float);
long double ft_erfl(long double);

double      ft_erfc(double);
float       ft_erfcf(float);
long double ft_erfcl(long double);

double      ft_exp(double);
float       ft_expf(float);
long double ft_expl(long double);

double      ft_exp2(double);
float       ft_exp2f(float);
long double ft_exp2l(long double);

double      ft_expm1(double);
float       ft_expm1f(float);
long double ft_expm1l(long double);

double      ft_fabs(double);
float       ft_fabsf(float);
long double ft_fabsl(long double);

double      ft_fdim(double, double);
float       ft_fdimf(float, float);
long double ft_fdiml(long double, long double);

double      ft_floor(double);
float       ft_floorf(float);
long double ft_floorl(long double);

double      ft_fma(double, double, double);
float       ft_fmaf(float, float, float);
long double ft_fmal(long double, long double, long double);

double      ft_fmax(double, double);
float       ft_fmaxf(float, float);
long double ft_fmaxl(long double, long double);

double      ft_fmin(double, double);
float       ft_fminf(float, float);
long double ft_fminl(long double, long double);

double      ft_fmod(double, double);
float       ft_fmodf(float, float);
long double ft_fmodl(long double, long double);

double      ft_frexp(double, int *);
float       ft_frexpf(float, int *);
long double ft_frexpl(long double, int *);

double      ft_hypot(double, double);
float       ft_hypotf(float, float);
long double ft_hypotl(long double, long double);

int         ft_ilogb(double);
int         ft_ilogbf(float);
int         ft_ilogbl(long double);

double      ft_ldexp(double, int);
float       ft_ldexpf(float, int);
long double ft_ldexpl(long double, int);

double      ft_lgamma(double);
float       ft_lgammaf(float);
long double ft_lgammal(long double);

long long   ft_llrint(double);
long long   ft_llrintf(float);
long long   ft_llrintl(long double);

long long   ft_llround(double);
long long   ft_llroundf(float);
long long   ft_llroundl(long double);

double      ft_log(double);
float       ft_logf(float);
long double ft_logl(long double);

double      ft_log10(double);
float       ft_log10f(float);
long double ft_log10l(long double);

double      ft_log1p(double);
float       ft_log1pf(float);
long double ft_log1pl(long double);

double      ft_log2(double);
float       ft_log2f(float);
long double ft_log2l(long double);

double      ft_logb(double);
float       ft_logbf(float);
long double ft_logbl(long double);

long        ft_lrint(double);
long        ft_lrintf(float);
long        ft_lrintl(long double);

long        ft_lround(double);
long        ft_lroundf(float);
long        ft_lroundl(long double);

double      ft_modf(double, double *);
float       ft_modff(float, float *);
long double ft_modfl(long double, long double *);

double      ft_nan(const char *);
float       ft_nanf(const char *);
long double ft_nanl(const char *);

double      ft_nearbyint(double);
float       ft_nearbyintf(float);
long double ft_nearbyintl(long double);

double      ft_nextafter(double, double);
float       ft_nextafterf(float, float);
long double ft_nextafterl(long double, long double);

double      ft_nexttoward(double, long double);
float       ft_nexttowardf(float, long double);
long double ft_nexttowardl(long double, long double);

double      ft_pow(double, double);
float       ft_powf(float, float);
long double ft_powl(long double, long double);

double      ft_remainder(double, double);
float       ft_remainderf(float, float);
long double ft_remainderl(long double, long double);

double      ft_remquo(double, double, int *);
float       ft_remquof(float, float, int *);
long double ft_remquol(long double, long double, int *);

double      ft_rint(double);
float       ft_rintf(float);
long double ft_rintl(long double);

double      ft_round(double);
float       ft_roundf(float);
long double ft_roundl(long double);

double      ft_scalbln(double, long);
float       ft_scalblnf(float, long);
long double ft_scalblnl(long double, long);

double      ft_scalbn(double, int);
float       ft_scalbnf(float, int);
long double ft_scalbnl(long double, int);

double      ft_sin(double);
float       ft_sinf(float);
long double ft_sinl(long double);

double      ft_sinh(double);
float       ft_sinhf(float);
long double ft_sinhl(long double);

double      ft_sqrt(double);
float       ft_sqrtf(float);
long double ft_sqrtl(long double);

double      ft_tan(double);
float       ft_tanf(float);
long double ft_tanl(long double);

double      ft_tanh(double);
float       ft_tanhf(float);
long double ft_tanhl(long double);

double      ft_tgamma(double);
float       ft_tgammaf(float);
long double ft_tgammal(long double);

double      ft_trunc(double);
float       ft_truncf(float);
long double ft_truncl(long double);

#endif