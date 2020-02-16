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

bool get(int arr, int bit) {
    return (arr & (1 << bit)) ? 1 : 0;
}

string bitStr(int arr, int digits = 0) {
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

void printGrid(vector<int> &lines) {
    for (int i = 0; i < M; i++) {
        string s = bitStr(lines[i], N);
        for (int i = N - 1; i >= 0; i--) {
            cout << s[i];
            if (i > 0) {
                cout << " ";
            }
        }
        cout << endl;
    }
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
    vector<int> ans;
    int minFlips = M * N + 1;
    for (int firstLine = 0; firstLine < pow(2.0, N); firstLine++) {
        vector<int> lines = grid;
        vector<int> flips = vector<int>(M);
        int totalFlips = 0;
        flips[0] = firstLine;
        for (int j = 0; j < N; j++) {
            if (get(flips[0], j)) {
                totalFlips++;
                toggle(lines[0], j);
                toggle(lines[1], j);
                if (j > 0) {
                    toggle(lines[0], j - 1);
                }
                if (j < N - 1) {
                    toggle(lines[0], j + 1);
                }
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (get(lines[i - 1], j)) {
                    totalFlips++;
                    set(flips[i], j);
                    toggle(lines[i], j);
                    toggle(lines[i - 1], j);
                    if (i < M - 1) {
                        toggle(lines[i + 1], j);
                    }
                    if (j > 0) {
                        toggle(lines[i], j - 1);
                    }
                    if (j < N - 1) {
                        toggle(lines[i], j + 1);
                    }
                }
            }
        }
        if (lines[M - 1] == 0) {
            if (totalFlips < minFlips) {
                ans = flips;
                minFlips = totalFlips;
            }
        }
    }
    if (ans.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        printGrid(ans);
    }
    return 0;
}