#include "functions.h"

int Addition( int a, int b ) {

    return a + b;
}

void Swap( int *a, int *b ) {

    if ( a == nullptr || b == nullptr ) return;

    int temp = *a;
    *a = *b;
    *b = temp;
}

int CalculatePerimeter( int a, int b, int c ) {

    int sumOfCodes = ( a<0 ? -1:0 ) + ( b<0 ? -10:0 ) + ( c<0 ? -100:0 );
    if ( sumOfCodes < 0 ) return sumOfCodes;

    bool isSatisfiedTriangleInequality =
        a + b > c && b + c > a && a + c > b;
    if (!isSatisfiedTriangleInequality) return -200;

    return a + b + c;
}