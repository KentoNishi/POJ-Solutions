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
}

int main() {
    cin >> N >> C;
    stalls.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());
    int lower = 0;
    int upper = N - 1;
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