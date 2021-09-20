#include "library.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <stdbool.h>
enum constants {
    INF = 2147483647,
    ERCODE = -1,
    ORLEQ = 4,
    ONE = 1,
    TWO = 2,
    ZERO = 0
};
//write constant for each variant
/**
 * Check the number for equation to zero
 * @param [in] num - a double number
 * @return 1 if number equates zero or 0 otherwise
 */
bool is_zero(double num) {
    return fabs(num) < DBL_EPSILON;
}

/**
 * Gives a root of D
 * @param [in] D - discriminant
 * @return root of D
 */
double sqrt_d(double D) {
    assert(D > 0 || is_zero(D));
    return sqrt(D);
}

/**
 * Solves a square equation a * x^2 + b * x + c = 0
 *
 * @param [in] a - first coefficient
 * @param [in] b - second coefficient
 * @param [in] c - third coefficient
 * @param [out] x1 - Pointer to the first possible root
 * @param [out] x2 - Pointer to the second possible root
 *
 * @return - Number of roots or ErrorCode (-1)
 */

int SquareEquationSolver(const double a, const double b, const double c, double* x1, double* x2) {
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (is_zero(a)) {
        if (is_zero(b)) {
            *x1 = NAN;
            *x2 = NAN;
            if (is_zero(c)) {
                return INF;
            } else {
                return ERCODE;
            }
        } else {
            *x1 = -c / b;
            return ORLEQ;
        }
    } else {
        if (!is_zero(a) && !is_zero(b) && is_zero(c)) {
            *x1 = 0;
            *x2 = -b / a;
            return TWO;
        }
        double D = b * b - 4 * a * c;
        if (D < 0) {
            *x1 = NAN;
            *x2 = NAN;
            return ZERO;
        } else if (is_zero(D)) {
            *x1 = -b / (2 * a);
            *x2 = NAN;
            return ONE;
        } else {
            double sqrtd = sqrt_d(D);
            *x1 = (-b + sqrtd) / (2 * a);
            *x2 = (-b - sqrtd) / (2 * a);
            return TWO;
        }
    }
}

/**
 * Gives an answer depending on number of roots
 *
 * @param [in] status - Number of roots
 * @param [in] x1 - first possible root
 * @param [in] x2 - second possible root
 *
 * @note prints answer for square equation
 */
void SquareEqAns(int status, double x1, double x2) {
    if (status != INF && status != ORLEQ) {
        printf("%d\n", status);
    }
    switch (status) {
        case ZERO : printf("zero roots\n");
            break;
        case ONE : printf("one root : %lf\n", x1);
            break;
        case TWO : printf("two roots : %lf and %lf\n", x1, x2);
            break;
        case ORLEQ : printf("This is One-line linear equation and his only root : %lf\n", x1);
            break;
        case INF : printf("Infinite number of roots\n");
            break;
        default: printf("ERROR : This equation can not be solved\n");
    }
}


