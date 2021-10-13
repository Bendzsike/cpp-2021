//
// Created by Benjamin on 2021. 10. 13..
//

#ifndef LAB4_POINTSET_H
#define LAB4_POINTSET_H

#include "Point.h"
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

class PointSet {
    vector<Point> points;
    int n;
    vector<double> distances;
    void computeDistances();

public:
    PointSet( int n = 100 );
    double maxDistance() const;
    double minDistance() const;
    int numDistances() const;
    void printPoints() const;
    void printDistances() const;
    void sortPointsX();
    void sortPointsY();
    void sortDistances();
    int numDistinctDistances();
};


#endif //LAB4_POINTSET_H
