#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <cstring>
#include "functions.h"

using namespace std;

int main(int argc, char * argv[]) {
//    int num;
//    cout << "Enter a positive number:";
//    cin >> num;
//    cout << "The number of bits in number '" << num << "' is: " << countBits(num) << endl;
//    for(int i = 0; i < 128; ++i) {
//        cout << "Num of bits in number '" << i << "' is: " << countBits(i) << endl;
//    }

//    for(int i = 0; i < 35; ++i) {
//        int n = 0;
//        if (setBit(n, i)) {
//            cout << i << " ---> " << n << endl;
//        } else {
//            cout << "Impossible operation!" << endl;
//        }
//    }

//    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//    cout << "Mean: " << mean(array, 5) << endl;
//    cout << "Stddev: " << stddev(array, 5) << endl;

//    pair<double, double> result = max2(array, 5);
//    cout << "Two max numbers: " << result.first << ", " << result.second << endl;

//    double sum = 0;
//    for(int i = 1; i < argc; ++i) {
//        istringstream iss(argv[i]);
//        double number;
//        while (iss >> number) {
//            sum += number;
//        }
//    }
//    cout << "Numeric sum from command line: " << sum << endl;

//    string str("Hello there General Kenobi");
//    cout << "String \"" << str << "\" has " << countWords(str) << " words." << endl;
//    string str("AbCdEfGhIjKzZ1234.,");
//    cout << "Coded message: " << code(str) << endl;

//    string line;
//    cout << "Enter your text:" << endl;
//    while(getline(cin, line) && !line.empty()) {
//        cout << capitalizeWords(line) << endl;
//    }

    nMostCommonWords(argv[1], atoi(argv[2]));
    return 0;
}
