#include "Point3D.h"
#include "Point3DFunctions.h"

#include <iostream>

using namespace std;


int main() {

    Point3D p1(3, 4, 5), p2(45, 245, 235);
    Point3D* ptrP1 = &p1, * ptrP2 = &p2;

    cout << "Original:\n";
    PrintPoint3D(ptrP1);
    PrintPoint3D(ptrP2);
    cout << endl;

    ptrP1->SetX(5);
    ptrP1->SetY(2);

    ptrP2->SetY(42534);
    ptrP2->SetZ(3223);

    cout << "Modified:\n";
    PrintPoint3D(ptrP1);
    PrintPoint3D(ptrP2);

    return 0;
}