#include "library.h"
#include <stdio.h>
enum constants {
    INF = 2147483647,
    ERCODE = -1,
    ORLEQ = 4,
    ONE = 1,
    TWO = 2,
    ZERO = 0
};
void Unittest() {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
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
        assert(ans == ERCODE);
    }
}
