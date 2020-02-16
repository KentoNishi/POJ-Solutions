// http://poj.org/problem?id=3279

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void set(int &arr, int bit) {
    arr = arr | (1 << bit);
}

void toggle(int &arr, int bit) {
    arr = arr ^ (1 << bit);
}

void clear(int &arr, int bit) {
    arr = arr & (~(1 << bit));
}

bool get(int &arr, int bit) {
    return (arr & (1 << bit)) ? 1 : 0;
}

string bitStr(int &arr) {
    string s = "";
    int current = 1;
    int digit = 0;
    while (current <= arr) {
        current *= 2;
        s = (get(arr, digit) ? "1" : "0") + s;
        digit++;
    }
    return s;
}

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int grid = 0;
    int test = 8;
    cout << get(test, 3) << endl;
    clear(test, 3);
    cout << get(test, 3) << endl;
    toggle(test, 3);
    cout << get(test, 3) << endl;
    cout << bitStr(test) << endl;
    return 0;
}