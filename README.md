# ft_math

A custom implementation of standard mathematical functions in C, built from scratch without relying on the standard math library. Part of the ft_maki project ecosystem.

**Note**: This is an educational implementation. For production use, prefer the 
standard `<math.h>` library which uses hardware-optimized implementations.

## Overview

ft_math provides implementations of fundamental mathematical operations including trigonometric functions, exponentials, logarithms, and power functions. All functions are implemented using numerical methods and series expansions.


### Installation
```bash
git clone https://github.com/thiagoviks/ft_math.git
cd ft_math
sudo make install
```

## Features

### Trigonometric Functions
- `sin`, `cos`, `tan` - Basic trigonometry
- `asin`, `acos`, `atan` - Inverse trigonometric functions
- Angle normalization and range reduction

### Exponential & Logarithmic
- `exp` - Natural exponential (e^x)
- `log` - Natural logarithm
- `pow` - Power function (x^y)
- `sqrt` - Square root

### Utility Functions
- `fabs` - Absolute value
- `fmod` - Floating-point modulo
- `ceil` - Ceiling function
- `normalize` - Angle normalization

### Mathematical Constants
High-precision constants for accurate calculations:
- π (pi) and related values
- Double precision limits
- Machine epsilon values
- Special values (NaN, Infinity)

## Constants Reference

### Pi Constants
```c
FT_M_PI       // π ≈ 3.14159265358979323846
FT_TWO_PI     // 2π
FT_HALF_PI    // π/2
```

### Tangent Constants
```c
TAN_PI_8      // tan(π/8) = √2 - 1 ≈ 0.414213562
TAN_3PI_8     // tan(3π/8) = √2 + 1 ≈ 2.414213562
```

### Precision & Limits
```c
FT_DBL_MIN        // 2.225e-308  - Smallest normalized positive double
FT_DBL_MAX        // 1.798e+308  - Largest representable double
FT_DBL_EPSILON    // 2.220e-16   - Machine epsilon
FT_DBL_TRUE_MIN   // 4.941e-324  - Smallest subnormal positive double
FT_TOLERANCE      // 1e-12       - General comparison tolerance
FT_EPSILON        // 1e-15       - Relaxed epsilon for series convergence
```

### Special Values
```c
FT_NAN            // Not a Number (0.0 / 0.0)
FT_INFINITY       // Positive infinity (1.0 / 0.0)
FT_NEG_INFINITY   // Negative infinity (-1.0 / 0.0)
```

## API Reference

### Trigonometric Functions

```c
double ft_sin(double x);
```
Calculate sine of x (radians). Uses Taylor series expansion with angle normalization.

```c
double ft_cos(double x);
```
Calculate cosine of x (radians). Implemented using Taylor series.

```c
double ft_tan(double x);
```
Calculate tangent of x (radians). Returns sin(x)/cos(x) with special handling for singularities.

### Inverse Trigonometric Functions

```c
double ft_asin(double x);
```
Calculate arcsine of x. Domain: [-1, 1]. Returns value in [-π/2, π/2].

```c
double ft_acos(double x);
```
Calculate arccosine of x. Domain: [-1, 1]. Returns value in [0, π].

```c
double ft_atan(double x);
```
Calculate arctangent of x. Domain: all real numbers. Returns value in (-π/2, π/2).

### Exponential & Power Functions

```c
double ft_exp(double x);
```
Calculate e^x using Taylor series expansion.

```c
double ft_log(double x);
```
Calculate natural logarithm (ln(x)). Domain: x > 0.

```c
double ft_pow(double base, double exp);
```
Calculate base^exp. Handles special cases (negative bases, zero, infinity).

```c
double ft_sqrt(double x);
```
Calculate square root using Newton-Raphson method. Domain: x ≥ 0.

### Utility Functions

```c
double ft_fabs(double x);
```
Return absolute value of x.

```c
double ft_fmod(double x, double y);
```
Return floating-point remainder of x/y.

```c
double ft_ceil(double x);
```
Return smallest integer not less than x.

```c
double ft_normalize(double x);
```
Normalize angle x to range [0, 2π).

## Implementation Notes

### Epsilon Choice
The library uses `FT_EPSILON = 1e-15` (instead of the "true" machine epsilon ~2.22e-16) because:

1. **Accumulated rounding errors**: Series expansions accumulate errors over multiple terms
2. **Practical precision**: Double precision provides ~15-16 significant decimal digits
3. **No extended precision**: Without `long double`, forcing tighter tolerance is counterproductive
4. **Convergence balance**: More relaxed epsilon allows faster convergence without sacrificing useful accuracy

### Numerical Methods
- **Taylor series**: Used for sin, cos, exp
- **Newton-Raphson**: Used for sqrt
- **Range reduction**: Trigonometric functions normalize angles for better accuracy
- **Special case handling**: NaN, infinity, and edge cases properly handled

## Usage Example

```c
#include <ft_math.h>
#include <ft_maki.h>

int main(void) {
    // Trigonometry
    double angle = FT_M_PI / 4;  // 45 degrees
    ft_printf("cos(π/4) = %f\n", ft_cos(angle));
    ft_printf("tan(π/4) = %f\n", ft_tan(angle));
    ft_printf("sin(π/4) = %f\n", ft_sin(angle));
    
    // Exponential and logarithm
    double x = 2.0;
    ft_printf("e^2 = %f\n", ft_exp(x));
    ft_printf("ln(2) = %f\n", ft_log(x));
    ft_printf("2^10 = %f\n", ft_pow(2.0, 10.0));
    
    // Square root
    ft_printf("√2 = %f\n", ft_sqrt(2.0));
    
    // Inverse trig
    ft_printf("asin(0.5) = %f\n", ft_asin(0.5));
    ft_printf("acos(0.5) = %f\n", ft_acos(0.5));
    ft_printf("atan(1) = %f\n", ft_atan(1.0));  // Should be π/4
    
    // Utility functions
    ft_printf("|−3.14| = %f\n", ft_fabs(-3.14));
    ft_printf("ceil(3.14) = %f\n", ft_ceil(3.14));
    ft_printf("fmod(7.5, 2.0) = %f\n", ft_fmod(7.5, 2.0));
    
    return (0);
}
```
**Compile:**
```bash
clang hello.c -o hello -lft_maki -lft_math
./hello
```

## Accuracy & Performance

### Accuracy
- Trigonometric functions: ~15 decimal places
- Exponential/logarithm: ~14-15 decimal places
- Square root: Machine precision (Newton-Raphson converges quickly)

### Performance Considerations
- Functions use iterative methods (slower than hardware implementations)
- Suitable for educational purposes and environments without standard library
- Not optimized for high-performance computing

## Limitations

- **No hardware optimization**: Pure C implementation without SIMD or FPU instructions
- **Limited special functions**: Only basic mathematical functions included
- **No complex numbers**: Real numbers only
- **Series convergence**: Some edge cases may converge slowly

## Building

Include the header in your project:

```c
#include <ft_math.h>
```

This library is standalone and does not depend on `<math.h>`.

## Use Cases

Perfect for:
- Learning mathematical function implementation
- Embedded systems without standard library
- Academic projects
- Understanding numerical methods

Not recommended for:
- Production systems (use standard library instead)
- High-performance computing
- Real-time applications requiring speed

## License

MIT

---

**Note**: This is an educational implementation. For production use, prefer the standard `<math.h>` library which uses hardware-optimized implementations.