//
// Created by Benjamin on 2021. 09. 22..
//

#include "functions.h"

int countBits(int num) {
    int count = 0;
    while(num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

bool setBit(int& num, int order) {
    if(order >= 0 && order <= 31) {
        num = (1 << order) | num;
        return true;
    }
    return false;
}

double mean(double array[], int length) {
    if(length == 0) {
        return NAN;
    }
    double sum = 0;
    for(int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum / length;
}

double stddev(double array[], int length) {
    if(length == 0) {
        return NAN;
    }
    double sum = 0;
    double arrayMean = mean(array, length);
    for(int i = 0; i < length; ++i) {
        sum += (array[i] - arrayMean) * (array[i] - arrayMean);
    }
    return sqrt(sum / length);
}

pair<double, double> max2(double array[], int length) {
    if(length == 0) {
        pair<double, double> result (NAN, NAN);
        return result;
    }
    if(length == 1) {
        pair<double, double> result (array[0], array[0]);
        return result;
    }
    double maxA = std::numeric_limits<double>::lowest();
    double maxB = std::numeric_limits<double>::lowest();
    for(int i = 0; i < length; ++i) {
        if(array[i] > maxA) {
            maxB = maxA;
            maxA = array[i];
        } else if(array[i] > maxB) {
            maxB = array[i];
        }
    }
    pair<double, double> result (maxB, maxA);
    return result;
}

int countWords(const string& str) {
    istringstream iss(str);
    string word;
    int count = 0;
    while(iss >> word) {
        ++count;
    }
    return count;
}

string code(const string& str) {
    string result;
    for(int i = 0; i < str.length(); ++i) {
        if((str[i] >= 'a' && str[i] < 'z') || (str[i] >= 'A' && str[i] < 'Z')) {
            result[i] = str[i] + 1;
        } else if(str[i] == 'z') {
            result[i] = 'a';
        } else if(str[i] == 'Z') {
            result[i] = 'A';
        }
    }
    return result;
}