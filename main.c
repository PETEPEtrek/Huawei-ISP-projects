#include <stdio.h>
#include "library.h"
#include "Unittest.h"
enum constants {
    INF = 2147483647,
    ERCODE = -1,
    ORLEQ = 4,
    ONE = 1,
    TWO = 2,
    ZERO = 0
};

int main() {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;

    printf("This program can help you with solving a square equation\n");
    printf("Please, type three constituents of square equation :\n");

    Unittest();
    printf("Tests passed succsesful!\n");

    int num = scanf("%lf%lf%lf", &a, &b, &c);
    while (num != 3) {
        printf("ERROR : not enough arguments, try again\n");
        num = scanf("%lf%lf%lf", &a, &b, &c);
    }
    int answer = SquareEquationSolver(a, b, c, &x1, &x2);
    SquareEqAns(answer, x1, x2);
    return 0;
}
