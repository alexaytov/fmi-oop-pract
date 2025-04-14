#include "Point3D.h"

Point3D::Point3D(int x, int y, int z) {

    SetX(x);
    SetY(y);
    SetZ(z);
}

int Point3D::GetX() const {

    return x;
}

int Point3D::GetY() const {

    return y;
}

int Point3D::GetZ() const {

    return z;
}

void Point3D::SetX(int x) {

    this->x = x;
}

void Point3D::SetY(int y) {

    this->y = y;
}

void Point3D::SetZ(int z) {

    this->z = z;
}