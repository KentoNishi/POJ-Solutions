// http://poj.org/problem?id=2456

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, C;
vector<int> stalls;

bool test(int num) {
    int prev = stalls[0];
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (stalls[i] - prev >= num) {
            count++;
            prev = stalls[i];
        }
        if (count >= C) {
            return true;
        }
    }
    return count >= C;
}

int main() {
    cin >> N >> C;
    stalls.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());
    int lower = 0;
    int upper = stalls[N - 1];
    while (lower < upper - 1) {
        int mid = (lower + upper) / 2;
        if (test(mid)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    if (test(upper)) {
        cout << upper << endl;
    } else {
        cout << lower << endl;
    }
    return 0;
}