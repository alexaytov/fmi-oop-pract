#include "Point3D.h"

#include <iostream>

using namespace std;

void PrintPoint3D(const Point3D& p) {

    cout
        << "X: " << p.GetX()
        << ", Y: " << p.GetY()
        << ", Z: " << p.GetZ() << endl;
}

void PrintPoint3D(const Point3D* ptrPoint) {

    cout
        << "X: " << ptrPoint->GetX()
        << ", Y: " << ptrPoint->GetY()
        << ", Z: " << ptrPoint->GetZ() << endl;
}

bool AreLexic(const Point3D& p1, const Point3D& p2) {

    bool condition1 = p1.GetX() < p2.GetX();
    bool condition2 = p1.GetX() == p2.GetX() && p1.GetY() < p2.GetY();
    bool condition3 =
        p1.GetX() == p2.GetX()
        && p1.GetY() == p2.GetY()
        && p1.GetZ() < p2.GetZ();

    return condition1 || condition2 || condition3;
}

void SelectionSortLexicPoints3D(Point3D points[], size_t pointsSize) {

    for (size_t i = 0; i <= pointsSize - 2; i++)
    {
        size_t k = i;
        for (size_t j = i + 1; j <= pointsSize - 1; j++)
        {
            if (AreLexic(points[j], points[k])) k = j;
        }
        swap(points[i], points[k]);
    }
}