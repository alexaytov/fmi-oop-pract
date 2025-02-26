#include <iostream>

#define DEBUG // Uncomment to enable debugging

inline int calculateArea(int width, int height) {
    return width * height;
}

int main() {
    int width = 5, height = 10;
    int area = calculateArea(width, height);

#ifdef DEBUG
    std::cout << "[DEBUG] Calculating area: " << width << " * " << height << " = " << area << std::endl;
#endif

    std::cout << "Rectangle Area: " << area << std::endl;
    return 0;
}