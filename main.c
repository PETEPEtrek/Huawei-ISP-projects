#include <stdio.h>
#include <assert.h>
#include <math.h>

#define eps 0.000000001
#define INF 2147483647
//---------------------------------------------------------------
//! Solves a square equation a * x^2 + b * x + c = 0
//!
//! @param [in] a - first coefficient
//! @param [in] b - second coefficient
//! @param [in] c - third coefficient
//! @param [out] x1 - Pointer to the first possible root
//! @param [out] x2 - Pointer to the second possible root
//!
//! @return - Number of roots
//---------------------------------------------------------------

int SquareEquationSolver(double a, double b, double c, double* x1, double* x2) {
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            *x1 = NAN;
            *x2 = NAN;
            if (fabs(c) < eps) {
                return INF;
            } else {
                return -1;
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
        } else if (fabs(D) < eps) {
            *x1 = -b / (2 * a);
            *x2 = NAN;
            return 1;
        } else {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return 2;
        }
    }
}
int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;

    printf("This program can help you with solving a square equation\n");
    printf("Please, type three constituents of square equation :\n");

    {
        a = 1;
        b = 2;
        c = 1;
        int ans = SquareEquationSolver(a, b, c, &x1, &x2);
        assert(ans == 1 && x1 == -1);
    }

    {
        a = 0;
        b = 0;
        c = 0;
        int ans = SquareEquationSolver(a, b, c, &x1, &x2);
        assert(ans == INF);
    }

    {
        a = 1;
        b = 1;
        c = 1;
        int ans = SquareEquationSolver(a, b, c, &x1, &x2);
        assert(ans == 0);
    }

    {
        a = 1;
        b = 3;
        c = 2;
        int ans = SquareEquationSolver(a, b, c, &x1, &x2);
        assert(ans == 2 && x1 == -1 && x2 == -2);
    }

    {
        a = 0;
        b = 0;
        c = 2;
        int ans = SquareEquationSolver(a, b, c, &x1, &x2);
        assert(ans == -1);
    }

    scanf("%lf%lf%lf", &a, &b, &c);

    int answer = SquareEquationSolver(a, b, c, &x1, &x2);
    printf("%d\n", answer);
    switch (answer) {
        case 0 : printf("zero roots\n");
            break;
        case 1 : printf("one root : %lf\n", x1);
            break;
        case 2 : printf("two roots : %lf and %lf\n", x1, x2);
            break;
        case -1 : printf("ERROR : This equation can not be solved\n");
            break;
        default: printf("Infinite number of roots\n");
    }
    return 0;
}
