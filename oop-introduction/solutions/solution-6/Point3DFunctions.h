#pragma once

#include "Point3D.h"

void PrintPoint3D(const Point3D& p);
void PrintPoint3D(const Point3D* ptrPoint);

bool AreLexic(const Point3D& p1, const Point3D& p2);

void SelectionSortLexicPoints3D(Point3D points[], size_t pointsSize);