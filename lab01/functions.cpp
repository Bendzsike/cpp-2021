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
    for(char ch : str) {
        if((ch >= 'a' && ch < 'z') || (ch >= 'A' && ch < 'Z')) {
            result += (char)(ch + 1);
        } else if(ch == 'z' || ch == 'Z') {
            result += (char)(ch - 25);
        } else {
            result += ch;
        }
    }
    return result;
}

string capitalizeWords(const string& text) {
    string result;
    result += (char)toupper(text[0]);
    for(int i = 1; i < text.length(); ++i) {
        if (text[i - 1] == ' ') {
            result += (char) toupper(text[i]);
        } else {
            result += (char) tolower(text[i]);
        }
    }
    return result;
}

///EXTRA

void nMostCommonWords(const string& fileName, int n) {
    ifstream input(fileName);
    if(!input) {
        cout << "Couldn't open file!" << endl;
        return;
    }

    map<string, int> bible;
    string word;
    input >> word;
    while(!input.eof()) {
        for (int i = 0; i < word.size(); i++)
        {
            if (ispunct(word[i]))
            {
                word.erase(i--, 1);
            }
            word[i] = (char)tolower(word[i]);
        }
        auto it = bible.find(word);
        if(it == bible.end()) {
            bible[word] = 1;
        } else {
            bible[word] = bible[word] + 1;
        }
        input >> word;
    }
    input.close();
    bible.erase("");

    vector<pair<string, int>> backup;
    for(int i = 0; i < n; ++i) {
        pair<string, int> best("", 0);
        for(auto it = bible.begin(); it != bible.end(); ++it) {
            if(it->second > best.second) {
                best.first = it->first;
                best.second = it->second;
            }
        }
        cout << best.first << " - " << best.second << endl;
        backup.emplace_back(make_pair(best.first, best.second));
        bible[best.first] = 0;
    }
    for(int i = 0; i < n; ++i) {
        bible[backup[i].first] = backup[i].second;
    }
}