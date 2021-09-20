#ifndef SQEQLIB_LIBRARY_H
#define SQEQLIB_LIBRARY_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <stdbool.h>

double sqrt_d(double x);
int SquareEquationSolver(double a, double b, double c, double* x1, double* x2);
void SquareEqAns(int status, double x1, double x2);

#endif //SQEQLIB_LIBRARY_H
