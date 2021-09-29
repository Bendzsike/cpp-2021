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
    //I calculate every distance between each point, and put them in a set.
    //Every value in a set has to be unique.
    std::set<double> s;
    s.insert(distance(a, b));
    s.insert(distance(a, c));
    s.insert(distance(a, d));
    s.insert(distance(b, c));
    s.insert(distance(b, d));
    s.insert(distance(c, d));


    //There are only 2 types of distances in a square, so if set size is 2, then it's a square.
    if(s.size() == 2) {
        return true;
    }
    //Else, it's not.
    return false;
}