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
    cout << "(" << x << ", " << y << ")";
}

double distance(const Point &a, const Point &b) {
    return sqrt(pow((double) b.getX() - (double) a.getX(), 2) + pow((double) b.getY() - (double) a.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    //I calculate every distance between each point, and put them in a set.
    //Every value in a set has to be unique.
    set<double> s;
    s.insert(distance(a, b));
    s.insert(distance(a, c));
    s.insert(distance(a, d));
    s.insert(distance(b, c));
    s.insert(distance(b, d));
    s.insert(distance(c, d));


    //There are only 2 types of distances in a square, so if set size is 2, then it's a square.
    if (s.size() == 2) {
        return true;
    }
    //Else, it's not.
    return false;
}

void testIsSquare(const char *fileName) {
    ifstream input(fileName);
    if (!input) {
        cout << "Couldn't open file!" << endl;
        exit(1);
    }

    while (true) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (input.eof()) {
            break;
        }
        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Point d(x4, y4);
        cout << " a";
        a.print();
        cout << " b";
        b.print();
        cout << " c";
        c.print();
        cout << " d";
        d.print();
        cout << " " << (isSquare(a, b, c, d) ? "Yes" : "No") << endl;
    }
}

Point* createArray(int numPoints) {
    srand(time(nullptr));
    auto* points = new Point[numPoints];
    for(int i = 0; i < numPoints; ++i) {
        int x = rand() % 2001;
        int y = rand() % 2001;
        points[i] = Point(x, y);
    }
    return points;
}

void printArray(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
        cout << ", ";
    }
    cout << endl;
}

pair<Point, Point> closestPoints(Point* points, int numPoints) {
    pair<Point, Point> closest;
    double min = 999999999999999;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if(dist < min) {
                min = dist;
                closest = make_pair(points[i], points[j]);
            }
        }
    }
    return closest;
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    pair<Point, Point> farthest;
    double max = -1;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if(dist > max) {
                max = dist;
                farthest = make_pair(points[i], points[j]);
            }
        }
    }
    return farthest;
}

bool compare(Point a, Point b) {
    return (distance(a, Point(0, a.getY())) < distance(b, Point(0, b.getY())));
}

void sortPoints(Point* points, int numPoints) {
    sort(points, points + numPoints, compare);
    printArray(points, numPoints);
}

bool partialSortCompare(Point a, Point b) {
    return (distance(b, Point(0, 0)) < distance(a, Point(0, 0)));
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    Point* top = new Point[10];
    for(int i = 0; i < 10; ++i) {
        int maxIndex = i;
        double maxValue = distance(points[i], Point(0, 0));
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[j], Point(0, 0));
            if(dist > maxValue) {
                maxIndex = j;
                maxValue = dist;
            }
        }
        Point temp = points[maxIndex];
        points[maxIndex] = points[i];
        points[i] = temp;
        top[i] = points[i];
    }

//    partial_sort(points, points + 10, points + numPoints, partialSortCompare);
//    for(int i = 0; i < 10; ++i) {
//        top[i] = points[i];
//    }

    return top;
}

void deletePoints(Point* points) {
    delete [] points;
}
