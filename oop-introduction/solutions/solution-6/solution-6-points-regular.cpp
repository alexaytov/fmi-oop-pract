#include "Point3D.h"
#include "Point3DFunctions.h"

#include <iostream>

using namespace std;

int main() {

    Point3D p1(3, 4, 5), p2(45, 245, 235);
    cout << "Original:\n";
    PrintPoint3D(p1);
    PrintPoint3D(p2);
    cout << endl;

    p1.SetX(5);
    p1.SetY(2);

    p2.SetY(42534);
    p2.SetZ(3223);

    cout << "Modified:\n";
    PrintPoint3D(p1);
    PrintPoint3D(p2);

    return 0;
}