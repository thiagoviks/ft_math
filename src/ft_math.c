#include "../include/ft_math.h"

// normalize to [-PI, PI]
double ft_normalize(double x) {
    while (x > M_PI) x -= TWO_PI;
    while (x < -M_PI) x += TWO_PI;
    return x;
}

double ft_sin(double x) {
    x = ft_normalize(x);
    double term = x;
    double result = x;
    double x2 = x * x;

    for (int n = 1; n < 10; n++) {
        term *= -x2 / ((2*n) * (2*n+1));
        result += term;
    }
    return result;
}

double ft_cos(double x) {
    x = ft_normalize(x);
    double term = 1.0;
    double result = 1.0;
    double x2 = x * x;

    for (int n = 1; n < 10; n++) {
        term *= -x2 / ((2*n-1) * (2*n));
        result += term;
    }
    return result;
}

double ft_tan(double x) {
    double c = ft_cos(x);
    if (c == 0.0) return (ft_sin(x) > 0) ? 1e308 : -1e308;
    return ft_sin(x) / c;
}

double ft_ceil(double x) {
    double i = x;
    if (x == i) return i;
    return (x > 0) ? i + 1 : i;
}

double ft_floor(double x) {
    double i = x;
    if (x == i) return i;
    return (x < 0) ? i - 1 : i;
}