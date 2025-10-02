#include "../include/ft_math.h"

// normalize to [-PI, PI]
double ft_normalize(double x) {
    //too slow
    // while (x > M_PI) x -= TWO_PI;
    // while (x < -M_PI) x += TWO_PI;

    long long quo = (long long) (x / FT_TWO_PI);
    x -= quo * FT_TWO_PI;
    if (x > FT_M_PI) x -= FT_TWO_PI;
    if (x < -FT_M_PI) x += FT_TWO_PI;
    return(x);
}

double ft_acos(double x) {
	if (x != x)
		return (FT_NAN);
    if (x > 1.0 || x < -1.0) {
        return (FT_NAN); // NaN
    }
	if (x == 1.0)  return (0.0);
    if (x == -1.0) return (FT_M_PI);
    return (FT_HALF_PI - ft_asin(x));
}

double ft_asin(double x) {
	if (x != x)
		return (FT_NAN);
    if (x > 1.0 || x < -1.0) {
        return (FT_NAN); // NaN
    }
    if (x == 1.0) return (FT_HALF_PI);
    if (x == -1.0) return (-FT_HALF_PI);
    return (ft_atan(x / ft_sqrt(1.0 - x*x)));
}

static const double aT[] = {
  0.33333333333329318027,
 -0.199999999998764832476,
  0.142857142725034663711,
 -0.111111104054623557880,
  0.0909088713343650656196,
 -0.0769187620504482999495,
  0.0666107313738753120669,
 -0.0583357013379057348645,
  0.0497687799461593236017,
 -0.0365315727442169155270,
  0.0162858201153657823623
};

