#pragma once

class Point3D {

public:
    // Конструктор по подразбиране с параметри:
    Point3D(int = 0, int = 0, int = 0);
    // Член фунцкии за достъп до координатите на точка:
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    // Мутатори на координатите на точка:
    void SetX(int);
    void SetY(int);
    void SetZ(int);

private:
    // Съответно: абциса, ордината и апликата:
    int x, y, z;
};
