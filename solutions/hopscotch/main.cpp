// http://poj.org/problem?id=3258

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L, M, N;

vector<int> rocks;

bool canDo(int minDist) {
    int removed = 0;
    int prev = 0;
    int index = 0;
    while (true) {
        while (index < M && removed <= N && rocks[index] - prev < minDist) {
            removed++;
            index++;
        }
        if (removed > N) {
            return false;
        }
        if (index == M) {
            return (L - prev >= minDist && removed <= N);
        }
        prev = rocks[index];
        index++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> M >> N;
    rocks = vector<int>(M);
    for (int i = 0; i < M; i++) {
        cin >> rocks[i];
    }
    sort(rocks.begin(), rocks.end());
    int lower = 1;
    int upper = L;
    while (upper - lower > 1) {
        int mid = (lower + upper) / 2;
        if (canDo(mid)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    cout << (canDo(upper) ? upper : lower) << endl;
    return 0;
}