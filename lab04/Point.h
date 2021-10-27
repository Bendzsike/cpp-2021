#ifndef LAB2_POINT_H
#define LAB2_POINT_H
#define M 2000

#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    int x;
    int y;
    static int counter;
public:
    Point(int x = 0, int y = 0);
    Point(const Point&);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point) const;
    ~Point();
    static int getCounter() {return counter;};
};

#endif //LAB2_POINT_H
