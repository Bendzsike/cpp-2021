//
// Created by Benjamin on 2021. 10. 13..
//

#include "PointSet.h"

void PointSet::computeDistances() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}

bool occurMatrix[M][M];

void initOccurMatrix() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            occurMatrix[i][j] = false;
        }
    }
}


PointSet::PointSet(int n) {
    srand(time(nullptr));
    this->n = n;

    initOccurMatrix();

    while (points.size() < n) {
        int x = rand() % M;
        int y = rand() % M;
        if (!occurMatrix[x][y]) {
            points.emplace_back(Point(x, y));
            occurMatrix[x][y] = true;
        }
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for(auto point : points) {
        cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for(auto distance : distances) {
        cout << distance << ", ";
    }
    cout << endl;
}

bool compareX(const Point& first, const Point& second) {
    return first.getX() < second.getX();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), compareX);
}

bool compareY(const Point& first, const Point& second) {
    return first.getY() < second.getY();
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), compareY);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    return unique(distances.begin(), distances.end()) - distances.begin();
}
