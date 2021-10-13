#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PointSet.h"

using namespace std;

int main() {
//    int x[100];
//    int n = 10;
//    cout<<"x = [";
//    for( int i=0; i<n; ++i ){
//        x[i] = rand() % 1000;
//        cout<<x[i]<<" ";
//    }
//    cout << "\b]" <<endl;
//    cout << "Legkisebb : " << *min_element(x, x+n) << endl;
//    vector<int> v;
//    v.reserve(100);
//    cout<<"v = [";
//    for( int i=0; i<n; ++i ){
//        v.emplace_back( rand() % 1000 );
//        cout<<v[ i]<<" ";
//    }
//    cout << "\b]" <<endl;
//    cout << "Legnagyobb: " << *max_element(v.begin(),v.end()) << endl;

    int n = 2;
//    PointSet ps(10);
//    ps.printPoints();
//    ps.sortPointsY();
//    ps.printPoints();
//    ps.sortDistances();
//    ps.printDistances();
//    cout << ps.numDistinctDistances() << endl;

    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ) {
        PointSet pSet(n);
        cout << setw(6) << n << " ";
        cout << setw(8) << setprecision(2) << pSet.minDistance() << " ";
        cout << setw(8) << setprecision(2) << pSet.maxDistance() << " ";
        cout << setw(10) << pSet.numDistances() << " ";
        cout << setw(16) << pSet.numDistinctDistances() << endl;
        n = n << 1;
    }


    return 0;
}
