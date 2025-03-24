#include "functions.h"

int Addition( int a, int b ) {

    return a + b;
}

void Swap( int *a, int *b ) {

    // В случай, че някой от подадените аргументи е със
    // стойност 0, то функцията не прави нищо:
    if ( a == nullptr || b == nullptr ) return;

    // В противен случай, реализираме стандартния
    // алгоритъм за размяна на стойностите на две промнеливи:
    int temp = *a;
    *a = *b;
    *b = temp;
}

int CalculatePerimeter( int a, int b, int c ) {

    // Връщаме сума от кодовете на грешките в случай, че
    // поне един от аргументите е < 0:
    int sumOfCodes = ( a<0 ? -1:0 ) + ( b<0 ? -10:0 ) + ( c<0 ? -100:0 );
    if ( sumOfCodes < 0 ) return sumOfCodes;

    // Връщаме подходящия код, в случай, че правилото на
    // триъгълника не е изпълнено:
    bool isSatisfiedTriangleInequality =
        a + b > c && b + c > a && a + c > b;
    if (!isSatisfiedTriangleInequality) return -200;

    // В противен случай (на граничните) 
    // връщаме обиколката на триъгълника:
    return a + b + c;
}