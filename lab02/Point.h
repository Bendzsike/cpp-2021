#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <iostream>
#include <cmath>
#include <iterator>
#include <set>

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void print() const;
};

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);

#endif //LAB2_POINT_H
