#include <iostream>
#include "Point.h"

using namespace std;

int main() {
//    Point p1(2,3);
//    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
//    Point p2(100, 200);
//    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
//    Point * pp1 = new Point(300, 400);
//    Point * pp2 = new Point(500, 1000);
//    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
//    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
//    delete pp1;
//    delete pp2;

    cout << "6. assignment:" << endl;
    testIsSquare("points.txt");

    cout << "7. & 8. assignment:" << endl;
    int N;
    cout << "Enter the size of the array:";
    cin >> N;
    Point* points = createArray(N);
    cout << "The random elements in the array:" << endl;
    printArray(points, N);

    cout << "9. assignment:" << endl;

    pair<Point, Point> closest = closestPoints(points, N);
    cout << "Closest points in the array: ";
    closest.first.print();
    cout << " and ";
    closest.second.print();
    cout << endl;

    cout << "10. assignment:" << endl;
    pair<Point, Point> farthest = farthestPoints(points, N);
    cout << "Farthest points in the array: ";
    farthest.first.print();
    cout << " and ";
    farthest.second.print();
    cout << endl;

    cout << "11. assignment:" << endl;
    sortPoints(points, N);

    cout << "12. assignment:" << endl;
    Point* top = farthestPointsFromOrigin(points, N);
    printArray(top, 10);

    deletePoints(points);
    deletePoints(top);
    return 0;
}
