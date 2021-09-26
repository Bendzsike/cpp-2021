#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <cstring>
#include "functions.h"

using namespace std;

int main(int argc, char * argv[]) {
    cout << "1. assignment" << endl;
    for(int i = 0; i < 128; ++i) {
        cout << "Num of bits in number '" << i << "' is: " << countBits(i) << endl;
    }
    cout << "2. assignment" << endl;
    for(int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }

    cout << "3. assignment" << endl;
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "The elements in the test array:" << endl;
    for(int i = 0; i < 5; ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
    cout << "Mean: " << mean(array, 5) << endl;

    cout << "4. assignment" << endl;
    cout << "Stddev: " << stddev(array, 5) << endl;

    cout << "5. assignment" << endl;
    pair<double, double> result = max2(array, 5);
    cout << "Two max numbers: " << result.first << ", " << result.second << endl;

    cout << "(Strings) 1. assignment" << endl;
    double sum = 0;
    for(int i = 3; i < argc; ++i) {
        istringstream iss(argv[i]);
        double number;
        while (iss >> number) {
            sum += number;
        }
    }
    cout << "Numeric sum from command line: " << sum << endl;

    cout << "(Strings) 2. assignment" << endl;
    string str("Hello there General Kenobi");
    cout << "String \"" << str << "\" has " << countWords(str) << " words." << endl;

    cout << "(Strings) 3. assignment" << endl;
    string str2("AbCdEfGhIjKzZ1234.,");
    cout << "Coded message: " << code(str2) << endl;

    cout << "(Strings) 4. assignment" << endl;
    string line;
    cout << "Enter your text:" << endl;
    while(getline(cin, line) && !line.empty()) {
        cout << capitalizeWords(line) << endl;
    }

    cout << "EXTRA:" << endl;
    nMostCommonWords(argv[1], atoi(argv[2]));
    return 0;
}
