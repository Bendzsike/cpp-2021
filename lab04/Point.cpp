#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < M) {
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

double Point::distanceTo(const Point& point) const {
    return sqrt(pow(point.getX() - this->getX(), 2) + pow(point.getY() - this->getY(), 2));
}
