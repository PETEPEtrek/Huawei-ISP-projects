#include <stdio.h>
#include "library.h"
#include <assert.h>

enum constants { INF = 2147483647, ERCODE = -1, ORLEQ = 4};

int main() {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;

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
        assert(ans == ERCODE);
    }

    int num = scanf("%lf%lf%lf", &a, &b, &c);
    while (num != 3) {
        printf("ERROR : not enough arguments, try again\n");
        num = scanf("%lf%lf%lf", &a, &b, &c);
    }
    int answer = SquareEquationSolver(a, b, c, &x1, &x2);
    SquareEqAns(answer, x1, x2);
    return 0;
}