/* polinômio de Taylor modificado */
static double atan_poly(double x) {
    double z = x*x;
    double w = z*z;
    double s1 = z*(aT[0] + w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
    double s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
    return x - x*(s1+s2);
}

double ft_atan(double x) {
    if (x != x) return FT_NAN;

    int sign = (x < 0) ? -1 : 1;
    double ax = ft_fabs(x);
    double z;
    double result;
    int id = -1;

    /* redução de argumento */
    if (ax < 0.4375) {        /* |x| < 7/16 */
        z = ax;
        id = -1;
    } else if (ax < 1.1875) { /* 7/16 <= |x| < 19/16 */
        if (ax < 0.6875) {    /* 7/16 <= x < 11/16 */
            z = (2.0*ax - 1.0)/(2.0 + ax);
            id = 0;
        } else {               /* 11/16 <= x < 19/16 */
            z = (ax - 1.0)/(ax + 1.0);
            id = 1;
        }
    } else if (ax < 2.4375) { /* 19/16 <= x < 39/16 */
        z = (ax - 1.5)/(1.0 + 1.5*ax);
        id = 2;
    } else {                   /* x >= 2.4375 */
        z = -1.0/ax;
        id = 3;
    }

    /* polinômio */
    result = atan_poly(z);

    /* adicionar a constante do intervalo */
    static const double atanhi[] = {
        0.4636476090008061,  /* atan(0.5) */
        0.7853981633974483,  /* atan(1.0) */
        0.982793723247329,   /* atan(1.5) */
        1.5707963267948966   /* atan(inf) */
    };

    static const double atanlo[] = {
        2.2698777452961687e-17,
        3.061616997868383e-17,
        1.3903311031230998e-17,
        6.123233995736766e-17
    };

    if (id >= 0) {
        result = atanhi[id] - ((z*(aT[0]+aT[1]*z*z) + z*(aT[2]+aT[3]*z*z)) - atanlo[id]); /* simplificação */
    }

    return (sign < 0) ? -result : result;
}

double ft_cos(double x) {
    x = ft_normalize(x);
    double term = 1.0;
    double result = 1.0;
    double x2 = x * x;

    for (int n = 1; n < 100; n++) {
        term *= -x2 / ((2*n-1) * (2*n));
		if (term == 0.0) break;
        result += term;
		if (ft_fabs(term) < FT_EPSILON) break;
    }
    return (result);
}

double ft_exp(double x) {
    double term = 1.0;   // primeiro termo
    double result = 1.0; 
    for (int n = 1; n < 100; n++) {
        term *= x / n;   // próximo termo
        result += term;
    }
    return result;
}

double ft_fabs(double x) {
    return (x < 0.0) ? -x : x;
}

double ft_floor(double x) {
    long long i = (long long)x;
    if (x < 0 && x != (double)i) return (double)(i - 1);
    return (double)i;
}

double ft_fmod(double x, double y) {
    if (y == 0.0) {
        return 0.0;  /* Undefined, but avoids division by zero */
    }

    /* Work with absolute values for division */
    double ax = (x < 0) ? -x : x;
    double ay = (y < 0) ? -y : y;

    /* Compute integer quotient q = trunc(ax / ay) */
    long long q = (long long)(ax / ay);

    /* remainder = ax - q*ay */
    double r = ax - (double)q * ay;

    /* Make sure remainder is within [0, ay). 
       If due to floating point error r >= ay, reduce it */
    while (r >= ay) {
        r -= ay;
    }

    /* Restore the sign of x */
    if (x < 0) r = -r;

    return r;
}

double ft_log(double x) {
    if (x <= 0) return -FT_DBL_MAX; // não definido para <= 0

    double y = 0.0;  // chute inicial
    for (int i = 0; i < 100; i++) {
        double ey = ft_exp(y);
        y -= (ey - x) / ey;
    }
    return y;
}

double ft_pow(double base, double exp) {
    if (base <= 0) return -FT_DBL_MAX; // simplificação: não suportamos negativos
    
    // verifica se exp é "inteiro"
    int iexp = (int)exp;
    if (exp == (double)iexp) {
        // exponenciação rápida para inteiros
        if (iexp == 0) return 1.0;
        if (iexp < 0) return 1.0 / ft_pow(base, -iexp);
        double result = 1.0, b = base;
        int e = iexp;
        while (e > 0) {
            if (e & 1) result *= b;
            b *= b;
            e >>= 1;
        }
        return result;
    }

    // caso geral: exp real
    return ft_exp(exp * ft_log(base));
}


double ft_sin(double x) {
    x = ft_normalize(x);
    double term = x;
    double result = x;
    double x2 = x * x;

    for (int n = 1; n < 100; n++) {
        term *= -x2 / ((2*n) * (2*n+1));
		if (term == 0.0) break;
        result += term;
		if (ft_fabs(term) < FT_EPSILON) break;
    }
    return (result);
}

/*
Porque se o loop termina por i == 100 (nunca atingiu a precisão EPSILON),
 a variável new_guess pode estar fora do escopo do loop, enquanto guess sempre 
 guarda o último valor válido.
*/

double ft_sqrt(double x) {
    if (x < 0.0) return FT_NAN;
    if (x == 0.0) return 0.0;

    double guess = (x >= 1.0) ? x : 1.0;
    for (int i = 0; i < 1000; i++) {
        double new_guess = 0.5 * (guess + x / guess);

        double diff = ft_fabs(new_guess - guess);
        /* critério absoluto e relativo */
        if (diff < FT_EPSILON) return new_guess;
        if (diff / (ft_fabs(new_guess) + 1e-300) < FT_EPSILON) return new_guess;

        guess = new_guess;
    }
    return guess;
}


double ft_tan(double x) {
    double c = ft_cos(x);
    if (ft_fabs(c) < FT_DBL_MIN) 
		return (ft_sin(x) > 0) ? FT_DBL_MAX : -FT_DBL_MAX;
    return (ft_sin(x) / c);
}

double ft_ceil(double x) {
    long long i = (long long)x;
    if (x > 0 && x != (double)i) return (double)(i + 1);
    return (double)i;
}


