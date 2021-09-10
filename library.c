#include "library.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <float.h>

enum constants{INF = 2147483647 , ERCODE = -1};

/**
 * Gives a root of x
 * @param x - discriminant
 * @return root of x
 */
double sqrt_d(double x) {
    assert(x > 0 || fabs(x) < DBL_EPSILON);
    return sqrt(x);
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

int SquareEquationSolver(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (fabs(a) < DBL_EPSILON) {
        if (fabs(b) < DBL_EPSILON) {
            *x1 = NAN;
            *x2 = NAN;
            if (fabs(c) < DBL_EPSILON) {
                return INF;
            } else {
                return ERCODE;
            }
        } else {
            *x1 = -c / b;
            return 1;
        }
    } else {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            *x1 = NAN;
            *x2 = NAN;
            return 0;
        } else if (fabs(D) < DBL_EPSILON) {
            *x1 = -b / (2 * a);
            *x2 = NAN;
            return 1;
        } else {
            double sqrtd = sqrt_d(D);
            *x1 = (-b + sqrtd) / (2 * a);
            *x2 = (-b - sqrtd) / (2 * a);
            return 2;
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
 * @return Answer for square equation
 */
void SquareEqAns(int status, double x1, double x2) {
    if (status != INF) {
        printf("%d\n", status);
    }
    switch (status) {
        case 0 : printf("zero roots\n");
            break;
        case 1 : printf("one root : %lf\n", x1);
            break;
        case 2 : printf("two roots : %lf and %lf\n", x1, x2);
            break;
        case ERCODE : printf("ERROR : This equation can not be solved\n");
            break;
        default: printf("Infinite number of roots\n");
    }
}


