#include <iostream>
#include <cmath>

using namespace std;

struct Point2D {

    double X, Y;
};

double CalculateDistance(const Point2D& point1, const Point2D& point2) {

    double differenceSquaredX = pow(point1.X - point2.X, 2);
    double differenceSquaredY = pow(point1.Y - point2.Y, 2);

    return sqrt(differenceSquaredX + differenceSquaredY);
}

// Извикайте я в main(), за да я тествате:
void CalculateDistanceDemonstration() {

    Point2D
        p1 = { 1, 1 },
        p2 = { 1, 2 },
        p3 = { 3, 1 },
        p4 = { 4.3453, 1 },
        p5 = { 4.3453, 0.3454 };

    cout
        << CalculateDistance(p1, p2) << endl
        << CalculateDistance(p1, p3) << endl
        << CalculateDistance(p1, p4) << endl
        << CalculateDistance(p2, p5) << endl;
}

int main() {

    const int ArrayMaxSize = 100;

    Point2D points[ArrayMaxSize];
    cout << "Array size: ";
    int arraySize;
    cin >> arraySize;
    cout << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cout << "point[" << i << "] coordinates: ";
        cin >> points[i].X >> points[i].Y;
    }
    cout << endl;

    double currentMaxDistance = -1;
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            double currentDistance = CalculateDistance(points[i], points[j]);
            cout << "Distance(" << i << ", " << j << ") = " << currentDistance << endl;
            if (currentDistance > currentMaxDistance)
                currentMaxDistance = currentDistance;
        }
    }

    cout << "\nMax Distance: " << currentMaxDistance << endl;

    return 0;
}
