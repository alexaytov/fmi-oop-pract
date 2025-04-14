#include "Point3D.h"
#include "Point3DFunctions.h"

#include <iostream>

using namespace std;

int main() {

    Point3D points[100];
    cout << "Number of points (2-100): ";
    int pointsSize;
    cin >> pointsSize;

    for (int i = 0; i < pointsSize; i++)
    {
        cout << "Coordinates(" << i << "): ";
        int x, y, z;
        cin >> x >> y >> z;
        points[i].SetX(x);
        points[i].SetY(y);
        points[i].SetZ(z);
    }
    cout << endl;

    // ??????? ????????? ?? ?? ????????? ???????????:
    //SelectionSortLexicPoints3D(points, pointsSize);

    for (int i = 0; i < pointsSize; i++) {

        cout
            << "Coordinates(" << i << ") = "
            << "(" << points[i].GetX() << ", "
            << points[i].GetY() << ", "
            << points[i].GetZ() << ")\n";
    }

    return 0;
}