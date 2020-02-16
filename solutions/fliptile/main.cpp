// http://poj.org/problem?id=3279

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int M, N;

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

string bitStr(int &arr, int digits = 0) {
    string s = "";
    int current = 1;
    int digit = 0;
    while ((digits == 0 && current <= arr) || digit < digits) {
        current *= 2;
        s = (get(arr, digit) ? "1" : "0") + s;
        digit++;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    vector<int> grid = vector<int>(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                set(grid[i], j);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        cout << bitStr(grid[i], N) << endl;
    }
    return 0;
}