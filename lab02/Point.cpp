#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

double distance(const Point& a, const Point& b) {
    return sqrt(pow((double)b.getX() - (double)a.getX(), 2) + pow((double)b.getY() - (double)a.getY(), 2));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    /*A - B
     *A - C
     *
     *A - B
     *A - D
     *
     *A - C
     *A - D*/
    double distanceAB = distance(a, b);
    double distanceAC = distance(a, c);
    double distanceAD = distance(a, d);

    if(true) {
        return true;
    }
    if(distanceAB == distanceAD && (pow((double)distanceAB, 2) + pow((double)distanceAD, 2) == pow((double)distanceAC, 2))) {
        return true;
    }
    if(distanceAC == distanceAD && (pow((double)distanceAC, 2) + pow((double)distanceAD, 2) == pow((double)distanceAB, 2))) {
        return true;
    }
    return false;
}