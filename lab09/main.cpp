#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main() {
    cout << "############################# 1. exercise #############################\n" << endl;

    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };

    auto it = find_if(fruits.begin(), fruits.end(), [](const string& fruit) {
                                                                return fruit.find("berry") != string::npos;
                                                            });
    cout << "First fruit to contain \"berry\" is: " << *it << endl;

    cout << "\n############################# 2. exercise #############################\n" << endl;

    srand(time(nullptr));
    vector<int> numbers {
            10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    };

    if(all_of(numbers.begin(), numbers.end(), [](int num) {
                                                        return !(num % 2);
                                                    })) {
        cout << "All elements are even!" << endl;
    } else {
        cout << "There are odd numbers!" << endl;
    }

    cout << "\n############################# 3. exercise #############################\n" << endl;

    for_each(numbers.begin(), numbers.end(), [](int &num) {
                                                    num *= 2;
                                                });
    cout << "Doubled every element: ";
    for_each(numbers.begin(), numbers.end(), [](int num) {
                                                    cout << num << ", ";
                                                });
    cout << endl;

    cout << "\n############################# 4. exercise #############################\n" << endl;

    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int count = count_if(months.begin(), months.end(), [](const string &month) {
                                                                return month.size() == 5;
                                                            });

    cout << "There are " << count << " months which are 5 characters long." << endl;

    cout << "\n############################# 5. exercise #############################\n" << endl;

    vector<double> realNums {
            65.08, 88.59, 94.68, 72.97, 68.42, 73.68, 6.1, 2.7, 88.18, 6.27
    };

    vector<double> copyArr = realNums;

    sort(realNums.begin(), realNums.end(), [](double i, double j) {
                                                    return i > j;
                                                });

    cout << "Sorted with lambda: ";
    for_each(realNums.begin(), realNums.end(), [](double num) {
                                                    cout << num << ", ";
                                                });
    cout << endl;

    realNums = copyArr;

    sort(realNums.begin(), realNums.end(), greater<>());

    cout << "Sorted with \"greater<>\": ";
    for_each(realNums.begin(), realNums.end(), [](double num) {
                                                    cout << num << ", ";
                                                });
    cout << endl;

    cout << "\n############################# 6. exercise #############################\n" << endl;

    vector<pair<string, double>> monthsWithTemp {
            make_pair("January", -1), make_pair("February", 0.8), make_pair("March", 5.8), make_pair("April", 11.4), make_pair("May", 16.8), make_pair("June", 20.6),
            make_pair("July", 22.6), make_pair("August", 22.4), make_pair("September", 17.6), make_pair("October", 11.6), make_pair("November", 5.2), make_pair("December", 0.2)
    };

    sort(monthsWithTemp.begin(), monthsWithTemp.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
                                                                return a.second > b.second;
                                                            });

    cout << "Sorted: ";
    for_each(monthsWithTemp.begin(), monthsWithTemp.end(), [](const pair<string, double> &month) {
                                                                cout << "(" << month.first << ", " << month.second << "), ";
                                                            });
    cout << endl;

    cout << "\n############################# 7. exercise #############################\n" << endl;

    vector<double> realNumsAbs {
            16.08, -80.79, -79.04, 48.16, -51.84, -11.39, -21.98, -21.08, 21.50, 64.55
    };

    sort(realNumsAbs.begin(), realNumsAbs.end(), [](double i, double j) {
                                                            return abs(i) < abs(j);
                                                        });

    cout << "Sorted by absolute value: ";
    for_each(realNumsAbs.begin(), realNumsAbs.end(), [](double num) {
                                                            cout << num << ", ";
                                                        });
    cout << endl;

    cout << "\n############################# 8. exercise #############################\n" << endl;

    for_each(months.begin(), months.end(), [](string &month) {
                                                transform(month.begin(), month.end(), month.begin(), ::tolower);
    });

    cout << "Lowercased months: ";
    for_each(months.begin(), months.end(), [](const string& month) {
                                                cout << month << ", ";
                                            });
    cout << endl;

    cout << "\n############################# 9. exercise #############################\n" << endl;

    vector<char> abc {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    random_shuffle(abc.begin(), abc.end());

    cout << "Strange alphabet: ";
    for_each(abc.begin(), abc.end(), [](char a) {
                                            cout << a << ", ";
                                        });
    cout << endl;

    sort(months.begin(), months.end(), [abc](const string& a, const string& b) {
                                                return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [abc](char a, char b) {
                                                                                                                                    return (find(abc.begin(), abc.end(), toupper(a)) - abc.begin()) < (find(abc.begin(), abc.end(), toupper(b)) - abc.begin());
                                                                                                                                });
                                            });

    cout << "Sorted by the strange alphabet: ";
    for_each(months.begin(), months.end(), [](const string& month) {
                                                cout << month << ", ";
                                            });
    cout << endl;

    return 0;
}