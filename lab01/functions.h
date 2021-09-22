//
// Created by Benjamin on 2021. 09. 22..
//

#ifndef CPP_2021_FUNCTIONS_H
#define CPP_2021_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <utility>
#include <limits>
#include <sstream>

using namespace std;

int countBits(int);

bool setBit(int&, int);

double mean(double[], int);

double stddev(double[], int);

pair<double, double> max2(double[], int);

int countWords(const string&);

string code(const string&);

#endif //CPP_2021_FUNCTIONS_H
