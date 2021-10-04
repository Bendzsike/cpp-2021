#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <random>
#include <cmath>
#include <ctime>
#include <set>

using namespace std;

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
void testIsSquare(const char* fileName);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //LAB2_POINT_H
